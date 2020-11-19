import os
import time

in_file = None
in_list = []
in_str = ""
out_file = open("address.log","w")

if(os.path.exists("address.txt")):
    in_file = open("address.txt","r")

    while True :
        in_str = in_file.readline()
        in_list.append(in_str)
        if (in_str == ""):
            break
    out_file.write("[" + time.asctime() + "] " + "open file address.txt")
    out_file.write("\n")
else :
    print("error : address.txt 파일이 없습니다")
    out_file.write("[" + time.asctime() + "] " + "cannot open file address.txt")
    out_file.write("\n")

in_file.close()

out_file.write("[" + time.asctime() + "] " + "total 10 people")
out_file.write("\n")

while True :
    set = 0
    name = input("\n찾을 사람은? ")
    if(name == "exit"):
        out_file.write("[" + time.asctime() + "] " + "exit")
        out_file.write("\n")
        break
    for i in in_list:
        if(i.find(name) != -1):
            set = 1
            print(i[14:33].strip())
            print(i[33:43].strip())
            print(i[43:-1].strip())
            out_file.write("[" + time.asctime() + "] " + "search "+name)
            out_file.write("\n")
            break
    if set != 1:
        print("%s은(는) 주소록에 없습니다" % name)
        out_file.write("[" + time.asctime() + "] " + "search " + name)
        out_file.write("\n")
        set=0

out_file.close()