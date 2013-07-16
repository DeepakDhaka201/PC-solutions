#include <stdio.h>
#define MAX 10
char temp[MAX];
char stored[MAX];
unsigned short int used[MAX];
int N;

void permute(int i){
int j=0;
if(i==N){printf("%s\n",&temp[0]);}
for(j=0;j<N;j++){
   if(!used[j]){
      used[j]=1;temp[i]=stored[j];
      permute(i+1);
      used[j]=0;
   }
 }
}

int main(){
    ::N=5;
    stored[0]='a';
    stored[1]='b';
    stored[2]='c';
    stored[3]='d';
    stored[4]='e';stored[5]='\0';
    temp[5]='\0';

    permute(0);
}

