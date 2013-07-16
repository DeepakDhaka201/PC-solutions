#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!= mp.end();it++)
#define pb push_back
#define mkp make_pair
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
using namespace std;
typedef pair<int,int> PII;
typedef vector<short int> VI;
typedef vector<string> VS;
typedef long long int LL;
#define MN 310
char map[MN][MN];
int cost[MN][MN],K,R,C;

#define COST(i,j,k1,k2) (cost[j][k2] - cost[i-1][k2] - cost[j][k1-1] + cost[i-1][k1-1])

int main(){
	int T = 0;
	while((R=GI)+(C=GI)+(K=GI)){
		getchar();
		for(int x=1; x<=R; ++x) {
			for(int y=1;y<=C; ++y)
				cost[x][y] = (getchar() == '.') + cost[x][y-1] + cost[x-1][y] - cost[x-1][y-1];
			getchar();
		}			
		assert( ++T < 50 );
		int ans = INT_MAX;
		for(int i = 1;i <= R; ++i) for(int j = i; j <= R; ++j ) if( COST(i,j,0,C) >= K ) {
			int f = 1;
			for(int k = 1;k <= C; ++k ){
				while( f <= k && COST(i,j,f,k) >= K ){
					ans <?= (j-i+1)*(k-f+1);
					if( ans == K ) goto bad;
					f++;
				}
			}
		}
		bad:
		printf("%d\n",ans);
	}
	return  0;
}



