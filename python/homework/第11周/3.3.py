import string
sentence = str(input("请输入带标点的英文句子:"))
translator = str.maketrans(string.punctuation,' '*len(string.punctuation))
new_sentence = sentence.translate(translator)
words = new_sentence.split()
print("该句子中含有单词",len(words),"个")