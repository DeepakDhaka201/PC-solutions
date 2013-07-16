#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <sstream>
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
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

vector<VI> Tree;
int Size = int(8),Canmove[32][32],Ht;
char src[100002],targ[100002],temp[4];
deque<int> Pos[27];

void clear(){
	memset(Canmove,0,sizeof(Canmove));
	Tree.clear();
	REP(i,27) Pos[i].clear();
	Ht = 0;
	for( int t = 1; t <= Size ; t *= 2 ) Tree.pb( VI(t,0) ),Ht++;	
}

void Add(int x,int f){
	int t = x;
	REP(i,Ht){
		Tree[Ht-1-i][t] += f;
		t /= 2;
	}
}

int Calc(int x){
	int ret = 0,j = 0;
	REP(i,Ht-1){
		int m = x & (1<<(Ht-2-i));
		if( m ) ret += Tree[i+1][2*j];
		j = j*2 + !!m;
	}
	return ret + Tree[Ht-1][x];	
}

int main(){
	int T = GI;
	while( T-- ){
		clear();
		scanf("%s",src);scanf("%s",targ);
		int N = GI;
		REP(i,N){
			scanf("%s",temp);
			Canmove[temp[1]-'a'][temp[0]-'a'] = 1;
			Canmove[temp[0]-'a'][temp[1]-'a'] = 1;
		}
		for(int i=0;src[i];i++) Pos[src[i]-'a'].pb( i );
		
		int f = 0;
		unsigned int ret = 0;
		for(int i=0;targ[i];i++){
			char c = targ[i] - 'a';
			if( !Pos[c].sz ){ 
				f = 1;
				break;
			}			
			int fpos = Pos[c].front();
			Pos[c].pop_front();
			
			REP(cdash,26) if( !Canmove[c][cdash] && Pos[cdash].sz )	 if( Pos[cdash].front() < fpos ){
			 	f = 1;
			 	break;
			 }
			ret += ( unsigned int ) (fpos - Calc( fpos ));
			Add( fpos , 1 );
		}
		printf("%lld\n",f?-1LL:LL(ret));
		
	}
	return 0;
}


