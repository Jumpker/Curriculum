def Fibonacci(n):
    if n == 1:
        return 0
    elif n==2:
        return 1
    return(Fibonacci(n-1)+Fibonacci(n-2))
                                                #斐波那契数列函数, 作业2.2用
def prime(n):
    if n <= 1:
        return "输入错误!请输入大于1的正整数"
    elif n == 2:
        return 2
    else:
        prime = []
        for i in range(2,n):
            browns = []
            for a in range(2,i):
                if i % a == 0:
                    brown = False
                    browns.append(brown)
                else:
                    brown = True
                    browns.append(brown)
            if all(browns):
                prime.append(i)
        return prime
                                                 #查找0到n之间的质数(不包括n), 作业2.3用
def tangle(n,char):
    for i in range(1,n):
        print(" "*(n-i),char*(2*i-1))
    return ""
                                                #打印三角形函数
def square(a,b,c):
    p = (a+b+c)/2
    n = (p*(p-a)*(p-b)*(p-c))**0.5
    return n
                                                #计算三角形面积函数