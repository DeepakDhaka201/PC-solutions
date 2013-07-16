#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<28)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;


#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );

map<string,int> mp;
int Dist[64][64];

int main(){
	int N,R;
	int cc = 1;
	while((N=GI) + (R=GI)){		
		int cnt = 0;
		mp.clear();		
		set<string> S;
		REP(i,64) REP(j,64) Dist[i][j] = INF;
		REP(i,64) Dist[i][i] = 0;
		REP(i,R){
			string a,b;
			cin >> a >> b;
			if( S.find(a) == S.end()) mp[a] = cnt++,S.insert(a);
			if( S.find(b) == S.end()) mp[b] = cnt++,S.insert(b);
			Dist[mp[a]][mp[b]] <?= 1;
			Dist[mp[b]][mp[a]] <?= 1;
		}
		int ret = 0;
		REP(k,N) REP(i,N) REP(j,N) Dist[i][j] <?= Dist[i][k] + Dist[k][j];
		REP(i,N) REP(j,N) ret >?= Dist[i][j];		
		if( ret == INF ) cout << "Network "<< cc <<": DISCONNECTED" << endl;
		else cout << "Network "<< cc <<": "<< ret << endl;
		cout << endl;
		cc++;			
	}
}


