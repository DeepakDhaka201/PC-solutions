#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

VI nos;
int N,nR,a,b;

void add(int& rem,int x,int y){
	int sub = ( rem <? nR );
	rem -= sub;
	a = a + x*sub;
	b = b + y*sub;
}

int main(){
	nos.pb( 1 );
	while( nos.back() < 1000000 ) nos.pb( nos.back() + (nos.sz)*6 );
	
	while( scanf("%d",&N) == 1 ){
		REPV(i,nos) if( N <= nos[i] ) { nR = i;break;}
		
		int rem = nos[nR] - N;
		a = nR , b = 0;
		
		add( rem , 0 , -1 );
		add( rem , -1 , 0 );
		add( rem , -1 , 1 );
		add( rem , 0 , 1 );
		add( rem , 1 , 0 );
		add( rem , 1 , -1 );
		printf("%d %d\n",a,b);
		
	}
	return 0;
}





