#include <iostream>
using namespace std;

int main(){
int t,i,tloop,n,j,a;scanf("%d",&t);
for(tloop=0;tloop<t;tloop++){
scanf("%d",&n);
if(n>1){
j=1;printf(" n: %d\n",n);
for(i=2;i*i<n;i++) if(n%i==0){ j+=i;j+=(a/i);printf("%d\n",i);}
if(n%i==0) j+=i;
printf("%d\n",j);   
}
else printf("0\n");
}
getchar();getchar();                             
}
    
