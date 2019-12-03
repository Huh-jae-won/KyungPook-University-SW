# 창을 만들어 input을 입력받게 한후
# 글자색과 배경색을 버튼으로 컨트롤 가능하도록 구현함
from tkinter import *
from tkinter.simpledialog import *

# func
def my_func():
    str = askstring("String", "문자를 입력하세요")
    txt3.configure(text=str)            # txt3의 text를 입력받은 문자로 변경

def func_exit():
    win.quit()
    win.destroy()

def my_bg():
    txt3.configure(bg=var_chk1.get())   # txt3의 배경색을 클릭된 radio_button색(var_chk1)으로 변경

def my_fg():
    txt3.configure(fg=var_chk2.get())   # txt3의 글자색을 클릭된 radio_button색(var_chk1)으로 변경

# main window
win = Tk()
win.title("String Viewer")              # window창의 제목

# create mainmenu
main_menu = Menu(win)
win.config(menu=main_menu)

# create sub menu
menu1 = Menu(main_menu)

# main-sub menu cascade
main_menu.add_cascade(label="File", menu=menu1)         # 주메뉴에 File이라고 버튼 추가

# add sub menu(open, exit)
menu1.add_command(label="Input String",command=my_func) # Input String 버튼 생성 -> 클릭시 my_func 실행
menu1.add_separator()                                   # 구분선 생성
menu1.add_command(labe="exit",command=func_exit)        # exit버튼 생성 -> 클릭시 func_exit 실행

txt1 = Label(win,text="<배경색>")
txt2 = Label(win,text="<글자색>")
txt1.grid(row=0,column=0)
txt2.grid(row=0,column=2)
str=""
txt3 = Label(win,width=20,height=2, text = str,bg="white")  # txt3의 크기와 글자, 배경색 지정
txt3.grid(row=5,columnspan=3)                               # txt3의 위치를 지정


# check
var_chk1 = StringVar()
# 배경색을 정해줄 radio_button 생성
rb1 = Radiobutton(win,text="blue",variable=var_chk1,value="blue",command=my_bg)
rb2 = Radiobutton(win,text="black",variable=var_chk1,value="black",command=my_bg)
rb3 = Radiobutton(win,text="yellow",variable=var_chk1,value="yellow",command=my_bg)

# 글자색을 정해줄 radio_button 생성
var_chk2 = StringVar()
rb4 = Radiobutton(win,text="white",variable=var_chk2,value="white",command=my_fg)
rb5 = Radiobutton(win,text="yellow",variable=var_chk2,value="yellow",command=my_fg)
rb6 = Radiobutton(win,text="red",variable=var_chk2,value="red",command=my_fg)

# radio_button들을 위치에 맞게 지정
rb1.grid(row=1,column=0)
rb2.grid(row=2,column=0)
rb3.grid(row=3,column=0)
rb4.grid(row=1,column=2)
rb5.grid(row=2,column=2)
rb6.grid(row=3,column=2)



win.mainloop()
