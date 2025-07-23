words = list(input("请输入非空字符串:"))
unique_words = []
for n in words:
    if n not in unique_words:
        unique_words.append(n)
unique_words.sort()
print(''.join(unique_words))