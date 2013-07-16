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

int Carea[16],Sums[1<<11],Cbits[32];
int Cap[32],N,R,M,Seen[32],MAX;
VI ans;

void go(int n,int r){	
	if( !r ){		
		int r = 0,b = 0;VI tmp;
		REP(i,N) if( Seen[i] ) r += Cap[i],b |= Cbits[i],tmp.pb( i );
		r += Sums[b];		
		if( r > MAX ) MAX = r, ans = tmp;
		return;
	}
	if( n >= N ) return;
	Seen[n] = 1;go( n+1 , r-1 );
	Seen[n] = 0;go( n+1, r );	
}

int main(){
	int T = 1;
	while((N=GI)+(R=GI)){		
		REP(i,N) Cap[i] = GI,Cbits[i] = 0;
		M = GI;
		REP(i,M){
			int p = GI,bit = 0;
			REP(j,p){
				int a = GI-1;
				Cbits[a] |= (1<<i),bit |= (1<<a);
			}
			Carea[i] = GI;
			REP(j,N) if( bit & (1<<j) ) Cap[j] -= Carea[i];
		}		
		REP(b,(1<<M)){
			Sums[b] = 0;
			REP(j,M) if( b & (1<<j) ) Sums[b] += Carea[j];				
		}
			
		MAX = -1;
		go(0,R);		
		printf("Case Number  %d\n",T++);
		printf("Number of Customers: %d\n",MAX);
		printf("Locations recommended:");REPV(i,ans) printf(" %d",ans[i]+1);
		puts("\n");
	}
	return 0;
}