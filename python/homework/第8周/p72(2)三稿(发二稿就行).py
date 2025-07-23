for i in range(100,1000):
    num = i
    num1 = num % 10
    num2 = ((num - num1)/10) % 10
    num3 = num//100
    if num1 ** 3 + num2 ** 3 +num3 ** 3 == num:
        print(i)
    else:
        print(i,"不是水仙花数")