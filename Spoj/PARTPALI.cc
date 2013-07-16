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
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,int> PII;

int Ar[32][1024],M,Seen[32][1024],Seenid;
int POW[32],first;

int go(int s,int m){
	int& ret = Ar[s][m];
	if( Seen[s][m] == Seenid ) return ret;Seen[s][m] = Seenid;
	ret = 0;
	if(s == 1) FOR(n,first,9) ret += ( (n%M) == m );
	else if(s == 2) FOR(n,first,9) ret += ( (n*10 + n)%M == m);
	else
		FOR(n,first,9){
			 first = 0;
			 REP(mod,M) 
				if( (n*POW[s-1] + mod*10 + n)%M == m )	 ret += go(s-2,mod);
		}
	return ret;
}

int main(){
	int T = GI;
	while( T-- ){
		++Seenid;
		M = GI;int s = GI;
		POW[0] = 1;
		FOR(i,1,31) POW[i] = (POW[i-1]*10)%M;
		first = 1;
		cout << go(s,0) << endl;
	}
	return 0;
}
