#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
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
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;
VI Gr[3002];
int Seen[3002][3002][2];
int Moves[3002][3002][2];
#define SEEING 1
#define WIN 2
#define LOSE 3
int dep = 0;
int go(int a,int b,int f){
	//if (f) a plays else b plays	
	if(Seen[a][b][f]) return Seen[a][b][f];
	dep += 1;
	REP(i,dep) cout << " ";
	cout << a <<" "<< b << " "<< f << endl;
	getchar();	

	Moves[a][b][f] = 0;
	if( a == b ){ dep -=2;return Seen[a][b][f] = (f?LOSE:WIN);}
	Seen[a][b][f] = SEEING;
	int fl = 0,ch,a1 = 0,b1 = INF;
	if(f){
		REPV(i,Gr[a]) if(Seen[Gr[a][i]][b][0]==SEEING || go(Gr[a][i],b,0) == LOSE){
				fl = 1;				
				b1 <?= Moves[Gr[a][i]][b][0];
			}
			else a1 >?= Moves[Gr[a][i]][b][0];
	}
	else{		
		REPV(i,Gr[b]) if(Seen[a][Gr[b][i]][1] != SEEING && go(a,Gr[b][i],1) == LOSE){ 
			fl = 1;
			b1 <?= Moves[a][Gr[b][i]][1];
		}
		else a1 >?= Moves[a][Gr[b][i]][1];
	}
	ch = (fl?b1:a1);	
	Moves[a][b][f] = ch+1;
	dep -= 2;	
	return Seen[a][b][f] = (fl?WIN:LOSE);
}

int main(){
	int T = GI;
	while( T-- ){
		int N = GI,M = GI,A = GI,B = GI;
		REP(i,3001) Gr[i].clear();
		memset(Seen,0,sizeof(Seen));
		
		REP(i,M){
			int a = GI,b = GI;
			Gr[a].pb(b);
			Gr[b].pb(a);	
		}

		int f = go(A,B,0);
		if(f) cout << Moves[A][B][0] << endl;
		else cout <<"No" << endl;
	}
	return 0;
}
