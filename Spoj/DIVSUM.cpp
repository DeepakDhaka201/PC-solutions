#include <stdio.h>

int main(){
int t,tloop,n;scanf("%d",&t);
register int i,j;
for(tloop=0;tloop<t;tloop++){
scanf("%d",&n);j=1;
if(!(n-1)){ printf("0\n");continue;}
for(i=2;i*i<n;i++) if(n%i==0){ j+=i;j+=(n/i);}
if(i*i==n) j+=i;
printf("%d\n",j);   

}
return(0);  
}
    
