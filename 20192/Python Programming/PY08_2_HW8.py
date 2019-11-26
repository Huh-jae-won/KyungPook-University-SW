from tkinter import *
from tkinter.simpledialog import *

# func
def my_func():
    str = askstring("String", "문자를 입력하세요")
    txt3.configure(text=str)

def func_exit():
    win.quit()
    win.destroy()

def my_bg():
    txt3.configure(bg=var_chk1.get())

def my_fg():
    txt3.configure(fg=var_chk2.get())

# main window
win = Tk()
win.title("String Viewer")

# create mainmenu
main_menu = Menu(win)
win.config(menu=main_menu)

# create sub menu
menu1 = Menu(main_menu)

# main-sub menu cascade
main_menu.add_cascade(label="File", menu=menu1)

# add sub menu(open, exit)
menu1.add_command(label="Input String",command=my_func)
menu1.add_separator()
menu1.add_command(labe="exit",command=func_exit)

txt1 = Label(win,text="<배경색>")
txt2 = Label(win,text="<글자색>")
txt1.grid(row=0,column=0)
txt2.grid(row=0,column=2)
str=""
txt3 = Label(win,width=20,height=2, text = str,bg="white")
txt3.grid(row=5,columnspan=3)


# check
var_chk1 = StringVar()
# radio button
rb1 = Radiobutton(win,text="blue",variable=var_chk1,value="blue",command=my_bg)
rb2 = Radiobutton(win,text="black",variable=var_chk1,value="black",command=my_bg)
rb3 = Radiobutton(win,text="yellow",variable=var_chk1,value="yellow",command=my_bg)

var_chk2 = StringVar()
rb4 = Radiobutton(win,text="white",variable=var_chk2,value="white",command=my_fg)
rb5 = Radiobutton(win,text="yellow",variable=var_chk2,value="yellow",command=my_fg)
rb6 = Radiobutton(win,text="red",variable=var_chk2,value="red",command=my_fg)

rb1.grid(row=1,column=0)
rb2.grid(row=2,column=0)
rb3.grid(row=3,column=0)
rb4.grid(row=1,column=2)
rb5.grid(row=2,column=2)
rb6.grid(row=3,column=2)



win.mainloop()