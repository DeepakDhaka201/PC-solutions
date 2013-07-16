#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
#define sq(a) ((a)*(a))
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
int Zc[256][256],N,M;
int CanSee[256][256],sa,sb,ea,eb;



bool can_see(int a,int b,int x,int y){
	double mag = sqrt( sq(a-x) + sq(b-y) + sq(Zc[a][b]-Zc[x][y]));
	
	
}

int Search();
void print(int ar[256][256]);
int main(){
	int T =  GI;
	FOR(t,1,T){
		N = GI,M = GI;
		REP(i,N) REP(j,M) Zc[i][j] = GI;
		sa = GI-1,sb = GI-1;
		ea = GI-1,eb = GI-1;
		REP(i,N) REP(j,M){
			if(i==sa && j==sb || i==ea && j==eb) CanSee[i][j] = 0;
			else CanSee[i][j] = can_see(i,j,sa,sb) | can_see(i,j,ea,eb);
		}
		int t = Search();
		
		if( t == -1) cout << "Mission impossible!" << endl;
		else cout <<" The Shortest Path is " << t <<" Steps long." << endl;
	}
	return 0;
}



#define ok(a,b) (a>=0 && b>=0 && a<N && b<M)
int Search(){
	int Seen[256][256];
	memset(Seen,-1,sizeof(Seen));
	
	Seen[sa][sb] = 0;
	queue<PII> Q;
	Q.push(PII(sa,sb));
	
	while( Q.sz ){
		int r = Q.front().first,c = Q.front().second;Q.pop();
		int ht = Zc[r][c];
		if(r==ea && c==eb) break;
		FOR(i,-1,1) FOR(j,-1,1) if(!i || !j){
			int x = r+i,y = c+j;
			if(!ok(x,y) || Seen[x][y]!=-1 || !CanSee[x][y]) continue;
			if(!(ht>=Zc[x][y] && ht-Zc[x][y]<=3 || Zc[x][y]>=ht && Zc[x][y]-ht<=1)) continue; 
			Q.push(PII(x,y));
			Seen[x][y] = Seen[ea][eb] + 1;
		}
		
	}
	return Seen[ea][eb];
}


void print(int x[256][256]){
	REP(i,N){REP(j,M) cout << x[i][j] <<" ";cout << endl;}	
}