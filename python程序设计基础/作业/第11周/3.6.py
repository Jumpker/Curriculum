password = str(input("请输入你的密码:"))
if len(password) < 8:
    print("您的密码强度为: 弱")
else:
    if len(set(password)) == 2:
        print("您的密码强度为: 中等")
    elif len(set(password)) == 3:
        print("您的密码强度为: 强")
    elif len(set(password)) == 4:
        print("您的密码强度为: 极强")
    else:
        print("别问,我也不知道你密码强度怎么样,题目没说")