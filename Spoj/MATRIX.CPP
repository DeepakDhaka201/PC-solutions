#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>

int ar[80];
unsigned char ar1[80];
short int inc1[80];
int i=0;
char msg[]=" GAME OF LIFE   ";
short int fls[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void inc(){
int i=0;
for(i=0;i<80;i++){
  ar[i]+=inc1[i];
  if(ar[i]>50){ar[i]=0;ar1[i]=random(100)+50;inc1[i]=random(2)+1;}
}

}

void disp1(){
int i=0;
clrscr();
for(i=0;i<80;i++){
  if(i>35 && i<50){ if(fls[i-35]){
					  fls[i-35]=2;
					  gotoxy(i,25);
					  printf("%c",msg[i-35]);
					  continue;}
					  }
//  textcolor(GREEN);
  gotoxy(i,ar[i]);
  printf("%c",ar1[i]);}

}

int main(){
	int i=0,j=0,m=DETECT,g,flag=0;
	long int jj=0;
	clrscr();
	textcolor(GREEN);
	randomize();
	randomize();
	for(i=0;i<80;i++) ar[i]=random(30);
	for(i=0;i<80;i++) ar1[i]=random(100)+50;
	for(i=0;i<80;i++) inc1[i]=random(2)+1;
	disp1();


	while(!kbhit()){
	if(!flag){
	jj++;
	if(jj>200) flag=1;
	}
	else {if(random(100)>95 && j<14) fls[j++]=1;}
	delay(10);
	disp1();
	inc();
	}


}