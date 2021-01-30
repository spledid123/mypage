import turtle
import time
import math
def name(): #输入名字并显示，楷体，绿色，字号30
    a = input('请输入你的名字:')
    turtle.penup()
    turtle.goto(-40,-300)
    turtle.pendown()
    turtle.pencolor('green')
    turtle.write(a,font=('楷体',30,'normal'))
def curveonly(length,n):#单根曲线
    if n==0:
        turtle.fd(length)
    else:
        for angle in [0,60,-120,60]:
            turtle.left(angle)
            curveonly(length/3,n-1)   #单根线
def snowflake(n):#雪花 蓝色
    turtle.setup(700,800)
    turtle.penup()
    turtle.goto(-300,173.2)
    turtle.pendown()
    turtle.seth(0)
    for i in range(3):
        turtle.pencolor('blue')
        turtle.pensize(2.5)
        curveonly(600,n)
        turtle.right(120)#雪花
def timeknows():#获取系统时间并显示 蓝色
    s=time.gmtime()
    a=time.ctime()
    turtle.penup()
    turtle.goto(-70,-250)
    turtle.pencolor('blue')
    turtle.pendown()
    turtle.write(a)
    if time.strftime("%I",s)[0]=='0':
        hour=eval(time.strftime("%I",s)[1])
    else:
        hour=eval(time.strftime("%I",s))
    hour=hour+8
    min1=eval(time.strftime("%M",s))
    if hour>=12:
        hour=hour-12
    #换时区
    return hour,min1
def clock():#画钟表 黑色
    turtle.pencolor('black')
    turtle.pensize(2)
    for i in range(1,13):
        angle=i*30/180*math.pi
        turtle.penup()
        turtle.goto(150*(math.cos(angle)),150*(math.sin(angle)))
        turtle.seth(i*30)
        turtle.pendown()
        turtle.fd(25)
        i=i+1
def point(m,n):#画时针 红色
    turtle.pencolor('red')
    turtle.pensize(2)
    anglem=90-(m*30+n*0.5)
    anglen=90-n*6
    turtle.penup()
    turtle.goto(0,0)
    turtle.seth(anglem)
    turtle.pendown()
    turtle.fd(85)
    turtle.penup()
    turtle.goto(0,0)
    turtle.seth(anglen)
    turtle.pendown()
    turtle.fd(155)
def main(n):#主函数
    turtle.hideturtle()
    turtle.speed(0)
    name()
    snowflake(n)
    hour,min1=timeknows()
    clock()
    point(hour,min1)
    turtle.done()
a=eval(input('你想要几阶雪花？（请输入2~5的一个整数）'))
main(a)
