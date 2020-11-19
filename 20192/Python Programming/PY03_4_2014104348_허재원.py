a = input("가격을 입력 : ").split(';')

for i,val in enumerate(a):
    a[i] = int(val)


a.sort(reverse = True)
for i in a:
    print("%9s"%format(i,',d'))
      
