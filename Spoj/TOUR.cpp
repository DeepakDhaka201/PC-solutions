#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,a) for(int i=0;i<a.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define sz size()
#define INF (1<<28)
#define LINF ((int) 1e18)
#define GI ({int t;scanf("%d",&t);t;})
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;

VI Gr[1001];
VI Rev[1001];
int MainSeen[1001];
int Seen[1001],Seenid = 1;
int bfs(int Source,VI V[]){
	int cnt = 0;
	Seenid++;
	
	queue<int> Q;
	Q.push(Source);
	
	while( Q.sz ){
		int v = Q.front();Q.pop();		
		if(Seen[v] == Seenid) continue;Seen[v] = Seenid;MainSeen[v] = 1;
		cnt++;
		REPV(i,V[v]) Q.push(V[v][i]);	
	}
	return cnt;
}

int main(){
	int T = GI;
	REP(t,T){
		REP(i,1001) Gr[i].clear(),Rev[i].clear(),MainSeen[i] = 0;	
		int N = GI;
		REP(i,N){
			int R = GI;
			REP(j,R){
				int a = GI-1;
				Gr[a].pb(i);
				Rev[i].pb(a);
			}
		}
		
		int t = -1,cnt = 0;

		REP(i,N) if(!MainSeen[i] && bfs(i,Gr)==N){ t = i;break;}		
		if(t>-1) cnt = bfs(t,Rev);
		cout << cnt << endl;
	}
	return 0;
}


