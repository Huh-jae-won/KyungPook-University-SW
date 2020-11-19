import random
import time

def makeRandom():
    while True:
        r = random.randint(100,999)
        tmp = str(r)
        if tmp[0]!=tmp[1] and tmp[0]!=tmp[2] and tmp[1]!=tmp[2]:
            r = tmp
            return r
            break
    

t1 = time.time()
print("게임을 시작합니다");
random = str(makeRandom());
print("정답 : ",random)
cnt = 0
while True :
    strike = 0
    ball = 0
    user = str(input("숫자를 입력하세요"))
    cnt+=1
    for i in range(3):
        if random[i] == user[i]:
            strike+=1
        for j in range(3):
            if i!=j and random[i]==user[j]:
                ball+=1
    print("[STRIKE] %d\t[BALL] %d"%(strike,ball))
    if(strike==3):
        break
t2 = time.time()
print("게임을 %d회에서 이겼습니다"%cnt)
print("게임 시간은 %d 초입니다"%(t2-t1))

        
    



