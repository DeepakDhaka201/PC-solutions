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


LL Ar[32][1024];
LL POW[32],S,MOD;


int main(){
	int T = GI;
	while( T-- ){
		MOD = GI;S = GI;
		memset(Ar,0,sizeof(Ar));
		POW[0] = 1;
		FOR(i,1,31) POW[i] = (POW[i-1]*10)%MOD;
		
		FOR(n,1,9) Ar[1][n%MOD]++;
		FOR(n,1,9) Ar[2][(n*10+n)%MOD]++;
		
		if( S > 2 ){
			Ar[1][0]++;Ar[2][0]++;
			int st = (S%2?1:2);
			
			for(;st < S;st += 2 ) {
				REP(m,MOD) if(Ar[st][m]) FOR(n,( (st+2==S)?1:0),9){
						int nm = (n*POW[st+1] + m*10 + n)%MOD;
						assert(nm>=0);
						Ar[st+2][nm] += Ar[st][m];						
				}
			}			
		}
		cout << Ar[S][0] << endl;
	}
}