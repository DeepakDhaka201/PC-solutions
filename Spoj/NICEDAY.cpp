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
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define GI ({int y;scanf("%d",&y);y;})
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;

vector<PIII> V;

int main(){
	int T = GI;
	REP(tt,T){
		int N = GI;
		V.clear();
		REP(i,N){
			int a = GI,b = GI,c = GI;
			V.pb( PIII( PII(c,a) ,b) );
		}
		sor(V);
		
		set<PIII> S;				
		REPV(i,V){
			int z = V[i].first.first,x = V[i].first.second,y = V[i].second;
			S.insert(PIII( PII(x,y),z ) );
			
			int f = 1;
			while( f ){
				f = 0;
				set<PIII>::iterator it = S.find( PIII(PII(x,y),z) );	
				if( it != S.begin() ){
					it--;
					if( it->first.first <= x && it->first.second <= y && it->second <= z ) S.erase(it),f = 1;
				}
			}
		}
		cout << S.sz << endl;
	}
	return 0;
}