#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>


#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define rev(ar) reverse(ar.begin(),ar.end())
#define p_b push_back
#define mset(ar,i) memset(ar,i,sizeof(ar))
#define VI vector<int> 
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define ALL(ar) ar.begin(),ar.end()
typedef long long int LL;
using namespace std;

struct node{
  int vertex;
  node(int a):vertex(a){}
};

int cost[101];
int tolls[101];

bool operator<(const node& a,const node& b){
  return cost[a.vertex] < cost[b.vertex];
}

struct st{
    int to,toll,time;
    st(int a,int b,int c):to(a),time(b),toll(c){}
};



int max_t;

int main(){
    int T = GI;
    REP(t,T){
      max_t = GI; 
      int N = GI;
      int R = GI;
      vector<st> v[101];
      REP(i,R){
        int from = GI,to = GI;
        int len = GI,toll = GI;
        v[from - 1].p_b( st(to - 1,len,toll) );         
      }
    
         
      REP(i,N) cost[i] = 1<<30;
      REP(i,N) tolls[i] = 0;
      
      cost[0] =  0;
      priority_queue<node> s;
      s.push( node(0) );
      
      while(!s.empty()){
          node n = s.top();s.pop();
          cout << " in vertex = "<< n.vertex+1 <<endl;
          if( n.vertex == N-1 ) break;
          REPV(i,v[n.vertex]){
             int from = n.vertex;
             int to = v[n.vertex][i].to;
             int tol = v[n.vertex][i].toll;
             int cos = v[n.vertex][i].time;
             if( tolls[from] + tol < max_t  &&
                 cost[to] > cost[from] + cos ){
               if(s.find(to) != s.end()) s.erase(s.find(to));
               cost[to] = cost[from] + cos;
               tolls[to] = tolls[from] + tol;
               s.push(node(to));             
               cout << " pushing " << to+1 << " time = " << cost[to] << " money = " << tolls[to] << endl;
             }                              
          }
          
          cout << " SET S " << endl;
          EACH(it,s) cout << (*it).vertex + 1 << " with cost =  " << cost[(*it).vertex] << endl;
      }
      
      if(cost[N-1] >= (1<<30)) cout << -1 << endl;
      else cout << cost[N-1] << endl;
    }
}
