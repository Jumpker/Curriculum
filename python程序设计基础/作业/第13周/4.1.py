def test(n):
    if n == "aaa":
        return 123456
    elif n == "bbb":
        return 888888
    elif n == "ccc":
        return 333333
    else:
        return False

print("欢迎使用登录系统")
name = str(input("请输入您的账号:"))
password = int(input("请输入您的密码:"))
if test(name) == False:
    print("Wrong User")
elif test(name) == password:
    print("Success")
elif test(name) != password:
    print("Fail")