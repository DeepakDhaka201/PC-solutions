#include <iostream>
#include <string>
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
int pos[5][3],T[5][3];
short Seen[1<<24+1],Seenid;
bool Board[16][16],Tboard[16][16];
#define ok(i,j) (i>=0 && j>=0 && i<8 && j<8)
#define ok1(i) (i>=0 && i<8)
int  encode(){
	int ret = 0;
	REP(i,4) ret = (ret*8+pos[i][0])*8 + pos[i][1];
	return ret;
}


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n_matched;

void go(int step){
	if(!n_matched) throw 1;	
	if(step+n_matched > 8) return;	
	int en = encode();
	if(Seen[en] <= step) return;
	Seen[en] = step;
	
	REP(i,4) REP(j,4){
		int ox = pos[i][0],oy = pos[i][1];
 		int newx = pos[i][0] + dx[j],newy = pos[i][1] + dy[j];
 		if(!ok(newx,newy)) continue;
		if(Board[newx][newy]) newx += dx[j],newy += dy[j];
		if(!ok(newx,newy) || Board[newx][newy]) continue;
		if(!ok(newx,newy)) continue;
		
		int oldm = n_matched;		
		if(Tboard[ox][oy]) n_matched++;		
		if(Tboard[newx][newy]) n_matched--;		
		
		Board[ox][oy] = false;
		Board[newx][newy] = true;
		pos[i][0] = newx,pos[i][1] = newy;
		go(step+1);
		pos[i][0] = ox,pos[i][1] = oy;		
		Board[newx][newy] = false;
		Board[ox][oy] = true;
		n_matched = oldm;
	}
}



int main(){
	int Tr,a;
	scanf("%d",&Tr);	
	REP(t,Tr){		
		for(int i=0;i<4;i++){
		 	int a,b;
		 	scanf("%d",&a);assert(a>=1 && a<=8);
		 	scanf("%d",&b);assert(b>=1 && b<=8);
		 	pos[i][0] = a-1;
		 	pos[i][1] = b-1;
		}
		
		for(int i=0;i<4;i++){
		 	int a,b;
		 	scanf("%d",&a);assert(a>=1 && a<=8);
		 	scanf("%d",&b);assert(b>=1 && b<=8);
		 	T[i][0] = a-1;
		 	T[i][1] = b-1;
		 	assert(a>=1 && a<=8);
		 	assert(b>=1 && b<=8);
		}
		REP(i,(1<<24)) Seen[i] = (100);
		REP(i,8) REP(j,8) Board[i][j] = Tboard[i][j] = false;
				
		REP(i,4) Board[pos[i][0]][pos[i][1]] = true;
		REP(i,4) Tboard[T[i][0]][T[i][1]] = true;		
		n_matched = 4;
		REP(i,4) if(Tboard[pos[i][0]][pos[i][1]]) n_matched--;		
		try{
			go(0);
			printf("NO\n");
		}catch(int){	printf("YES\n");}
		
	}
	
	return 0;
}

