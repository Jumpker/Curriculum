while True:
    ID = str(input("请输入身份证号码:"))
    number = len(ID)
    if number == 18:
        print("您的出生日期是:",ID[6:10],"年",ID[10:12],"月",ID[12:14],"日")
        s = int(ID[-2])
        if s%2 == 0:
            sex = "女"
        else:
            sex = "男"
        print("您的性别是:",sex)
        break
    else:
        print("您输入的身份证号不合法! 请重新输入")