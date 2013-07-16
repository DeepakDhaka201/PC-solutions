#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
const int BGCOLOR=EGA_BLACK;
const int title_depth=15;
int windcnt=-1;
int active=0;
int toplevel=0;
int MOUSEX,MOUSEY;
int ex,ey;
int exit_button_ht=10;
int active_window_color=EGA_YELLOW;


//Initialise Mouse
void mouseinit(){
union REGS reg;
reg.x.ax=0;
int86(0x33,&reg,&reg);
if(reg.x.ax){printf(" Mouse is not Present");getch();exit(0);}
}
//Show the Mouse
void mouseshow(){
	union REGS reg;
	reg.x.ax=0x01;
	int86(0x33,&reg,&reg);

}
//Clip the mouse
void mouseclip(int x1,int y1,int x2,int y2){
	union REGS reg;
	reg.x.cx=x1 <<1;reg.x.dx=x2 <<1;
	reg.x.ax=0x07;
	int86(0x33,&reg,&reg);
	reg.x.cx=y1;
	reg.x.dx=y2;reg.x.ax=0x08;
	int86(0x33,&reg,&reg);
}
//Hide the Mouse
void mousehide(){
 union REGS reg;
 reg.x.ax=0x02;
 int86(0x33,&reg,&reg);
}
//Read the Mouse up
int readmouse(){
union REGS reg;
reg.x.ax=0x06;reg.x.bx=0;
int86(0x33,&reg,&reg);
if(!reg.x.bx) return 0;
MOUSEX=reg.x.cx >> 1;
MOUSEX=MOUSEX*2;
MOUSEY=reg.x.dx;
return 1;
}
//Read Mouse down
int readmousedn(){
union REGS reg;
reg.x.ax=0x03;
int86(0x33,&reg,&reg);
if(!(reg.x.bx &1))return 0;
MOUSEX=reg.x.cx >>1;
MOUSEY=reg.x.dx;
MOUSEX=2*MOUSEX;
return 1;
}

//Initialize everything
void init(){
	int m=DETECT,g;
	initgraph(&m,&g,"");setfillstyle(SOLID_FILL,EGA_BLACK);
	ex=getmaxx();ey=getmaxy();
	bar(0,0,getmaxx(),getmaxy());
	mouseclip(0,0,319,478);
}
void refresh();
struct wind{
 char title[20];
 int depth;
 int active;
 int title_bar_color,window_color;
 int topx,topy,botx,boty;
};
typedef struct wind Window;

struct node{
   Window wind;
   int id;
   struct node * next;
};
typedef struct node  *link;
link head;
Window windows[100];

void dispwindow(Window wind,int flag){
char buffer[100];
int dtopx,dtopy,dbotx,dboty,title_bar_depth;
mousehide();
if(!(wind.topx>=0 && wind.botx<ex && wind.topy>=0 && wind.boty<ey)) return;
if(wind.topx<0) dtopx=0;
else if(wind.topx>ex) dtopx=ex;else dtopx=wind.topx;
if(wind.topy<0) dtopy=0;
else if(wind.topy>ey)dtopy=ey;else dtopy=wind.topy;
if(wind.botx<0) dbotx=0;
else if(wind.botx>ex) dbotx=ex;else dbotx=wind.botx;
if(wind.boty>ey) dboty=ey;
else if(wind.boty>ey) dboty=ey;else dboty=wind.boty;
if(dtopy+title_depth>dboty) title_bar_depth=dboty;
else title_bar_depth=dtopy+title_depth;
setfillstyle(SOLID_FILL,wind.window_color);setcolor(EGA_WHITE);
bar3d(dtopx,dtopy,dbotx,dboty,1,1);
if(!flag)setfillstyle(SOLID_FILL,wind.title_bar_color);
else setfillstyle(SOLID_FILL,active_window_color);
bar3d(dtopx,dtopy,dbotx,title_bar_depth,0,0);
sprintf(buffer,wind.title);
while(textwidth(buffer)>(dbotx-dtopx) && buffer[0]!='\0') buffer[strlen(buffer)-2]='\0';
if(title_bar_depth-dtopy>10)outtextxy(dtopx+1,dtopy+2,buffer);
setfillstyle(SOLID_FILL,EGA_BLACK);
bar3d(dbotx-15,dtopy,dbotx,title_bar_depth,0,0);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(dbotx-12,dtopy+5,"X");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
mouseshow();
}

int getid(int x,int y){
int i=0,j=0;
for(j=toplevel-1;j>=0;j--)
  for(i=0;i<=windcnt;i++) if(windows[i].depth==j) if(x>=windows[i].topx && x<=windows[i].botx && y>=windows[i].topy && y<=windows[i].boty) return i;
return -1;
}


void functionhandler(int windid){
int id,xdiff,x1diff,ydiff,y1diff,i;
int prevx,prevy;
if(!readmousedn()) return;
id=getid(MOUSEX,MOUSEY);
if(id<0) return ;
if(id!=windid){
active=id;windows[id].depth=toplevel;toplevel++;refresh();return;}
 if(istitle(id)){
  xdiff=MOUSEX-windows[id].topx;x1diff=MOUSEX-windows[id].botx;
  ydiff=MOUSEY-windows[id].topy;y1diff=MOUSEY-windows[id].boty;
  prevx=MOUSEX;prevy=MOUSEY;
	 while(readmousedn() ){
	 if(prevx==MOUSEX && prevy==MOUSEY)continue;
	 cleardevice();prevx=MOUSEX;prevy=MOUSEY;
	 if(MOUSEX-xdiff>=0 && MOUSEX-x1diff<ex && MOUSEY-ydiff>=0 && MOUSEY-y1diff<ey)
	 {windows[id].topx=MOUSEX-xdiff;
	 windows[id].botx=MOUSEX-x1diff;
	 windows[id].topy=MOUSEY-ydiff;
	 windows[id].boty =MOUSEY-y1diff;}
	 mousehide();
	 refresh();mouseshow();
	 }
 }
 if(isexit(id)){
   for(i=id;i<windcnt;i++){
   windows[i]=windows[i+1];
   }active=-1;
   windcnt--;mousehide();
   cleardevice();
   refresh();mouseshow();
 }
}

int istitle(int id){
  if(MOUSEX>=windows[id].topx && MOUSEX<=windows[id].botx && MOUSEY >= windows[id].topy && MOUSEY<=windows[id].topy+title_depth) return 1;
  return 0;
}
int isexit(int id){
  if(MOUSEX>=windows[id].botx-15 && MOUSEX<=windows[id].botx && MOUSEY >= windows[id].topy && MOUSEY<=windows[id].topy+title_depth) return 1;
  return 0;
}


int main(){
	int flag,i=0,temp;Window wind;char c;
	init();
	createwindow(23,24,100,100,EGA_DARKGRAY,EGA_BLUE,"This is the title",toplevel);
	toplevel++;
	createwindow(60,60,200,200,EGA_DARKGRAY,EGA_BLUE,"This is the title",toplevel);
	toplevel++;
	createwindow(60,60,200,200,EGA_DARKGRAY,EGA_BLUE,"This is the title",toplevel);
	toplevel++;
	createwindow(60,60,200,200,EGA_DARKGRAY,EGA_BLUE,"This is the title",toplevel);
	toplevel++;
	refresh();
	while(1){
		if(kbhit()){
		  c=getch();
		  if(c=='q' || c=='Q') break;
		}
		mouseshow();
		functionhandler(active);
	}
	mouseclip(0,0,318,195);
	mousehide();
	closegraph();
}

int createwindow(int x1,int y1,int x2,int y2,int wind_color,int title_color,char *tit,int dep){
windcnt++;
windows[windcnt].topx=x1;windows[windcnt].botx=x2;windows[windcnt].topy=y1;windows[windcnt].boty=y2;
windows[windcnt].title_bar_color=title_color;
windows[windcnt].window_color=wind_color;windows[windcnt].depth=dep;
active=windcnt;strcpy(windows[windcnt].title,tit);
}

void refresh(){
int i=0,j;
for(i=0;i<toplevel;i++)
  for(j=0;j<=windcnt;j++) if(windows[j].depth==i){ if(j!=active) dispwindow(windows[j],0);else dispwindow(windows[j],1);break;}
}


