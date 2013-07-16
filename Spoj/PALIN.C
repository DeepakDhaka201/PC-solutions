#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
char n[1000001];char a[1000000/2+1];
ll cnt;ll i=0;char *temp;ll j,k;ll t;int jj;

void f(){
 scanf("%s",&n);temp=n;while(temp[cnt])cnt++;
 for(i=0;i<cnt/2;i++) a[i]=n[cnt/2-i-1];a[i]='\0';//reverse the first half and store it in a
 temp=((cnt%2==0)?(&n[cnt/2]):(&n[cnt/2+1]));
 if(memcmp(a,temp,sizeof(a))> 0){//compare the reversed half and the remaining half
   n[cnt/2+((cnt%2==0)?(0):(1))]='\0';
   printf("%s%s\n",n,a);}
 else{
     if(cnt%2==0){k=1;j=0;}
     else{
     j=(n[cnt/2]-'0')+1;n[cnt/2]=j%10+'0';k=j/10;}
     for(i=cnt/2-1;i>=0;i--){j=k+(n[i]-'0');n[i]=(j)%10+'0';
      k=j/10;n[cnt-i-1]=n[i];}
     if(k){n[cnt-1]='1';
	   n[cnt]='\0';
	   printf("%ld%s\n",k,n);
	   }
     else printf("%s\n",n);
 }
}

int main(){
int t;scanf("%d",&t);
for(jj=0;jj<t;jj++)f();
cnt=i=j=k=0;
exit(0);
}
