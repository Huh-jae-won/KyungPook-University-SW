money = int(input("금액을 입력하시오 : "))
c500 = money//500
money %= 500
c100 = money//100
money %= 100
c50 = money//50
money %= 50
c10 = money//10
money %= 10
print("500원동전 : %2d개"%c500)
print("100원동전 : %2d개"%c100)
print("50원동전  : %2d개"%c50)
print("10원동전  : %2d개"%c10)
print("남은 금액 : %2d원"%money)
