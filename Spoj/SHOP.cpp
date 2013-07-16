#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#define rep(i,n) for(int i=0;i<(n);i++)
#define repv(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define sor(ar) sort(ar.begin(),ar.end())
#define VS vector<string>
#define VI vector<int>
#define p_b push_back
#define ALL(ar) ar.begin(),ar.end()
#define ll long long int 
#define sz size()
using namespace std;

struct node{
       int x,y,cost;
       node(int a,int b,int c):x(a),y(b),cost(c){}
};
bool operator<(const node& a,const node& b){
     return a.cost<=b.cost;     
     }

set<node> s;
VS v;
bool vis[30][30];
int xmax,ymax;


int find1(){
int sx=0,sy=0;
repv(i,v) repv(j,v[i]) if(v[i][j]=='S'){ sx=i,sy=j;break;} 
int ret=-1;
s.insert(node(sx,sy,0));
vis[sx][sy]=1;
while(!s.empty()){
set<node>::iterator n=s.begin();
int a=n->x,b=n->y,cost=n->cost;
s.erase(n);
FOR(i,-1,1) FOR(j,-1,1) if(!(i&&j))
  if(a+i>=0 && a+i<xmax && b+j>=0 && b+j<ymax && !vis[a+i][b+j] && v[a+i][b+j]!='X'){
       if(v[a+i][b+j]=='D'){ret=cost;return cost;}
       vis[a+i][b+j]=1;
       s.insert(node(a+i,b+j,cost+(v[a+i][b+j]-'0')));
 }                  

}   
return -1;    
}


int main(){
int t;
cin >> ymax >> xmax;
while(ymax && xmax){
s.clear();v.clear();memset(vis,0,sizeof(vis));
v.resize(xmax);
rep(i,xmax) cin >> v[i];
cout << find1() << endl;
cin >> ymax >> xmax;
}
}
