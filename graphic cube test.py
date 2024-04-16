import pygame
from math import pi
from math import cos
from math import sin
from math import sqrt

pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True


font = pygame.font.SysFont(None, 24)
flag = False
can_rotate = False
ang = 0

def dessine(rd,cd,apd):
    x1=cos(apd)*rd+rd+100
    y1=100+rd/3-sin(apd)*rd/3
    x2=cos(apd+pi/2)*rd+rd+100
    y2=100+rd/3-sin(apd+pi/2)*rd/3
    x3,y3=x2,y2+cd
    x4,y4=x1,y1+cd
    add = 0
    for i in range(int(y2), int(y3)):
        add = y2 - i
        pygame.draw.line(screen, "red", [x1 ,y1 - add], [x2, y2 - add], 1)   
    pygame.draw.line(screen, "white", [x1,y1], [x2,y2], 1)
    pygame.draw.line(screen, "white", [x2,y2], [x3,y3], 1)
    pygame.draw.line(screen, "white", [x3,y3], [x4,y4], 1)
    pygame.draw.line(screen, "white", [x4,y4], [x1,y1], 1)

def tourne(r,c,a):
    ap=2*pi*a/360
    
    if (a < 45) :
        dessine(r,c,ap+pi)
        dessine(r,c,ap+(3/2)*pi) 
    elif (a < 135) :
        dessine(r,c,ap+pi)
        dessine(r,c,ap+pi/2)
    elif (a < 225) :
        dessine(r,c,ap)
        dessine(r,c,ap+pi/2)
    elif (a < 315) :
        dessine(r,c,ap)
        dessine(r,c,ap+(3/2)*pi) 
    else :
        dessine(r,c,ap+pi)
        dessine(r,c,ap+(3/2)*pi) 
    # if (a < 90) :
    #     dessine(r,c,ap+pi)
    #     dessine(r,c,ap+(3/2)*pi)    
    # elif (a < 180) :
    #     dessine(r,c,ap+(3/2)*pi)
    #     dessine(r,c,ap)
    # elif (a < 270) :
    #     dessine(r,c,ap)
    #     dessine(r,c,ap+pi/2)
    # else :
    #     dessine(r,c,ap+pi/2)
    #     dessine(r,c,ap+pi)    

    
    # dessine(r,c,ap)
    # dessine(r,c,ap+pi/2)
    # dessine(r,c,ap+pi)
    # dessine(r,c,ap+(3/2)*pi)
    if (can_rotate) :
        global ang
        ang=ang+1
        ang=ang%360



while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    keys = pygame.key.get_pressed()
    if keys[pygame.K_SPACE]:
        can_rotate = not(can_rotate)
    # fill the screen with a color to wipe away anything from last frame
    screen.fill("black")

    # RENDER YOUR GAME HERE
    ray=150
    cot=sqrt(2)*ray
    tourne(ray,cot,ang)
    # flip() the display to put your work on screen
    pygame.display.flip()

    clock.tick(60)  # limits FPS to 60

pygame.quit()