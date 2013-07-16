#include <stdio.h>

long long int mp[15];
int main(){
int n,five=5,cnt=0,t,i=0;mp[0]=1;
scanf("%d",&t);
for(i=1;i<=14;i++){mp[i]=five;five*=5;}
for(five=0;five<t;five++){
scanf("%d",&n);
int x=1;cnt=0;
while(n/mp[x]){cnt+=n/mp[x];x++;}
printf("%d\n",cnt);
}

}
