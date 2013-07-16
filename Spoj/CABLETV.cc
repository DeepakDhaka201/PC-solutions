#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<28)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;


int Cap[64][64],N,M;
int Source,Sink;


bool find_path(){
	int par[64];
	memset(par,-1,sizeof(par));
	
	queue<int> Q;
	Q.push(Source);
	par[Source] = -2;
	while( Q.sz ){
		int v = Q.front();Q.pop();
		if( v == Sink ) break;
		REP(i,64) if( par[i] == -1 && Cap[v][i] > 0 ){
			par[i] = v;
			Q.push( i );
		}
	}
	int back = Sink;
	for( int prev = par[back];prev >= 0; back = prev,prev = par[prev])
		Cap[prev][back] -= 1,Cap[back][prev] += 1;
	
	return par[Sink] != -1;
}

int main(){
	int T = GI;
	while( T-- ){
		N = GI,M = GI;
		memset(Cap,0,sizeof(Cap));
		
		REP(i,M){
			char temp[100];
			int a,b;
			scanf("%s",temp);sscanf(temp,"(%d,%d)",&a,&b);
			Cap[a][b] = Cap[b][a] = 1;
		}
		
		int ret = N;
		//if( !M ) ret = 0;
		
		int temp[64][64];
		memcpy(temp,Cap,sizeof(temp));
		
		REP(i,N) FOR(j,i+1,N-1) if(Cap[i][j] == 0 ){
			Source = i,Sink = j;			
			int flow = 0;			
			while( find_path() ) flow++;			
			ret <?= flow;					
			memcpy(Cap,temp,sizeof(temp));
		}
		cout << (ret==INF?N:ret) << endl;
	}
}

