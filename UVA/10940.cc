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
		int start = 1,d = 1,n = N;
		int inhand = 0;
		while( n > 1 ){
			if( !inhand ) start = start + d;
			d *= 2;
			int a = 0;
			if( n%2 != inhand ) a = 1;		
			n = n/2 + (inhand?n%2:0);
			inhand = a;
		}
		if( inhand && start + d <= N ) start += d;
		printf("%d\n",start);
	}
	return 0;
}

