tmp=[]
list_1=[]
for i in range(0,3):
    for j in range(1,5):
        tmp.append(i*4+j)
    list_1.append(tmp)
    tmp=[]

for i,j in enumerate(list_1):
    print("list_1(%d): "%i, j)

print("----------------------------------------------")
list_2 = list_1
print("list_2: ",list_2)
print("----------------------------------------------")
for i in range(0,3):
    for j in range(0,4):
        print("list_2[%d][%d] : %-2d "%(i,j,list_2[i][j]),end=' ')
    print() 
