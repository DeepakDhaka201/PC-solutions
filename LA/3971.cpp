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
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

vector<PII> V[1024];
map<string,int> mp;
int nodes = 0;

int id(string s){
	if( mp.count( s ) ) return mp[ s ];
	return mp[ s ] = nodes++;
}

int main(){
	int T = GI;
	while( T-- ){
		mp.clear();
		nodes = 0;
		int N = GI,Kasu = GI;
		string a,b;int x,y;
		
		REP(i,N) V[i].clear();
		REP(i,N){
			cin >> a >> b >> x >> y;
			V[id(a)].pb(PII(x,y));
		}
		
		double lo = 0,hi = 1e9+1;
		int ans = -1;
		
		REP(i,50){
			double mid = (hi+lo)/2;
			LL cost = 0;
			EACH(it,mp){
				int lo = INF;
				EACH(it1,V[it->second]) if( it1->second >= mid ) lo <?= it1->first;
				cost += lo;
			}
			if( cost > Kasu) hi = mid;
			else lo = mid;
		}
		printf("%d\n",int(hi));
	}
	return 0;
}