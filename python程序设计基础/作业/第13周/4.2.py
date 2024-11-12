with open('6.5 hebei.txt','r',encoding='utf-8') as file:
    district_ls = [x.split(',') for x in file]
name = str(input("请输入名称:"))
for cities in district_ls:
    if cities[0] == name:
        print(cities)
    for county in cities:
        if county == name:
            print(cities[0])