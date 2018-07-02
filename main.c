#include "aircraft.h"

Flighter army ;
Flighter enemy[MAXENEMY];
Bullet blt[MAXBLT];
Bullet blt2[MAXBLT];
BG bg;
ACL_Image gameover;
ACL_Sound firesound;
ACL_Sound bgm;
ACL_Sound bgm2;
int yg = -50;
int cnt = 0;		//子弹序号 
int cnt2 = 0;
int enemycnt = 0;	//敌机序号 
int heat = 0;		//炮管热量 
int gaptime = 0;	//敌机出现间隔时间
int score = 0; 
char txt[5] ={48,};
int isFire = 0;		//是否开火 
int isPlaySound = 0;

void movePosition();
void fire();
void crash();
void paintGameOver();
void enemyOut();
void paintTitle();
//view
void paint(){
	int i =0;
	movePosition();
	beginPaint();
	clearDevice();
	setTextColor(BLACK);
	setTextSize(TXTSIZE);
	setTextFont(TXTFONT);
	paintBG(&bg);
	paintTitle();
	for(i=0;i<MAXENEMY;i++){
		paintFlighter(&enemy[i]);
	}
	for(i=0;i<MAXBLT;i++){
		paintBLT(&blt[i]);
		paintBLT(&blt2[i]);
	}
	if(army.isAlive == 1){
		paintFlighter(&army);
	}else if(army.isAlive == 0){
		paintGameOver();
	}
	endPaint();	
}

//model
void movePosition(){
	int i=0;
	if(army.isAlive == 1){
		moveArmy(&army);
	}
	if(army.isAlive == 0){
		if(yg <= 180) yg += 1;
	}
	for(i=0;i<MAXENEMY;i++){
		moveEnemy(&enemy[i]);
	}
	for(i=0;i<MAXBLT;i++){
		moveBLT(&blt[i]);
		moveBLT(&blt2[i]);
	}
	moveBG(&bg);
}

void timer(int id){
	if(id == 0){
		if(army.isAlive ==1){
			crash();
			fire();
		}
			enemyOut();
			paint();
		//music
		if(isPlaySound == 0 && army.isAlive == 1){
			playSound(bgm,1);
			isPlaySound = 1;
		}else if(isPlaySound == 1 && army.isAlive == 0){
			isPlaySound =2;
			playSound(bgm2,0);
		}
	}
}

void fire(){
	if( isFire == 1){
		if(heat == 0){
			heat = 6;
			blt[cnt] = initBLT(blt[cnt],&army,5,8);
			blt2[cnt2] = initBLT(blt2[cnt2],&army,32,8);
			blt[cnt].isAlive = 1;
			blt2[cnt2].isAlive = 1;
			playSound(firesound,0);
//			printf("%d %d\n",cnt,blt[cnt].isAlive);
			if(++cnt == MAXBLT) cnt = 0;
			if(++cnt2 == MAXBLT) cnt2 = 0;
		}else
			heat -- ;
	}
}

void enemyOut(){
	if(gaptime <= 0){
		initEnemy(&enemy[enemycnt]);
		enemy[enemycnt].dir = DOWN;
		gaptime = rand()%gaptimems*4+gaptimems;
		if(++enemycnt == MAXENEMY) enemycnt =0;
	}else 
		gaptime -= enemyspeed;
	if(score > 0 && score % 20 == 0){
		enemyspeed = score/20 +1;
		if(gaptime >= 10){
			gaptimems = 20 - enemyspeed ;			
		}
	}
}

void keyAction(int key,int event){
	static int isMove = 0;
	if( isMove == 0 && (key >= 37 && key <= 40) && event == 0 ){
		isMove = 1;
		switch(key){
			case 37:	army.dir = LEFT;	break;
			case 38:	army.dir = UP  ;	break;
			case 39:	army.dir = RIGHT;	break;
			case 40:	army.dir = DOWN;	break;
		}
	}else 
	if( isMove == 1 && (key >= 37 && key <= 40) && event == 1){
		isMove = 0;
		army.dir = 0;
	}
	if( isFire == 0 && key == 32 && event == 0){
		isFire = 1;
	}else
	if( isFire == 1 && key == 32 && event == 1){
		isFire = 0;
	}
}

void isHitbyBLT( Bullet *blt,Flighter *f ){
	if(blt->isAlive ==1 && f->isAlive ==1 && blt->yl <= f->yr && blt->yr >= f->yl){
		if(!(blt->xr <f->xl || blt->xl > f->xr)){
			f->isAlive = 0;
			blt->isAlive = 0;
			score ++; 
		}
	}
}

void isCrash(Flighter *enemy,Flighter *army){
	if(enemy->isAlive ==1 && army->isAlive ==1 && enemy->yr >= army->yl && enemy->yl <=army->yr){
		if(!(army->xr <enemy->xl  || army->xl > enemy->xr)){
			enemy->isAlive = army->isAlive = 0;
		}
	}
}

void crash(){
	int i,j;
	for(i=0;i<MAXBLT;i++){
		for(j=0;j<MAXENEMY;j++){
			isHitbyBLT( &blt[i],&enemy[j] );
			isHitbyBLT( &blt2[i],&enemy[j]);
		}
	}
	for(j=0;j<MAXENEMY;j++){
		isCrash( &enemy[j], &army);
	}
}

void paintGameOver(){
	putImageTransparent(&gameover,50,yg,200,40,WHITE);
}

void getText(int score){
	int s = score;
	int n=0;
	while(s>0){
		s = s /10 ;
		n++;
	}
	s = score;
	while( n>0 ){
		txt[n-1] = s%10 +48;
		s = s/10;
		n --;
	}
}

void paintTitle(){
	getText(score);
	paintText(2,2,txt);
}

//control
void getKey(int key,int event){
	keyAction(key,event);
}

int Setup(){
	initWindow("AirCraft",500,200,W_WIDTH,W_HEIGHT);
//	initConsole();
	int i;
	srand(time(NULL));
	loadImage("data/gameover.bmp",&gameover);
	loadSound("data/fire.wav",&firesound);
	loadSound("data/bgm1.mp3",&bgm);
	loadSound("data/gameover.mp3",&bgm2);
	bg = initBG(bg);
	initArmy(&army);
	for(i=0;i<MAXENEMY;i++){
		initEnemy(&enemy[i]);
	}
	for(i=0;i<MAXBLT;i++){
		blt[i] = initBLT(blt[i],&army,5,8);
		blt2[i] = initBLT(blt2[i],&army,32,8);
	}
	registerKeyboardEvent(getKey);
	registerTimerEvent(timer);
	startTimer(0,TIMEINTERVAL);
	
	return 0;
}
