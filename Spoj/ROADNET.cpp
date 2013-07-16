#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define repv(i,ar) for(int i=0;i<ar.size();i++)
using namespace std;

int cost[201][201];

int n;


int main(){
int t;cin >> t;
rep(tloop,t){
cin >> n;
rep(i,n) rep(j,n) cin >> cost[i][j];
    
for(int i=0;i<n;i++) for(int j=i;j<n;j++){
if(i==j) continue;
int flag=1;
rep(k,n){
         if(k==i || k==j ) continue;
         else if(cost[i][j]=cost[i][k]+cost[k][j]){ flag=0;break;}
}           
if(flag==0) cout << i <<" "<<j <<endl;
}

}
return(0);
}
