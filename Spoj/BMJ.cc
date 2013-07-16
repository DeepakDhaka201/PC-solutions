#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cassert>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>


#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define mkp(a,b) make_pair((a),(b))
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

VI nos;

int main(){
	nos.pb( 1 );
	while( nos.back() < 1000000 ) nos.pb( nos.back() + (nos.sz)*6 + 1 );
	int N;
	while((N=GI)){
		int nR = 0;
		REPV(i,nos) if( N <= nos[i] ){ nR = i;break;}
		cout <<" nR = "<< nR <<" nos[nR] = "<< nos[nR] << endl;
		int rem = nos[nR] - N;
		int x = 0,y = 0,a = x + nR, b = 0 ;
		
		int sub = ( rem <? nR );
		rem -= sub;
		b -= sub;

		sub = ( rem <? nR );
		rem -= sub;
		a -= sub;

		sub = ( rem <? nR );
		rem -= sub;
		a -= sub;
		b += sub;
		
		sub = ( rem <? nR );
		rem -= sub;
		b += sub;
		
		sub = ( rem <? nR );
		rem -= sub;
		a += sub;		
		
		sub = ( rem <? nR );
		rem -= sub;
		a += sub;
		b -= sub;		

		printf("%d %d\n",a,b);
	}
}
