#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_

#include "acllib.h"
#include <stdio.h>
#include <stdlib.h>

#define W_WIDTH  300
#define W_HEIGHT 399
#define ARMY_WIDTH 40
#define ARMY_HEIGHT 47
#define ENEMY_WIDTH 30
#define ENEMY_HEIGHT 22
#define BLT_WIDTH 4
#define BLT_HEIGHT 10
#define TXTSIZE 20
#define TXTFONT "幼圆"

#define MAXENEMY 200		//场上最多敌机个数 
#define MAXBLT 50			//场上最多子弹个数 
#define TIMEINTERVAL 20   //20ms  50fps

#define LEFT	1
#define UP  	2
#define RIGHT	3
#define DOWN	4

typedef struct _bg{
	ACL_Image image;
	int x,y1,y2;
}BG;

typedef struct _flighter{
	ACL_Image image;
	int width,height;
	int xl,yl,xr,yr;
	int dir;
	int isAlive;
}Flighter;

typedef struct _bullet{
	ACL_Image image;
	int width,height;
	int xl,yl,xr,yr;
	int isAlive;
}Bullet;

int enemyspeed = 1;
int gaptimems = 20;

void initArmy(Flighter *army){
	loadImage("data/army.bmp",&(army->image));
	army->isAlive = 1;
	//cordinary position
	army->width = ARMY_WIDTH;
	army->height = ARMY_HEIGHT;
	army->xl = 130;
	army->yl = 320;
	army->xr = army->xl + army->width -1;
	army->yr = army->yl + army->height -1;
	//dir
	army->dir = 0;
}

void initEnemy(Flighter *enemy){
	loadImage("data/enemy.bmp",&(enemy->image));
	enemy->isAlive = 1;
	//cordinary position
	enemy->width = ENEMY_WIDTH;
	enemy->height = ENEMY_HEIGHT;
	enemy->xl = rand()%271;
	enemy->yl = -enemy->height;
	enemy->xr = enemy->xl + enemy->width -1;
	enemy->yr = enemy->yl + enemy->height -1;
	//dir
	enemy->dir = 0;
}
Bullet initBLT(Bullet blt,Flighter *f,int xw,int yw){
	loadImage("data/bullet.bmp",&blt.image);
	blt.width = BLT_WIDTH;
	blt.height =BLT_HEIGHT;
	blt.isAlive = 0;
	//cordinary
	blt.xl = f->xl + xw;
	blt.yl = f->yl + yw;
	blt.xr = blt.xl + blt.width -1;
	blt.yr = blt.yl +blt.height -1;
	return blt;
}

BG initBG(BG bg){
	loadImage("data/bg.bmp",&bg.image);
	bg.x  = 0;
	bg.y1 = 0;
	bg.y2 = -W_HEIGHT+1;
	return bg;
}

//motion
void moveEnemy(Flighter *f){
	if(f->isAlive == 1){
		switch(f->dir){
			case LEFT:	(f->xl >= 0)?(f->xl -=enemyspeed , f->xr -=enemyspeed):1;
				break;
			case RIGHT:	(f->xr <= W_WIDTH)?(f->xl +=enemyspeed , f->xr +=enemyspeed):1;
				break;
			case UP:	(f->yl >= 0)?(f->yl -=enemyspeed , f->yr -=enemyspeed):1;
				break;
			case DOWN:	(1)?(f->yl += enemyspeed , f->yr +=enemyspeed):1;
				if(f->yl > W_HEIGHT){
					f->isAlive = 0;
				}
				break;
			default:
				;
		}
	}
}
void moveArmy(Flighter *f){
	switch(f->dir){
		case LEFT:	(f->xl >= 0)?(f->xl -= 3 , f->xr -= 3):1;
			break;
		case RIGHT:	(f->xr <= W_WIDTH)?(f->xl += 3 , f->xr += 3):1;
			break;
		case UP:	(f->yl >= 0)?(f->yl -= 3 , f->yr -= 3):1;
			break;
		case DOWN:	(f->yr <= W_HEIGHT)?(f->yl += 3 , f->yr += 3):1;
			break;
		default:
			;
	}
}
void moveBLT(Bullet *blt){
	if(blt->isAlive == 1){
		blt->yl -= 6;
	}
	if( blt->yl < 0 ){
		blt->isAlive = 0;
	}
}
void moveBG(BG *bg){
	bg->y1 ++;
	bg->y2 ++;
	if(bg->y1 == W_HEIGHT){
		bg->y1 = -W_HEIGHT+1;
	}
	if(bg->y2 == W_HEIGHT){
		bg->y2 = -W_HEIGHT+1;
	}
}

//onhit

//paint function
void paintFlighter(Flighter *f){
	if(f->isAlive == 1){
		putImageTransparent(&(f->image),f->xl,f->yl,f->width,f->height,WHITE);		
	}
}
void paintBLT(Bullet *blt){
	if(blt->isAlive == 1){
		putImageTransparent(&(blt->image),blt->xl,blt->yl,blt->width,blt->height,WHITE);		
	}
}
void paintBG(BG *bg){
	putImage(&(bg->image),bg->x,bg->y1);
	putImage(&(bg->image),bg->x,bg->y2);
}

#endif
