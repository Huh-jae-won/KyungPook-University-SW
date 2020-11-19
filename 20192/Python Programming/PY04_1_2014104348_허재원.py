
def get_minmax(*l):
    minimum=l[0]
    maximum=l[0]
    for i in range(1,len(l)):
        if maximum<l[i] :
            maximum = l[i]
        if minimum>l[i] :
            minimum = l[i]
    return [minimum,maximum]

def get_average(*l):
    s=0
    for i in l:
        s+=i
    return s/len(l)

        
    
while True:
    a = input("가격을 입력 : ").split(',')
    if '99999' in a:
        break
    a = list(map(float,a))
    print(a)
    result = get_minmax(*a)
    avg = get_average(*a)
    print("최저점수: %.2f, 최고점수: %.2f, 평균점수: %.2f"%(result[0],result[1],avg))
