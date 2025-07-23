/**
 * LL(1)语法分析器
 * 
 * 功能：针对给定文法规则，使用LL(1)语法分析方法对输入符号串进行语法分析
 * 文法规则：
 * ①　E -> TG        
 * ②　G -> +TG | -TG 
 * ③　G -> ε        
 * ④　T -> FS        
 * ⑤　S -> *FS | /FS 
 * ⑥　S -> ε        
 * ⑦　F -> (E) 
 * ⑧　F -> i 
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <windows.h> // 用于设置控制台输出编码

using namespace std;

// 定义文法规则的结构
struct Production {
    char left;           // 产生式左部（非终结符）
    string right;        // 产生式右部
    int index;           // 产生式编号
    
    Production(char l, string r, int i) : left(l), right(r), index(i) {}
};

class LL1Parser {
private:
    // 文法规则
    vector<Production> productions;
    
    // 终结符和非终结符集合
    set<char> terminals;
    set<char> nonTerminals;
    
    // FIRST集和FOLLOW集
    map<char, set<char>> firstSet;
    map<char, set<char>> followSet;
    
    // LL(1)分析表
    map<pair<char, char>, int> parseTable;
    
    // 分析栈和输入串
    stack<char> analysisStack;
    string inputString;
    int position;  // 当前分析位置
    
    // 分析过程记录
    vector<vector<string>> analysisSteps;
    int stepCount;
    
    // 错误信息
    string errorMessage;
    bool hasError;

public:
    // 构造函数
    LL1Parser() {
        // 初始化文法规则
        initGrammar();
        
        // 计算FIRST集和FOLLOW集
        computeFirstSet();
        computeFollowSet();
        
        // 构建LL(1)分析表
        buildParseTable();
        
        // 初始化分析状态
        position = 0;
        stepCount = 0;
        hasError = false;
    }
    
    // 初始化文法规则
    void initGrammar() {
        // 添加产生式
        productions.push_back(Production('E', "TG", 1));       // E -> TG
        productions.push_back(Production('G', "+TG", 2));      // G -> +TG
        productions.push_back(Production('G', "-TG", 3));      // G -> -TG
        productions.push_back(Production('G', "$", 4));       // G -> ε
        productions.push_back(Production('T', "FS", 5));       // T -> FS
        productions.push_back(Production('S', "*FS", 6));      // S -> *FS
        productions.push_back(Production('S', "/FS", 7));      // S -> /FS
        productions.push_back(Production('S', "$", 8));       // S -> ε
        productions.push_back(Production('F', "(E)", 9));      // F -> (E)
        productions.push_back(Production('F', "i", 10));       // F -> i
        
        // 初始化终结符和非终结符集合
        terminals = {'+', '-', '*', '/', '(', ')', 'i', '#', '$'}; // 添加$作为ε的替代
        nonTerminals = {'E', 'T', 'G', 'F', 'S'};
    }
    
    // 计算FIRST集
    void computeFirstSet() {
        // 初始化FIRST集
        for (char nt : nonTerminals) {
            firstSet[nt] = set<char>();
        }
        
        bool changed = true;
        while (changed) {
            changed = false;
            
            // 遍历所有产生式
            for (const Production& prod : productions) {
                char X = prod.left;
                string Y = prod.right;
                
                // 如果产生式右部为空（ε），则将$加入FIRST(X)
                if (Y == "$") {
                    if (firstSet[X].find('$') == firstSet[X].end()) {
                        firstSet[X].insert('$');
                        changed = true;
                    }
                    continue;
                }
                
                // 计算FIRST(Y1Y2...Yn)
                bool allDeriveEmpty = true;
                for (size_t i = 0; i < Y.length(); i++) {
                    char Yi = Y[i];
                    
                    // 如果Yi是终结符
                    if (terminals.find(Yi) != terminals.end()) {
                        if (firstSet[X].find(Yi) == firstSet[X].end()) {
                            firstSet[X].insert(Yi);
                            changed = true;
                        }
                        allDeriveEmpty = false;
                        break;
                    }
                    
                    // 如果Yi是非终结符
                    if (nonTerminals.find(Yi) != nonTerminals.end()) {
                        bool hasEmpty = false;
                        
                        // 将FIRST(Yi) - {$}加入FIRST(X)
                        for (char symbol : firstSet[Yi]) {
                            if (symbol != '$') {
                                if (firstSet[X].find(symbol) == firstSet[X].end()) {
                                    firstSet[X].insert(symbol);
                                    changed = true;
                                }
                            } else {
                                hasEmpty = true;
                            }
                        }
                        
                        // 如果FIRST(Yi)不包含$，则停止
                        if (!hasEmpty) {
                            allDeriveEmpty = false;
                            break;
                        }
                        
                        // 如果是最后一个符号且能推导出$
                        if (i == Y.length() - 1 && hasEmpty) {
                            if (firstSet[X].find('$') == firstSet[X].end()) {
                                firstSet[X].insert('$');
                                changed = true;
                            }
                        }
                    }
                }
                
                // 如果Y1, Y2, ..., Yn都能推导出$，则将$加入FIRST(X)
                if (allDeriveEmpty && Y.length() > 0) {
                    if (firstSet[X].find('$') == firstSet[X].end()) {
                        firstSet[X].insert('$');
                        changed = true;
                    }
                }
            }
        }
    }
    
    // 计算FOLLOW集
    void computeFollowSet() {
        // 初始化FOLLOW集
        for (char nt : nonTerminals) {
            followSet[nt] = set<char>();
        }
        
        // 将#加入FOLLOW(S)，其中S是开始符号
        followSet['E'].insert('#');
        
        bool changed = true;
        while (changed) {
            changed = false;
            
            // 遍历所有产生式
            for (const Production& prod : productions) {
                char A = prod.left;
                string beta = prod.right;
                
                // 遍历产生式右部的每个符号
                for (size_t i = 0; i < beta.length(); i++) {
                    char B = beta[i];
                    
                    // 如果B是非终结符
                    if (nonTerminals.find(B) != nonTerminals.end()) {
                        // 计算FIRST(beta_{i+1}...beta_n)
                        set<char> firstBeta;
                        bool hasEmpty = true;
                        
                        // 如果B是产生式右部的最后一个符号
                        if (i == beta.length() - 1) {
                            // 将FOLLOW(A)加入FOLLOW(B)
                            for (char symbol : followSet[A]) {
                                if (followSet[B].find(symbol) == followSet[B].end()) {
                                    followSet[B].insert(symbol);
                                    changed = true;
                                }
                            }
                        } else {
                            // 计算FIRST(beta_{i+1})
                            char nextSymbol = beta[i+1];
                            
                            // 如果nextSymbol是终结符
                            if (terminals.find(nextSymbol) != terminals.end()) {
                                firstBeta.insert(nextSymbol);
                                hasEmpty = false;
                            } else {
                                // 如果nextSymbol是非终结符
                                for (char symbol : firstSet[nextSymbol]) {
                                    if (symbol != '$') {
                                        firstBeta.insert(symbol);
                                    }
                                }
                                
                                // 检查nextSymbol是否能推导出$
                                hasEmpty = (firstSet[nextSymbol].find('$') != firstSet[nextSymbol].end());
                            }
                            
                            // 将FIRST(beta_{i+1}) - {$}加入FOLLOW(B)
                            for (char symbol : firstBeta) {
                                if (followSet[B].find(symbol) == followSet[B].end()) {
                                    followSet[B].insert(symbol);
                                    changed = true;
                                }
                            }
                            
                            // 如果FIRST(beta_{i+1})包含$，则将FOLLOW(A)加入FOLLOW(B)
                            if (hasEmpty) {
                                for (char symbol : followSet[A]) {
                                    if (followSet[B].find(symbol) == followSet[B].end()) {
                                        followSet[B].insert(symbol);
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // 构建LL(1)分析表
    void buildParseTable() {
        // 遍历所有产生式
        for (const Production& prod : productions) {
            char A = prod.left;
            string alpha = prod.right;
            int prodIndex = prod.index;
            
            // 计算FIRST(alpha)
            set<char> firstAlpha;
            bool hasEmpty = false;
            
            // 如果alpha为$
            if (alpha == "$") {
                hasEmpty = true;
            } else {
                char firstChar = alpha[0];
                
                // 如果firstChar是终结符
                if (terminals.find(firstChar) != terminals.end()) {
                    firstAlpha.insert(firstChar);
                } else {
                    // 如果firstChar是非终结符
                    for (char symbol : firstSet[firstChar]) {
                        if (symbol != '$') {
                            firstAlpha.insert(symbol);
                        } else {
                            hasEmpty = true;
                        }
                    }
                }
            }
            
            // 对于FIRST(alpha)中的每个终结符a
            for (char a : firstAlpha) {
                parseTable[{A, a}] = prodIndex;
            }
            
            // 如果alpha能推导出$，则对于FOLLOW(A)中的每个终结符b
            if (hasEmpty || alpha == "$") {
                for (char b : followSet[A]) {
                    parseTable[{A, b}] = prodIndex;
                }
            }
        }
    }
    
    // 获取FIRST集
    set<char> getFirstSet(char symbol) {
        return firstSet[symbol];
    }
    
    // 获取FOLLOW集
    set<char> getFollowSet(char symbol) {
        return followSet[symbol];
    }
    
    // 打印FIRST集和FOLLOW集
    void printSets() {
        cout << "FIRST集:" << endl;
        for (char nt : nonTerminals) {
            cout << "FIRST(" << nt << ") = { ";
            bool first = true;
            for (char symbol : firstSet[nt]) {
                if (!first) cout << ", ";
                if (symbol == '$') cout << "ε";
                else cout << symbol;
                first = false;
            }
            cout << " }" << endl;
        }
        
        cout << "\nFOLLOW集:" << endl;
        for (char nt : nonTerminals) {
            cout << "FOLLOW(" << nt << ") = { ";
            bool first = true;
            for (char symbol : followSet[nt]) {
                if (!first) cout << ", ";
                cout << symbol;
                first = false;
            }
            cout << " }" << endl;
        }
    }
    
    // 打印LL(1)分析表
    void printParseTable() {
        cout << "\nLL(1)分析表:" << endl;
        
        // 打印表头
        cout << setw(10) << " ";
        for (char t : terminals) {
            if (t != 'ε') {
                cout << setw(10) << t;
            }
        }
        cout << endl;
        
        // 打印分割线
        cout << string(10 + terminals.size() * 10, '-') << endl;
        
        // 打印表内容
        for (char nt : nonTerminals) {
            cout << setw(10) << nt << "|";
            
            for (char t : terminals) {
                if (t != 'ε') {
                    if (parseTable.find({nt, t}) != parseTable.end()) {
                        int prodIndex = parseTable[{nt, t}];
                        cout << setw(9) << prodIndex;
                    } else {
                        cout << setw(9) << " ";
                    }
                }
            }
            cout << endl;
        }
    }
    
    // 分析输入串
    bool parse(string input) {
        // 重置分析状态
        while (!analysisStack.empty()) {
            analysisStack.pop();
        }
        inputString = input + "#";
        position = 0;
        stepCount = 0;
        hasError = false;
        errorMessage = "";
        analysisSteps.clear();
        
        // 初始化分析栈
        analysisStack.push('#');
        analysisStack.push('E');
        
        // 记录初始状态
        recordStep("初始化");
        
        // 开始分析
        while (!analysisStack.empty()) {
            char X = analysisStack.top();
            char a = inputString[position];
            
            // 如果栈顶是终结符
            if (terminals.find(X) != terminals.end()) {
                if (X == a) {
                    // 匹配成功，弹出栈顶元素，输入指针前移
                    analysisStack.pop();
                    position++;
                    recordStep("匹配 '" + string(1, X) + "'");
                } else if (X == '$') {
                    // 匹配$，只弹出栈顶元素
                    analysisStack.pop();
                    recordStep("跳过 ε");
                } else {
                    // 匹配失败，报错
                    setError("语法错误：期望 '" + string(1, X) + "'，但得到 '" + string(1, a) + "'");
                    return false;
                }
            }
            // 如果栈顶是非终结符
            else if (nonTerminals.find(X) != nonTerminals.end()) {
                // 查找分析表
                if (parseTable.find({X, a}) != parseTable.end()) {
                    int prodIndex = parseTable[{X, a}];
                    const Production& prod = productions[prodIndex - 1];
                    
                    // 弹出栈顶元素
                    analysisStack.pop();
                    
                    // 将产生式右部逆序压入栈中
                    if (prod.right != "ε") {
                        for (int i = prod.right.length() - 1; i >= 0; i--) {
                            analysisStack.push(prod.right[i]);
                        }
                    }
                    
                    // 记录使用的产生式
                    string action = "使用产生式 " + to_string(prodIndex) + ": " + prod.left + " -> " + prod.right;
                    recordStep(action);
                } else {
                    // 分析表中没有对应项，报错
                    string expected = "";
                    bool first = true;
                    
                    // 查找期望的输入符号
                    for (char t : terminals) {
                        if (parseTable.find({X, t}) != parseTable.end()) {
                            if (!first) expected += ", ";
                            expected += string(1, t);
                            first = false;
                        }
                    }
                    
                    setError("语法错误：在非终结符 '" + string(1, X) + "' 处，无法处理输入符号 '" + string(1, a) + "'。期望的符号: " + expected);
                    return false;
                }
            } else {
                // 栈顶既不是终结符也不是非终结符，报错
                setError("内部错误：栈顶符号 '" + string(1, X) + "' 既不是终结符也不是非终结符");
                return false;
            }
            
            // 如果分析栈为空但输入串未处理完，报错
            if (analysisStack.empty() && position < inputString.length() - 1) {
                setError("语法错误：输入串未处理完，但分析栈已为空");
                return false;
            }
        }
        
        return true;
    }
    
    // 记录分析步骤
    void recordStep(string action) {
        vector<string> step;
        
        // 步骤编号
        step.push_back(to_string(stepCount++));
        
        // 分析栈内容
        string stackContent = "";
        stack<char> tempStack = analysisStack;
        vector<char> stackChars;
        
        while (!tempStack.empty()) {
            stackChars.push_back(tempStack.top());
            tempStack.pop();
        }
        
        for (int i = stackChars.size() - 1; i >= 0; i--) {
            stackContent += stackChars[i];
        }
        step.push_back(stackContent);
        
        // 剩余输入串
        string remainingInput = inputString.substr(position);
        step.push_back(remainingInput);
        
        // 动作
        step.push_back(action);
        
        // 添加到分析步骤列表
        analysisSteps.push_back(step);
    }
    
    // 设置错误信息
    void setError(string message) {
        hasError = true;
        errorMessage = message;
        
        // 记录错误步骤
        vector<string> errorStep;
        errorStep.push_back(to_string(stepCount++));
        errorStep.push_back("");
        errorStep.push_back("");
        errorStep.push_back("错误: " + message);
        analysisSteps.push_back(errorStep);
    }
    
    // 打印分析过程
    void printAnalysisProcess() {
        cout << "\n分析过程:" << endl;
        cout << setw(5) << "步骤" << setw(20) << "分析栈" << setw(20) << "剩余输入串" << setw(40) << "动作" << endl;
        cout << string(85, '-') << endl;
        
        for (const vector<string>& step : analysisSteps) {
            cout << setw(5) << step[0] << setw(20) << step[1] << setw(20) << step[2] << setw(40) << step[3] << endl;
        }
        
        if (hasError) {
            cout << "\n分析结果: 失败" << endl;
            cout << "错误信息: " << errorMessage << endl;
        } else {
            cout << "\n分析结果: 成功" << endl;
        }
    }
};

int main() {
    // 设置控制台输出为UTF-8编码
    SetConsoleOutputCP(65001);
    
    // 创建LL(1)分析器
    LL1Parser parser;
    
    // 打印FIRST集和FOLLOW集
    parser.printSets();
    
    // 打印LL(1)分析表
    parser.printParseTable();
    
    // 循环分析用户输入的符号串
    string input;
    char choice;
    
    do {
        cout << "\n请输入要分析的符号串 (使用i表示标识符): ";
        cin >> input;
        
        // 分析输入串
        bool success = parser.parse(input);
        
        // 打印分析过程
        parser.printAnalysisProcess();
        
        cout << "\n是否继续分析? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}