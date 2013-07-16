#include <stdio.h>
#define rep(i,n) for(i=0;i<(n);i++)
#define ll long long int
int num,maxt;
ll tim[55][55];
ll tol[55][55];
ll cost[55][1001];

void ff(){
ll ret=0,id=0;int i,j,k;
rep(i,num) rep(j,maxt+1) cost[i][j]=(1LL<<40);
cost[0][0]=0;
rep(j,maxt+1) 
 rep(i,num) rep(k,num) 
	 if(j+tim[i][k]<=maxt)
          if(cost[k][j+tim[i][k]]>cost[i][j]+tol[i][k])
			  cost[k][j+tim[i][k]]=cost[i][j]+tol[i][k];
		  
ret=cost[num-1][0];
rep(i,maxt+1){
    if(cost[num-1][i]<ret){
      ret=cost[num-1][i];
      id=i;
    }
}
printf("%d",ret);printf(" %d\n",id);
}


int main(){
int i,j;
scanf("%d",&num);scanf("%d",&maxt);
while(num && maxt){
rep(i,num) rep(j,num) scanf("%d",&tim[i][j]);
rep(i,num) rep(j,num) scanf("%d",&tol[i][j]);
ff();
scanf("%d",&num);scanf("%d",&maxt);
}
}
