n = int(input("0~99사이 숫자 입력 : "))

while n<=0 or n>99 :
    n = int(input("0~99사이 숫자 입력 : "))
    break
count = 0
tmp = 0
m=n
while True :
    tmp = m//10 + m%10
    tmp=str(m%10)+str(tmp%10)
    count +=1
    print("%2d번째 숫자 : %d"%(count,int(tmp)))
    if int(n) == int(tmp) :
        break
    m=int(tmp)
print("최종 연산 횟수 : %2d번"%count)
