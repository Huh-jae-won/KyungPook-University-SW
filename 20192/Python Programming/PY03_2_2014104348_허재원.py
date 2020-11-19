a=['alpha','beta','gamma','delta','epsilon','zeta']
l=[]
length = int(input("문자열길이 : "))

for i,j in enumerate(a):
    if len(j) == length:
        l.append(j)

print(l)
