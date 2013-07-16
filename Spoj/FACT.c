#include <stdio.h>

int main(){
int n,five=5,cnt=0,t,i=0;
int mp[14];mp[0]=1;
scanf("%d",&t);
for(i=1;i<=14;i++){mp[i]=five;five*=5;}
for(five=0;five<t;five++){
scanf("%d",&n);
register int x=1;cnt=0;
while((i=n/mp[x++])){cnt+=i;}
printf("%d\n",cnt);
}
return(0);
}
