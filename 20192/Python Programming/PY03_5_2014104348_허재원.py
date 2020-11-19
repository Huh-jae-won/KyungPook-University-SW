a = []

while True :
    number = int(input('입력할 수 : '))
    if number == 0 :
        break
    a.append(number)

print('입력된 리스트 : ',a)

for i in range(1,len(a)):
    print('%d단계 : '%i,end='')
    tmp = a[i]
    for j in range(i-1,-1,-1):
        if tmp<a[j] :
            a[j+1]=a[j]
            if(j==0):
                a[j]=tmp
        else :
            a[j+1]=tmp
            break
    print(a)
