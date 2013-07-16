#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <map>
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
ll maxht=0;
struct node{
double b,h,area;
node(int x,int y,int w,int z):b(x),h(y),area(w*z){}
};
vector<node> v;
bool flag;

double get_volume(double ht){
double ret=0;flag=false;
repv(i,v){
    double temp=min(v[i].h,ht-v[i].b);      
    if(v[i].b<=ht && ht<=v[i].b+v[i].h && temp!=0) flag=true;
    ret+=v[i].area*(temp>=0?temp:0);                   
}
//cout << " for ht: "<< ht << " ret:"<<ret << endl;
return ret;       
}

double calc(ll volume){
double lo=0,hi=maxht+1,mid;
while(hi-lo>1e-5){
mid=(lo+hi)/2;
double temp=get_volume(mid);                  
  if(!(temp-volume) && flag) return mid;
  else if(temp<volume) lo=mid;
  else hi=mid;                  
}       
return mid;
}

int main(){
ll n,a,b,c,d,vol,tot=0,t;cin >> t;
rep(tloop,t){
cin >> n;v.clear();tot=0;
rep(i,n){cin >> a>>b>>c>>d;v.p_b(node(a,b,c,d));tot+=b*c*d;maxht>?=a+b;}
cin >> vol;
if(vol>tot) cout << "OVERFLOW";    
else {
     double temp=calc(vol);
     printf("%.2f\n",temp);
     }
}
return(0);
}
