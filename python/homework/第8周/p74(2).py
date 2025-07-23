for i in range(100,1000):
    num = i
    sum = 0
    while num:
        num1 = num % 10
        num2 = ((num - num1)/10) % 10
        num3 = num//100
        sum = num1 ** 3 + num2 ** 3 +num3 ** 3
        if sum == i:
            print(i)
            break
        else:
            break