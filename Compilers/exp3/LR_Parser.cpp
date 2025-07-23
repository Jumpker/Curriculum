/**
 * LR语法分析器
 * 
 * 功能：针对给定文法规则，使用LR语法分析方法对输入符号串进行语法分析
 * 文法规则：
 * ①　E -> E+T
 * ②　E -> T
 * ③　T -> T*F
 * ④　T -> F
 * ⑤　F -> (E)
 * ⑥　F -> id
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

// 定义动作类型
enum ActionType {
    SHIFT,  // 移进
    REDUCE, // 归约
    ACCEPT, // 接受
    PARSE_ERROR   // 错误
};

// 定义动作结构
struct Action {
    ActionType type;
    int value; // 状态编号或产生式编号
    
    Action() : type(PARSE_ERROR), value(0) {}
    Action(ActionType t, int v) : type(t), value(v) {}
};

// 定义产生式结构
struct Production {
    char left;           // 产生式左部（非终结符）
    string right;        // 产生式右部
    int index;           // 产生式编号
    
    Production(char l, string r, int i) : left(l), right(r), index(i) {}
};

class LRParser {
private:
    // 文法规则
    vector<Production> productions;
    
    // 终结符和非终结符集合
    set<char> terminals;
    set<char> nonTerminals;
    
    // LR分析表
    map<int, map<char, Action>> actionTable;
    map<int, map<char, int>> gotoTable;
    
    // 分析栈
    stack<int> stateStack;
    stack<char> symbolStack;
    
    // 输入串和当前位置
    string inputString;
    int position;
    
    // 分析过程记录
    vector<vector<string>> analysisSteps;
    int stepCount;
    
    // 错误信息
    string errorMessage;
    bool hasError;

public:
    // 构造函数
    LRParser() {
        // 初始化文法规则
        initGrammar();
        
        // 构建LR分析表
        buildParseTable();
        
        // 初始化分析状态
        position = 0;
        stepCount = 0;
        hasError = false;
    }
    
    // 初始化文法规则
    void initGrammar() {
        // 添加产生式
        productions.push_back(Production('E', "E+T", 1));     // E -> E+T
        productions.push_back(Production('E', "T", 2));       // E -> T
        productions.push_back(Production('T', "T*F", 3));     // T -> T*F
        productions.push_back(Production('T', "F", 4));       // T -> F
        productions.push_back(Production('F', "(E)", 5));     // F -> (E)
        productions.push_back(Production('F', "i", 6));       // F -> id (使用i表示id)
        
        // 初始化终结符和非终结符集合
        terminals = {'+', '*', '(', ')', 'i', '#'};
        nonTerminals = {'E', 'T', 'F'};
    }
    
    // 构建LR分析表
    void buildParseTable() {
        // 构建ACTION表
        // 状态0
        actionTable[0]['i'] = Action(SHIFT, 5);   // 移进到状态5
        actionTable[0]['('] = Action(SHIFT, 4);   // 移进到状态4
        
        // 状态1
        actionTable[1]['+'] = Action(SHIFT, 6);   // 移进到状态6
        actionTable[1]['#'] = Action(ACCEPT, 0);  // 接受
        
        // 状态2
        actionTable[2]['+'] = Action(REDUCE, 2);  // 按产生式2归约
        actionTable[2]['*'] = Action(SHIFT, 7);   // 移进到状态7
        actionTable[2][')'] = Action(REDUCE, 2);  // 按产生式2归约
        actionTable[2]['#'] = Action(REDUCE, 2);  // 按产生式2归约
        
        // 状态3
        actionTable[3]['+'] = Action(REDUCE, 4);  // 按产生式4归约
        actionTable[3]['*'] = Action(REDUCE, 4);  // 按产生式4归约
        actionTable[3][')'] = Action(REDUCE, 4);  // 按产生式4归约
        actionTable[3]['#'] = Action(REDUCE, 4);  // 按产生式4归约
        
        // 状态4
        actionTable[4]['i'] = Action(SHIFT, 5);   // 移进到状态5
        actionTable[4]['('] = Action(SHIFT, 4);   // 移进到状态4
        
        // 状态5
        actionTable[5]['+'] = Action(REDUCE, 6);  // 按产生式6归约
        actionTable[5]['*'] = Action(REDUCE, 6);  // 按产生式6归约
        actionTable[5][')'] = Action(REDUCE, 6);  // 按产生式6归约
        actionTable[5]['#'] = Action(REDUCE, 6);  // 按产生式6归约
        
        // 状态6
        actionTable[6]['i'] = Action(SHIFT, 5);   // 移进到状态5
        actionTable[6]['('] = Action(SHIFT, 4);   // 移进到状态4
        
        // 状态7
        actionTable[7]['i'] = Action(SHIFT, 5);   // 移进到状态5
        actionTable[7]['('] = Action(SHIFT, 4);   // 移进到状态4
        
        // 状态8
        actionTable[8]['+'] = Action(SHIFT, 6);   // 移进到状态6
        actionTable[8][')'] = Action(SHIFT, 11);  // 移进到状态11
        
        // 状态9
        actionTable[9]['+'] = Action(REDUCE, 1);  // 按产生式1归约
        actionTable[9]['*'] = Action(SHIFT, 7);   // 移进到状态7
        actionTable[9][')'] = Action(REDUCE, 1);  // 按产生式1归约
        actionTable[9]['#'] = Action(REDUCE, 1);  // 按产生式1归约
        
        // 状态10
        actionTable[10]['+'] = Action(REDUCE, 3);  // 按产生式3归约
        actionTable[10]['*'] = Action(REDUCE, 3);  // 按产生式3归约
        actionTable[10][')'] = Action(REDUCE, 3);  // 按产生式3归约
        actionTable[10]['#'] = Action(REDUCE, 3);  // 按产生式3归约
        
        // 状态11
        actionTable[11]['+'] = Action(REDUCE, 5);  // 按产生式5归约
        actionTable[11]['*'] = Action(REDUCE, 5);  // 按产生式5归约
        actionTable[11][')'] = Action(REDUCE, 5);  // 按产生式5归约
        actionTable[11]['#'] = Action(REDUCE, 5);  // 按产生式5归约
        
        // 构建GOTO表
        gotoTable[0]['E'] = 1;
        gotoTable[0]['T'] = 2;
        gotoTable[0]['F'] = 3;
        
        gotoTable[4]['E'] = 8;
        gotoTable[4]['T'] = 2;
        gotoTable[4]['F'] = 3;
        
        gotoTable[6]['T'] = 9;
        gotoTable[6]['F'] = 3;
        
        gotoTable[7]['F'] = 10;
    }
    
    // 打印LR分析表
    void printParseTable() {
        cout << "LR分析表:" << endl;
        cout << "\nACTION表:" << endl;
        
        // 打印表头
        cout << setw(10) << "状态";
        for (char t : terminals) {
            cout << setw(10) << t;
        }
        cout << endl;
        
        // 打印分割线
        cout << string(10 + terminals.size() * 10, '-') << endl;
        
        // 打印表内容
        for (int i = 0; i <= 11; i++) {
            cout << setw(10) << i;
            
            for (char t : terminals) {
                if (actionTable.find(i) != actionTable.end() && 
                    actionTable[i].find(t) != actionTable[i].end()) {
                    
                    Action action = actionTable[i][t];
                    string actionStr;
                    
                    switch (action.type) {
                        case SHIFT:
                            actionStr = "s" + to_string(action.value);
                            break;
                        case REDUCE:
                            actionStr = "r" + to_string(action.value);
                            break;
                        case ACCEPT:
                            actionStr = "acc";
                            break;
                        case PARSE_ERROR:
                            actionStr = "";
                            break;
                    }
                    
                    cout << setw(10) << actionStr;
                } else {
                    cout << setw(10) << "";
                }
            }
            cout << endl;
        }
        
        cout << "\nGOTO表:" << endl;
        
        // 打印表头
        cout << setw(10) << "状态";
        for (char nt : nonTerminals) {
            cout << setw(10) << nt;
        }
        cout << endl;
        
        // 打印分割线
        cout << string(10 + nonTerminals.size() * 10, '-') << endl;
        
        // 打印表内容
        for (int i = 0; i <= 11; i++) {
            cout << setw(10) << i;
            
            for (char nt : nonTerminals) {
                if (gotoTable.find(i) != gotoTable.end() && 
                    gotoTable[i].find(nt) != gotoTable[i].end()) {
                    
                    cout << setw(10) << gotoTable[i][nt];
                } else {
                    cout << setw(10) << "";
                }
            }
            cout << endl;
        }
    }
    
    // 分析输入串
    bool parse(string input) {
        // 重置分析状态
        while (!stateStack.empty()) stateStack.pop();
        while (!symbolStack.empty()) symbolStack.pop();
        
        inputString = input + "#";
        position = 0;
        stepCount = 0;
        hasError = false;
        errorMessage = "";
        analysisSteps.clear();
        
        // 初始化分析栈
        stateStack.push(0);
        symbolStack.push('#');
        
        // 记录初始状态
        recordStep("初始化");
        
        // 开始分析
        while (true) {
            int currentState = stateStack.top();
            char currentInput = inputString[position];
            
            // 查找ACTION表
            if (actionTable.find(currentState) == actionTable.end() || 
                actionTable[currentState].find(currentInput) == actionTable[currentState].end()) {
                
                // 处理错误情况
                handleError(currentState, currentInput);
                return false;
            }
            
            Action action = actionTable[currentState][currentInput];
            
            // 根据动作类型执行相应操作
            switch (action.type) {
                case SHIFT: {
                    // 移进操作
                    stateStack.push(action.value);
                    symbolStack.push(currentInput);
                    position++;
                    
                    string actionStr = "移进到状态 " + to_string(action.value);
                    recordStep(actionStr);
                    break;
                }
                
                case REDUCE: {
                    // 归约操作
                    const Production& prod = productions[action.value - 1];
                    
                    // 弹出右部长度个符号和状态
                    for (size_t i = 0; i < prod.right.length(); i++) {
                        stateStack.pop();
                        symbolStack.pop();
                    }
                    
                    // 当前状态
                    int topState = stateStack.top();
                    
                    // 压入左部非终结符
                    symbolStack.push(prod.left);
                    
                    // 查找GOTO表
                    if (gotoTable.find(topState) == gotoTable.end() || 
                        gotoTable[topState].find(prod.left) == gotoTable[topState].end()) {
                        
                        setError("语法错误：无法找到GOTO表项 [" + to_string(topState) + ", " + 
                                 string(1, prod.left) + "]");
                        return false;
                    }
                    
                    // 压入新状态
                    int newState = gotoTable[topState][prod.left];
                    stateStack.push(newState);
                    
                    string actionStr = "按产生式 " + to_string(prod.index) + ": " + 
                                      prod.left + " -> " + prod.right + " 归约";
                    recordStep(actionStr);
                    break;
                }
                
                case ACCEPT: {
                    // 接受操作
                    recordStep("接受");
                    return true;
                }
                
                case PARSE_ERROR: {
                    // 错误操作
                    handleError(currentState, currentInput);
                    return false;
                }
            }
        }
        
        return false;
    }
    
    // 处理错误
    void handleError(int state, char input) {
        string expectedSymbols = "";
        bool first = true;
        
        // 查找期望的输入符号
        for (char t : terminals) {
            if (actionTable.find(state) != actionTable.end() && 
                actionTable[state].find(t) != actionTable[state].end()) {
                
                if (!first) expectedSymbols += ", ";
                expectedSymbols += string(1, t);
                first = false;
            }
        }
        
        // 根据不同错误类型设置错误信息
        if (input == '#' && position < inputString.length() - 1) {
            setError("语法错误：输入串未处理完，但分析已结束");
        } else if (expectedSymbols.empty()) {
            setError("语法错误：在状态 " + to_string(state) + " 无法处理输入符号 '" + 
                     string(1, input) + "'");
        } else {
            setError("语法错误：在状态 " + to_string(state) + " 处，无法处理输入符号 '" + 
                     string(1, input) + "'。期望的符号: " + expectedSymbols);
        }
        
        // 尝试错误恢复（简单跳过当前输入符号）
        if (position < inputString.length() - 1) {
            position++;
            recordStep("错误恢复：跳过符号 '" + string(1, input) + "'");
        }
    }
    
    // 记录分析步骤
    void recordStep(string action) {
        vector<string> step;
        
        // 步骤编号
        step.push_back(to_string(stepCount++));
        
        // 状态栈内容
        string stateContent = "";
        stack<int> tempStateStack = stateStack;
        vector<int> stateVec;
        
        while (!tempStateStack.empty()) {
            stateVec.push_back(tempStateStack.top());
            tempStateStack.pop();
        }
        
        for (int i = stateVec.size() - 1; i >= 0; i--) {
            stateContent += to_string(stateVec[i]) + " ";
        }
        step.push_back(stateContent);
        
        // 符号栈内容
        string symbolContent = "";
        stack<char> tempSymbolStack = symbolStack;
        vector<char> symbolVec;
        
        while (!tempSymbolStack.empty()) {
            symbolVec.push_back(tempSymbolStack.top());
            tempSymbolStack.pop();
        }
        
        for (int i = symbolVec.size() - 1; i >= 0; i--) {
            symbolContent += symbolVec[i];
        }
        step.push_back(symbolContent);
        
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
        errorStep.push_back("");
        errorStep.push_back("错误: " + message);
        analysisSteps.push_back(errorStep);
    }
    
    // 打印分析过程
    void printAnalysisProcess() {
        cout << "\n分析过程:" << endl;
        cout << setw(5) << "步骤" << setw(20) << "状态栈" << setw(20) << "符号栈" 
             << setw(20) << "剩余输入串" << setw(40) << "动作" << endl;
        cout << string(105, '-') << endl;
        
        for (const vector<string>& step : analysisSteps) {
            cout << setw(5) << step[0] << setw(20) << step[1] << setw(20) << step[2] 
                 << setw(20) << step[3] << setw(40) << step[4] << endl;
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
    
    // 创建LR分析器
    LRParser parser;
    
    // 打印LR分析表
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