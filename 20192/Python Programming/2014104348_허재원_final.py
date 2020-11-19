from tkinter import *
from tkinter.filedialog import *
import tkinter.messagebox
from tkinter.simpledialog import *

def  openfile():
    filename = askopenfilename(parent=win)
    in_file = open(filename,"r")
    str_file = in_file.read()
    label1.configure(text=str_file)

def search():
    global searched
    searched = txt1.get()
    result_search = "검색결과 : "
    result_search += str(str_in.count(searched))
    result_search+="개"
    result.configure(text=result_search)

def change():
    str_txt1 = txt1.get()
    print(searched,str_txt1)
    global str_change
    str_change = str_in.replace(searched,str_txt1)
    label1.configure(text=str_change)

def save():
    savefilename=askstring("","파일명을입력하세요")
    out_file = open(savefilename,"w")
    out_file.write(str_change)
    out_file.close()

str_in = ""
searched = ""
str_change = ""
try:
    infile = open("yesterday.txt", "r")
    str_in += infile.read()
except :
    tkinter.messagebox.showinfo("Error","yesterday.txt 파일이 없습니다")
infile.close()


win = Tk()
win.geometry("500x500")

# Menu
main_menu = Menu(win)
win.config(menu=main_menu)
menu1 = Menu()
main_menu.add_cascade(menu=menu1,label="File")
menu1.add_command(label="Open",command=openfile)
menu1.add_command(label="Save",command=save)
menu1.add_command(label="Exit",command=quit)

# Label
label1 = Label(text=str_in)
label1.pack()

# text
txt1 = Entry(text="")
txt1.pack(side=LEFT)

# Button
btn_search = Button(text="검색", command=search)
btn_change = Button(text="변경",command=change)
btn_search.pack(side=LEFT)
btn_change.pack(side=LEFT)

# Label
result = Label(text="")
result.pack(side=LEFT)

win.mainloop()
