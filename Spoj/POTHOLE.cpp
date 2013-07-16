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
#include <cassert>
#include <stdlib.h>
#include <list>

using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
#define GI ({int i;scanf("%d",&i);i;})
#define pb push_back
#define sz size()
#define INF (1<<28)
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();x++)
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define VI vector<int>
#define VS vector<string>

int Cost[256][256],Source,Sink;
int Seen[256],Par[256],f,Seenid = 1;

bool find_path(int N){
	
	memset(Par,-1,sizeof(Par));
	queue<int> Q;
	Q.push(Source);
	Par[Source] = -1,f = 0;
	
	while( Q.sz ){
		int v = Q.front();Q.pop();
		if( v == Sink ){ f = 1;break;}		
		if(Seen[v] == Seenid) continue;Seen[v] = Seenid;		
		FOR(i,1,N) if(Seen[i]!=Seenid && Cost[v][i]>0) Par[i] = v,Q.push(i);	
	}
	
	int back = Sink;
	while( Par[back]>-1 ){
		Cost[back][Par[back]]++;
		Cost[Par[back]][back]--;
		back = Par[back];			
	}
	return f;
}

int main(){
	int T = GI;
	while( T-- ){
		int N = GI;
		memset(Cost,0,sizeof(Cost));
		FOR(i,1,N-1){
			for(int j=GI;j>=0;j--){
				int c = GI;
				Cost[i][c] = ((i==1||c==N)?1:10000);
			}
		}
		
		Source = 1,Sink = N;
		int t,ret = 0;
		while(find_path(N)) ret++;
		cout << ret << endl;
	}	
}
