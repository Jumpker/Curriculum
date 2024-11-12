def test(n):
    if n == "aaa":
        return "123456"
    elif n == "bbb":
        return "888888"
    elif n == "ccc":
        return "333333"
    else:
        return False

print("欢迎使用登录系统"'\n')
name = input("请输入账号:")
if test(name) == False:
    print("Wrong User")
else:
    print("接下来请输入密码,您共有三次机会")
    for n in range(3,0,-1):
        password = input("请输入密码,您有"+str(n)+"次机会:")
        if password == test(name):
            print("Success")
            break
        else:
            print("Fail")
            if n == 1:
                print("Login Denied")