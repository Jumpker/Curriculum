import re

# 定义保留字、运算符、界符集合
RESERVED_WORDS = {'if', 'int', 'for', 'while', 'do', 'return', 'break', 'continue'}
OPERATORS = {'+', '-', '*', '/', '=', '>', '<', '>=', '<=', '!='}
DELIMITERS = {',', ';', '{', '}', '(', ')'}

def lex_analyzer(source_code):
    tokens = []
    i = 0
    n = len(source_code)
    
    while i < n:
        # 跳过空格和换行符
        if source_code[i].isspace():
            i += 1
            continue
        
        # 处理标识符/保留字（字母开头，后接字母、数字、下划线）
        if source_code[i].isalpha() or source_code[i] == '_':
            j = i
            while j < n and (source_code[j].isalnum() or source_code[j] == '_'):
                j += 1
            token = source_code[i:j]
            if token in RESERVED_WORDS:
                tokens.append((1, token))  # 保留字种别码1
            else:
                tokens.append((2, token))  # 标识符种别码2
            i = j
            continue
        
        # 处理无符号整数（纯数字）
        if source_code[i].isdigit():
            j = i
            while j < n and source_code[j].isdigit():
                j += 1
            token = source_code[i:j]
            tokens.append((3, token))  # 无符号整数种别码3
            i = j
            continue
        
        # 处理运算符（含多字符运算符）
        if source_code[i] in ['<', '>', '=', '!']:
            if i+1 < n and source_code[i] + source_code[i+1] in OPERATORS:
                token = source_code[i:i+2]
                tokens.append((4, token))  # 运算符种别码4
                i += 2
                continue
        if source_code[i] in OPERATORS:
            tokens.append((4, source_code[i]))  # 单字符运算符
            i += 1
            continue
        
        # 处理界符
        if source_code[i] in DELIMITERS:
            tokens.append((5, source_code[i]))  # 界符种别码5
            i += 1
            continue
        
        # 未识别字符（示例中暂不处理错误）
        i += 1
    
    return tokens

# 测试代码
if __name__ == "__main__":
    # 从同目录下的example.txt读取源代码
    with open('exp1\example.txt', 'r', encoding='utf-8') as f:
        source_code = f.read()
    # 去除多余空白并拼接成连续字符串（保留原始空格用于分析）
    source_code = re.sub(r'\n\s+', '\n', source_code).strip()
    tokens = lex_analyzer(source_code)
    
    # 输出结果（格式与示例一致）
    for idx, (type_code, value) in enumerate(tokens, 1):
        print(f"({type_code}，\"{value}\")")