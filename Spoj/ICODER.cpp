#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <math.h>
#include <map>
using namespace std;

#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.sz);++i)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin()); it != mp.end() ; ++it )
#define FOR(i,a,b) for(int i=(a);i<=(b); ++i )
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int main(){
	int N,a;
	char str[8];
	/*
	set<int> S;
	FOR(x,0,65536){
		int v = (x*6)%65536;
		S.insert( v );		
	}
	cout << S.sz << endl;
	exit(0);
	*/
	while( true ){
		int N = GI;
		if(!N) break;
		LL mul = 1 , add = 0;
		REP(i,N) {
			scanf("%s %d",str,&a);assert( a>=0 && a<= 65536 );
			if( str[0] == 'A' ) add +=a;
			else if ( str[0] == 'M' ) mul *=a, add *=a;
			mul %= 65536;
			add %= 65536;
		}
		set<int> S;
		for(LL x=0;x<=65536;++x) S.insert( ((x*mul)%65536 + add)%65536 );
		printf("%d\n",S.sz);
	}
}