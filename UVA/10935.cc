/*
	ACC	
*/
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
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,int> PII;

int main(){
	int N;
	while( (N=GI) ){
		deque<int> V;
		FOR(i,1,N) V.pb( i );
		
		printf("Discarded cards:");
		int p = 0;
		int disc = 1;
		while( V.sz > 1 ){
			int a = V[0];
			V.pop_front();
			if( disc ) printf("%s %d",p?",":"",a);
			else V.pb( a );			
			disc = (disc+1)%2;
			p = 1;
		}
		printf("\nRemaining card: %d\n",V[0]);
	}
	return 0;
}

