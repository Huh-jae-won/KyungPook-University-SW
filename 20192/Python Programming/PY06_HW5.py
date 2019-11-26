# HW4에서 주소록을 만들었는데 해당 주소록을 address.txt로 저장하고
# 읽어와 검색하는 프로그램 작성
# 검색시 로그를 write함
import os
import time
import random

class Person:
    def __init__(self, name, phone_num):
        self.name = name
        self.phone_num = phone_num

    def get_name(self):
        return self.name

    def get_phone(self):
        return self.phone_num


class Student(Person):
    def __init__(self, name, phone_num, major, std_num):
        super().__init__(name, phone_num)
        self.major = major
        self.std_num = std_num

    def get_major(self):
        return self.major

    def get_stdNum(self):
        return self.std_num


class Worker(Person):
    def __init__(self, name, phone_num, depart, work_num):
        super().__init__(name, phone_num)
        self.depart = depart
        self.work_num = work_num

    def get_depart(self):
        return self.depart

    def get_workNum(self):
        return self.work_num


def make_phoneNum():
    num = '010-'
    mid = random.randint(1000, 9999)
    end = random.randint(1000, 9999)
    num += (str(mid) + '-' + str(end))
    return num


def make_stdwrkNum(type):
    if type == 0:  # 학생
        num = '201' + str(random.randint(1000000, 9999999))
        return num
    else:
        num = '2019' + str(random.randint(100, 999))
        return num


## main ##
addrList=[]
file_name = input("파일이름을 입력 : ")
in_file = open(file_name,'r')
out_file = open('address.log','w')                  # address.log에 write할 예정

if os.path.exists(file_name):                       # 파일이 read했다면 log 기록
    out_file.write('[' + time.asctime() + '] ')
    out_file.write('open file address.txt\n')
    while True :
        tmp = in_file.readline()
        addrList.append(tmp.strip('\n'))            # 해당줄의 개행을 지운 후 addrList에 추가
        if(tmp == '') :
            break
    out_file.write('[' + time.asctime() + '] ')
    out_file.write('total 10 people\n')             # 10명을 모두 read해왔다면 log 기록
else:
    print("error %s가 존재하지 않습니다"%file_name)
in_file.close()
print(addrList)

while True:
    name = input("찾을사람 이름은?")
    out_file.write('[' + time.asctime() + '] ')     # log 기록
    out_file.write('search '+name+'\n')
    if name == "끝":                                 # 끝을 입력하면 종료
        out_file.write('[' + time.asctime() + '] ')  # log 기록
        out_file.write('exit\n')
        out_file.close()
        print("종료합니다")
        break

    for addr in addrList:
        if addr.find(name)>0:
            if addr.find('학생')>0:
                print(" 전화번호 : %s" %addr[addr.find("전화")+6:addr.find("전화")+19])
                print(" 학과 : %s" %addr[addr.find("학과")+4:addr.find("학과")+9].strip())
                print(" 학번 : %s" %addr[addr.find("학번")+4:addr.find("학번")+15])
            elif addr.find('사원')>0:
                print(" 전화번호 : %s" %addr[addr.find("전화")+6:addr.find("전화")+19])
                print(" 부서 : %s" %addr[addr.find("부서")+4:addr.find("부서")+9].strip())
                print(" 사번 : %s" %addr[addr.find("사번")+4:addr.find("사번")+11].strip())
