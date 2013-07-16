#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <list>
//defines	

#define GI ({int i;scanf("%d",&i);i;})
#define p_b push_back
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(it,x,mp) for( x::iterator it = mp.begin();it!=mp.end();it++)
#define VI vector<int>
#define VS vector<string>
#define SI set<int>
#define ALL(ar) ar.begin(),ar.end()
#define MAXN (int(1e6) + 1)
#define INF (1<<30)
typedef long long int LL;
using namespace std;
typedef pair<int,int> PII;


vector< pair<PII,PII> > Segments;
VI dp[MAXN];
VI toadd[MAXN],toremove[MAXN];
map<PII,int> mp;


double get_y(int ind,int x){
       int x1 = Segments[ind].first.first,y1 = Segments[ind].first.second;
       int x2 = Segments[ind].second.first,y2 = Segments[ind].second.second;
      
       double slope = (y2-y1)*1.00/(x2-x1);
       return y1 + (x-x1)*slope;
}


PII get_end(int ind){
    if(Segments[ind].first.second<Segments[ind].second.second)
     return PII(-Segments[ind].first.second,Segments[ind].first.first);
    
    else
     return PII(-Segments[ind].second.second,Segments[ind].second.first);

   
}


ostream & operator<<(ostream& out,PII p){
   out << p.first << " " << p.second << " ";        
}


int main(){
    int T = GI;
    REP(t,T){
            mp.clear();
            Segments.clear();
            int N = GI;
            int maxx = -1;
            set<int> Pts_x,Pts_y;
             
             REP(i,N){
               int a = GI,b = GI,c = GI,d = GI;
               Segments.p_b(make_pair(PII(a,b),PII(c,d)));
               toadd[a].p_b(i);
               toremove[c].p_b(i);
               Pts_x.insert(a);Pts_x.insert(c);
               mp[PII(-b,a)] = 0;
               mp[PII(-d,c)] = 0;
               maxx >?= c;
             }
             
             set<int> current;
             int last = 0;
              
             EACH(k,set<int>,Pts_x){
                int i = *k;
                double level = 0;int seg = -1;

                EACH(it,set<int>,current){
                      double ty = get_y(*it,i);
                      if(ty >= level ) level = ty,seg = (*it);
                }

                if(seg >= 0 ){
                       PII end = get_end(seg);
                       mp[end] += (i-last);
                }

                REPV(j,toadd[i]) current.insert(toadd[i][j]);
                dp[i] = VI (current.begin(),current.end());
                REPV(j,toremove[i]) current.erase(current.find(toremove[i][j]));               
                last = i;
            }
            
  
            for(map<PII,int>::iterator it = mp.begin();it!=mp.end();it++) if(it->second){
               PII actual(it->first.second,-it->first.first);
               int amt = it->second;
               
               VI current = dp[actual.first];
               double level = 0;int seg = -1;
               REPV(j,current){
                      double ty = get_y(current[j],actual.first);
                      if(ty > level && ty < actual.second) level = ty,seg = (current[j]);
               }
               
               if(seg>=0){
                       PII end = get_end(seg);
                       mp[end] += (amt);
               }

            }
            
            REPV(i,Segments){
                printf("%d\n",mp[get_end(i)]);
                
                toadd[Segments[i].first.first].clear();
                toremove[Segments[i].first.first].clear();
                dp[Segments[i].first.first].clear();
                
                toadd[Segments[i].second.first].clear();
                toremove[Segments[i].second.first].clear();
                dp[Segments[i].second.first].clear();                
            }

            
   }
}

