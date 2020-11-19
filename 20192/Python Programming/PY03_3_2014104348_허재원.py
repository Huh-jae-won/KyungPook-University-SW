
while True:
    ss = input("문자열 입력 : ")
    if ss == 'exit' :
        break
    print("대소문자 변환 결과 : ",end='')
    for i in range(0,len(ss)):
        if 'a'<=ss[i]<='z' :
            print("%c"%ss.upper()[i],end='')
        else :
            print("%c"%ss.lower()[i],end='')
    print()
