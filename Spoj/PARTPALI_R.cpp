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


int Ar[2][1024];
int POW[32],S,MOD;


int main(){
	int T = GI;
	while( T-- ){
		MOD = GI;S = GI;
		memset(Ar,0,sizeof(Ar));
		POW[0] = 1;
		FOR(i,1,31) POW[i] = (POW[i-1]*10)%MOD;
		
		int c = 0,next = 1,st;
		if( S%2 ) FOR(n,1,9) Ar[c][n%MOD]++;
		else FOR(n,1,9) Ar[c][(n*10+n)%MOD]++;
		
		if( S > 2 ){
			Ar[c][0]++;			
			for(int i=(S%2?1:2);i<S;i+=2){
				memset(&Ar[next],0,sizeof(Ar[next]));
				if( i == S-2 ) st = 1;else st = 0;
				
				FOR(n,st,9) REP(m,MOD){
					int nm = (n*POW[i+1] + m*10  + n)%MOD;
					Ar[next][nm] += Ar[c][m];
				}
				swap(next,c);
			}
		}
		cout << Ar[next][0] << endl;
	}
}