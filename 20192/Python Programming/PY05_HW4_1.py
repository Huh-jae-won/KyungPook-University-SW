# 많은 자료들을 랜덤하지만 알맞게 주소록을 생성하는 프로그램
# 생성자와 상속을 적절히 사용해야함

import random
class Person : 
    # 사람 클래스는 이름과 폰번호로 초기화한다
    def __init__(self,name,phone_num):
        self.name = name
        self.phone_num = phone_num

    def get_name(self):
        return self.name

    def get_phone(self):
        return self.phone_num

class Student(Person):
    # 학생 클래스는 사람 클래스를 상속하며, 이름,폰번호,학과,학번으로 초기화한다
    def __init__(self,name,phone_num,major,std_num): 
        super().__init__(name,phone_num)    # 이름과 폰번호는 상위 클래스의 값으로 초기화한다
        self.major = major
        self.std_num = std_num

    def get_major(self):
        return self.major
    def get_stdNum(self):
        return self.std_num

class Worker(Person):
    # 회사원 클래스는 사람 클래스를 상속하며, 이름,폰번호,부서,사번으로 초기화 한다
    def __init__(self,name, phone_num, depart, work_num):
        super().__init__(name, phone_num)   # 이름과 폰번호는 상위 클래스의 값으로 초기화한다
        self.depart = depart
        self.work_num = work_num

    def get_depart(self):
        return self.depart
    def get_workNum(self):
        return self.work_num

# 메소드
def make_phoneNum():
    # 폰번호를 만드는 메소드
    num='010-'
    mid = random.randint(1000,9999)
    end = random.randint(1000,9999)
    num += (str(mid)+'-'+str(end))
    return num

def make_stdwrkNum(type):
    # 학번 또는 사번을 만드는 메소드
    # type에 따라 학번, 사번을 생성함
    if type == 0: #학생
        num = '201'+str(random.randint(1000000,9999999))
        return num
    else :
        num = '2019'+str(random.randint(100,999))
        return num

## main ##
nameList = ["홍동현","서상욱",'도찬호','이대희','최기태','김동호','김준식','이영석','김승주','김종범']
majorList = ['컴퓨터학부', '경영학부  ', '통계학과  ', '기계공학부']
departList = ["개발연구팀",'전략기획팀','인사관리팀']
addrList=[]
for i in range(10):
    tmp = []
    type = random.randint(0,1)  # 랜덤하게 학생 또는 회사원을 정한다
    if type == 0 :              # 학생을 뜻하며, 이름을 제외한 폰번호,학과,학번은 랜덤하게 생성하여 tmp배열에 추가한다
        tmp.append("학생")
        tmp.append(nameList[i])
        tmp.append(make_phoneNum())
        tmp.append(majorList[random.randint(0,3)])
        tmp.append(make_stdwrkNum(type))
    else :                      # 회사원을 뜻하며, 이름을 제외한 폰번호,부서,사번은 랜덤하게 생성하여 tmp배열에 추가한다
        tmp.append("사원")
        tmp.append(nameList[i])
        tmp.append(make_phoneNum())
        tmp.append(departList[random.randint(0, 2)])
        tmp.append(make_stdwrkNum(type))
    addrList.append(tmp)        # tmp배열의 값을 addrList에 추가한다

# 10명의 사람이 addrList에 존재한다.
# 10명의 사람을 출력하는 for 문
for i in addrList:
    if i[0] == '학생':
        print("[%s] 이름: %s 전화번호: %s 학과: %s 학번: %s"%(i[0],i[1],i[2],i[3],i[4]))
    else :
        print("[%s] 이름: %s 전화번호: %s 부서: %s 사번: %s"%(i[0],i[1],i[2],i[3],i[4]))

# 이름을 입력하면 해당사람의 정보를 출력하는 프로그램
while True:
    name = input("찾을사람 이름은?")
    if name == "끝":
        print("종료합니다")
        break

    for i in addrList:
        if i[1] == name:
            if i[0] =='학생' :
                print(" 전화번호 : %s"%i[2])
                print(" 학과 : %s"%i[3])
                print(" 학번 : %s"%i[4])
            else :
                print(" 전화번호 : %s" % i[2])
                print(" 부서 : %s" % i[3])
                print(" 사번 : %s" % i[4])
