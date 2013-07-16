#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i=GI;i;i--) V.pb( GI )
#define REP(i,N) for(int i = 0;i<N;i++)
#define sz size()
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<28)
#define rev(ar) reverse(ar.begin(),ar.end())
#define SEEN if(Seen[new_ti][new_c][new_nc] == Seenid) continue;Seen[new_ti][new_c][new_nc] = Seenid;
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;

int NT,Nodes;
map<int,int> mp;
int Trips[32],NXT[32],NSZ,Seenid;
int DP[32][256][256],Seen[32][256][256];// ( Ticket_index, Current_city, Next_city )
VI Tickets[32];
VI Gr[256];

int get_id(int x){
	if(mp[x]) return mp[x];
	return mp[x] = ++Nodes;	
}
inline int encode(int a,int b,int c){return (a*256+b)*256 + c;}
inline void decode(int& a,int& b,int& c,int X){a = X%256;X/=256;b = X%256;X/=256;c = X;}

void init(){
	mp.clear();
	Nodes = 0;
}


void go(){
	Seenid++;
	int ti,c,nc,new_ti,new_c,new_nc;
	//Push Sources
	set< PII > Q;// ( Cost,State )
	REPV(i,Gr[NXT[0]]){
		new_ti = Gr[NXT[0]][i];new_c = 0;new_nc = 1;		
		SEEN;
		DP[new_ti][new_c][new_nc] = -1;
		Q.insert(PII(Trips[new_ti],encode(new_ti,new_c,new_nc)));
	}
	
	int new_cost,rcost,rstate;
	
	while( Q.sz ){
		int cost=Q.begin()->first,state = Q.begin()->second;Q.erase(Q.begin());
		decode(ti,c,nc,state);
		
		if(NXT[nc]<0){
			rcost = cost,rstate = state;
			break;
		}
		
		//Continue in Same Ticket
		if(c<Tickets[ti].size()-1){
			new_ti = ti,new_c = c+1,new_nc = nc;
			if(Gr[new_ti][new_c] == NXT[new_nc]) new_nc++;	
			SEEN;
			DP[new_ti][new_c][new_nc] = state;
			Q.insert(PII(cost,encode(new_ti,new_c,new_nc)));		
		}
		
		//Change to another Ticket
		REPV(i,Gr[Tickets[ti][c]]){
			new_ti = Gr[Tickets[ti][c]][i],new_c = 0,new_nc = nc;
			if(Gr[new_ti][new_c] == NXT[new_nc]) new_nc++;
			SEEN;
			new_cost = cost+Trips[new_ti];
			DP[new_ti][new_c][new_nc] = state;			
			Q.insert(PII(new_cost,encode(new_ti,new_c,new_nc)));			
		}
	}
	
	int back = rstate;
	 
	
}


int main(){
	while((NT=GI)){
		init();
		REP(i,NT){
			Trips[i] = GI;
			int N = GI,Par = get_id(GI);
			Tickets[i].pb(Par);
			REP(j,N){
				int a = get_id(GI);
				Tickets[j].pb(a);
				Gr[Par].pb(j);	
			}
			int R = GI;
			REP(i,R){
				NSZ = GI;
				memset(NXT,-1,sizeof(NXT));
				REP(j,NSZ) NXT[j] = get_id(GI);
				go();
			}
		}
		
	}
	
}
