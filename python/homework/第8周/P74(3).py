def fb(n):
    a,b = 1,1
    for i in range(n):
        if i:
            a,b = b,a+b
    return(b)
                                                        #定义函数:表示出斐波那契数列的每一项
def an(n):
    s = ((-1)**(n-1))*((n-1)/fb(n))
    return(s)
                                                        #定义函数:表示出题目所给的每一项数字
print("请输入一个正整数n:")
n = int(input())+1
if n <= 1:
    print("输入错误!请输入一个正整数")
else:
    sum = 1
    for i in range(1,n):
        if i:
            sum = sum + an(i)                           #求和, 得到答案
    print("计算其前n项和为:","{:.6f}".format(sum))