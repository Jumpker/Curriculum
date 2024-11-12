print("请输入乘车里程(整数)(km):")
s = int(input())
print("请输入等待时间(整数)(min):")
t = int(input())
money = 0
if s <= 3:
    money = t + 13
elif 3 < s <= 15:
    money = t + 13 + (s-3)*2.3
else:
    money = t + 13 + 12*2.3 + (s-15)*(2.3*1.5)
print("您本次乘车的车费是:",money)