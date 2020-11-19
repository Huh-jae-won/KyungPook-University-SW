import random

class Person:
    def __init__(self,name,num,type):
        self.name = name
        self.num = num
        self.type = type

    def get_name(self):
        return self.name
    def get_num(self):
        return self.num
    def get_type(self):
        return self.type

class Student(Person) :
    def __init__(self,major,std_num):
        #super().__init__(name, num, type)
        self.major = major
        self.std_num = std_num

    def get_major(self):
        return self.major
    def get_stdNum(self):
        return self.std_num

class Worker(Person):
    def __init__(self,depart,work_num):
        #super().__init__(name,num,type)
        self.depart = depart
        self.work_num = work_num

    def get_depart(self):
        return self.depart
    def get_work_num(self):
        return self.work_num


## main
nameList = ['홍동현', '서상욱', '도찬호', '이대희', '최기태', '김동호', '김준식', '이영석', '김승주', '김종범']
majorList = ['컴퓨터학부','경영학부','통계학과','기계공학부']
departList = ['개발연구팀','전략기획팀','인사관리팀']
tmpList = []
personList = []
for i in range(10):
    person = Person(nameList[i], '010-'+str(random.randint(1000,9999))+"-"+str(random.randint(1000,9999)), random.randint(0,1) )
    tmpList.append(person)



for person in tmpList:
    if person.get_type() == 0:
        std = Student(majorList[random.randint(0,3)],"201"+str(random.randint(1000000,9999999)))
        std.name = person.get_name()
        std.num = person.get_num()
        std.type = person.get_type()
        personList.append(std)

    else :
        worker = Worker(departList[random.randint(0,2)],"2019"+str(random.randint(100,999)))
        worker.name = person.get_name()
        worker.num = person.get_num()
        worker.type = person.get_type()
        personList.append(worker)

print("----------주소록 프로그램----------")
for person in personList:
    if(person.get_type()==0):
        print("[학생] 이름:%-7s 전화번호: %s 학과: %s\t학번: %s"%(person.get_name(),person.get_num(),person.get_major(),person.get_stdNum()))
    else :
        print("[사원] 이름:%-7s 전화번호: %s 부서: %s\t사번: %s"%(person.get_name(),person.get_num(),person.get_depart(),person.get_work_num()))
print("----------------------------------")

while True:
    name = input("찾을사람 이름은?")
    if(name == "끝"):
        print("주소록 프로그램을 종료합니다")
        break
    for i in range(10):
        if personList[i].get_name() == name:
            if personList[i].get_type() == 0 :
                print(" 전화번호 : %s" %personList[i].get_num())
                print(" 학   과 : %s"%personList[i].get_major())
                print(" 학   번 : %s"%personList[i].get_stdNum())

            else :
                print(" 전화번호 : %s" %personList[i].get_num())
                print(" 부   서 : %s"%personList[i].get_depart())
                print(" 사   번 : %s"%personList[i].get_work_num())