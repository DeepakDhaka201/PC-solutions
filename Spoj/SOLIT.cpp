#include <iostream> 
#include <string>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(_typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<30)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;
vector<PII> V;
char Seen[(1<<24)+1],Seenid;
int Board[16][16],Tboard[16][16];
#define ok(i,j) (i>=0 && j>=0 && i<8 && j<8)
#define ok1(i) (i>=0 && i<8)
#define CH(as) if(!(as)){ printf("sdgdgsdg\n");while(1);}

int  encode(){
	int ret = 0;
	REP(i,4) ret = (ret*8+V[i].first)*8 + V[i].second;
	CH(ret<=(1<<24));//check
	return ret;
}


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n_matched;
int cnt = 0;

void go(int step){
	cnt++;
	if(cnt > 1e5) throw 'a';//Check 
	if(!n_matched) throw 1;
	if(step+n_matched > 8) return;
	if(Seen[encode()] <= step) return;
	Seen[encode()] = step;
	
	int ox,oy,newx,newy;	
	REP(i,4) REP(j,4){
		ox = V[i].first,oy = V[i].second;
 		newx = ox + dx[j],newy = oy + dy[j];
 		if(!ok(newx,newy)) continue;
		if(Board[newx][newy]) newx += dx[j],newy += dy[j];
		if(!ok(newx,newy) || Board[newx][newy]) continue;
		
		int oldm = n_matched;		
		if(Tboard[ox][oy]) n_matched++;		
		if(Tboard[newx][newy]) n_matched--;		
		
		Board[ox][oy] = 0,Board[newx][newy] = 1;
		V[i].first = newx,V[i].second = newy;
		go(step+1);
		V[i].first = ox,V[i].second = oy;
		Board[ox][oy] = 1;Board[newx][newy] = 0;
		n_matched = oldm;
	}
}



int main(){
	int Tr,a;
	scanf("%d",&Tr);
	REP(t,Tr){
		memset(Board,0,sizeof(Board));
		memset(Tboard,0,sizeof(Tboard));
		int n_matched = 4;
		REP(i,4){
		 	int a = GI-1,b = GI-1;
			Board[a][b] = 1;
			V.pb(PII(a,b));
		}		
		REP(i,4){
		 	int a = GI-1,b = GI-1;
		 	Tboard[a][b] = 1;
		 	if(Board[a][b]) n_matched--;
		}		
		REP(i,(1<<24)) Seen[i] = (100);		
		
		try{
			go(0);
			printf("NO\n");
		}catch(int){ printf("YES\n");}
		catch(char){ printf("NO\n");while(1);}//Check
	}	
	return 0;
}

