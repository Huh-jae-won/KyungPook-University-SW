import calculator
import time
in_file = None
out_file = open('cal.log','w')
while True :
    in_put = ''
    tmp = ''
    user = []
    in_put = input("숫자를 입력하시오")
    if in_put.find('txt')>0:
        in_file = open(in_put,'r')
        tmp = in_file.readline().strip('\n')
        out_file.write('[' + time.asctime() + '] 파일열기 : ')
        out_file.write(in_put)
        out_file.write('\n')
    elif in_put == 'exit':
        if in_file != None:
            in_file.close()
        out_file.write('['+time.asctime()+'] ')
        out_file.write('프로그램 종료\n')
        break
    elif in_put.isalpha():
        print("숫자나 연산자를 입력해 주세요")
    else :
        out_file.write('[' + time.asctime() + '] 계산식 : ')
        out_file.write(in_put)
        out_file.write('\n')
        for i in range(len(in_put)):
            if in_put[i] != ' ':
                tmp += in_put[i]
    a = 0
    b = 0
    # user리스트에 input을 담음
    for i in range(len(tmp)):
        if tmp[i]=='+' or tmp[i]=='-' or tmp[i]=='*' or tmp[i]=='/':
            b=i
            user.append(tmp[a:b])
            user.append(tmp[i:i+1])
            a=i+1
    user.append(tmp[a:len(tmp)])
    # user리스트의 문자열을 숫자로
    for i in range(len(user)):
        if user[i]!='+' and user[i]!='-' and user[i]!='*' and user[i]!='/':
            user[i] = float(user[i])

    while len(user) !=1:
        for i in range(len(user)) :
            if user[i]=='*' or user[i]=='/':
                if user[i]=='*':
                    user[i] = calculator.multiply(user[i-1],user[i+1])
                    del(user[i+1])
                    del(user[i-1])
                    break
                else :
                    user[i] = calculator.divide(user[i - 1],user[i + 1])
                    del (user[i+1])
                    del (user[i-1])
                    break
        for i in range(len(user)):
            if user[i]=='+' or user[i]=='-':
                if user[i]=='+':
                    user[i] = calculator.plus(user[i-1],user[i+1])
                    del(user[i+1])
                    del(user[i-1])
                    break
                else :
                    user[i] = calculator.minus(user[i - 1],user[i + 1])
                    del (user[i+1])
                    del (user[i-1])
                    break
    if user[0]%1 != 0 :
        if user[0]*100-int(user[0]*100)>0.5:
            user[0] = float((int(user[0]*100)+1)/100)
        else :
            user[0] = float((int(user[0]*100))/100)
        print("%.2f"%user[0])
    else :
        print("%d"%user[0])
    out_file.write('[' + time.asctime() + '] 결과 : ')
    out_file.write(str(user[0]))
    out_file.write('\n')
out_file.close()