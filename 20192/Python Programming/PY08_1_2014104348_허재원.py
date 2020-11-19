from tkinter import *

def btn_befo(event):
    global i
    if(i==0):
        i=4
    else:
        i-=1
    photo = img[i]
    la_image.configure(image=photo)
    la_image.image=photo


def btn_next(event):
    global i
    if(i==4):
        i=0
    else:
        i+=1
    photo = img[i]
    la_image.configure(image=photo)
    #la_image.image=photo

# Tk instance
win = Tk()
win.title("사진 앨범 보기")

b_befo = Button(win,text="<< 이전")
b_next = Button(win,text="다음 >>")

b_befo.grid(row=0,column=0)
b_next.grid(row=0,column=1)

# bind
b_befo.bind("<Button>",btn_befo)
b_next.bind("<Button>",btn_next)
win.bind("<Left>",btn_befo)
win.bind("<Right>",btn_next)



# label
img = [None]*5
img[0] = PhotoImage(file=".\images\jeju1.png")
img[1] = PhotoImage(file=".\images\jeju2.png")
img[2] = PhotoImage(file=".\images\jeju3.png")
img[3] = PhotoImage(file=".\images\jeju4.png")
img[4] = PhotoImage(file=".\images\jeju5.png")
i=0
la_image = Label(win, image=img[i])
la_image.grid(row=1,columnspan=2)


win.mainloop()