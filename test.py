import tk
from math import pi
from math import cos
from math import sin
from math import sqrt

global flag
flag=False

def dessine(rd,cd,apd):
    x1=cos(apd)*rd+rd+100
    y1=100+rd/3-sin(apd)*rd/3
    x2=cos(apd+pi/2)*rd+rd+100
    y2=100+rd/3-sin(apd+pi/2)*rd/3
    x3,y3=x2,y2+cd
    x4,y4=x1,y1+cd
    can.create_line(x1,y1,x2,y2,width=3,fill="white")
    can.create_line(x2,y2,x3,y3,width=3,fill="white")
    can.create_line(x3,y3,x4,y4,width=3,fill="white")
    can.create_line(x4,y4,x1,y1,width=3,fill="white")

def tourne(r,c,a):
    can.delete(tk.ALL)
    ap=2*pi*a/360
    dessine(r,c,ap)
    dessine(r,c,ap+pi/2)
    dessine(r,c,ap+pi)
    dessine(r,c,ap+(3/2)*pi)
    global ang
    ang=ang+1
    ang=ang%360

def debut():
    global flag
    global ang
    if flag==False:
        ang=0
        flag=True
    ray=150
    cot=sqrt(2)*ray
    tourne(ray,cot,ang)
    fen.after(25,debut)

fen=tk.Tk()
fen.title("Cube giratoire")
can=tk.Canvas(fen,width=500,height=500,bg="black")
can.pack(side=tk.TOP)
b1=tk.Button(fen,text="Démarrer",command=debut)
b1.pack(side=tk.LEFT)
b2=tk.Button(fen,text="Quitter",command=fen.destroy)
b2.pack(side=tk.RIGHT)

fen.mainloop()
