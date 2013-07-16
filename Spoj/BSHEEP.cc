#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int LL;
#define REP(i,n) for(int i = 0;i<n;i++)
#define REPV(i,ar) for(int i  = 0;i<ar.size();i++)
#define p_b push_back
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define EACH(it,mp) for( typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define LL long long int
#define VI vector<int>
#define VS vector<string>
#define GI ({int t;scanf("%d",&t);t;});

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

struct node{
       int ind;
       int x,y;
       node(int a,int b,int c):ind(a),x(b),y(c){}      
};
int pt[2];

bool operator<(const node& a,const node& b){
     int x1 = a.x - pt[0];
     int y1 = a.y - pt[1];
     int x2 = b.x - pt[0];
     int y2 = b.y - pt[1];
     if( x1*y2 == x2*y1){
          if( y1 == y2 ) return x1<x2;
          if( x1 == x2 ) return y2<y1;
          return (x1*x1+ y1*y1)<(x2*x2 + y2*y2);
          }
     return (x1*y2 - x2*y1) > 0;
}

vector< node > V;
int low_index;

bool concave(int a,int b,int c){
     int p1[2] = { V[a].x,V[a].y};
     int p2[2] = { V[b].x,V[b].y};
     int p3[2];
     if( c == -1 ) p3[0] = pt[0],p3[1] = pt[1];
     else p3[0] = V[c].x,p3[1] = V[c].y;
     
     int x1 = p2[0] - p3[0];
     int y1 = p2[1] - p3[1];
     int x2 = p1[0] - p3[0];
     int y2 = p1[1] - p3[1];
     return (x1*y2 - x2*y1) <= 0;          
}

int main(){
    int T = GI;
    REP(t,T){
        int N = GI;
        map< PII,int > mp;
        V.clear();
        pt[0] = pt[1] = 0;
        
        int la = (1<<30),lb = (1<<30);
        REP(i,N){
	  double a1,b1;
	  scanf("%lf %lf",&a,&b);
          int a = int(a1*10),b = int(b1*10);
          if(!mp[PII(a,b)]) mp[PII(a,b)] = (i+1);
          if( b == lb ) if(a < la) la = a,lb = b;
          if( b < lb )la = a,lb = b;
        }

        pt[0] = la,pt[1] = lb;
        mp.erase(mp.find(PII(la,lb)));
        EACH(it,mp) V.p_b( node(it->second,it->first.first,it->first.second) );
        mp.clear();
 
        sor(V);
        V.p_b( node(low_index,la,lb) );
        vector<int> stack;       
        stack.p_b( -1 );
        stack.p_b(  0 );
      
        FOR(i,1,V.size()-1){
           while(stack.size()>=2 && concave(i,stack[stack.size()-1],stack[stack.size()-2])){
                 if(i!=V.size()-1){
                        stack.pop_back();
                        continue;
                 }
                 if( i== V.size()-1 && stack.size()>2)  stack.pop_back();
                 else break;
           }
           if(i != V.size()-1)stack.push_back(i);
        }
        

        REPV(i,stack){
          if( stack[i] == -1 ) printf("%d ",low_index);
          else printf("%d ",V[stack[i]].ind);
        }
        cout << endl << endl;
    }
    
}


