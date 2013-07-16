#include <iostream>
#include <map>
#include <cstdio>
#include <bitset>

using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i=0;i < (N) ; ++i )
typedef long long int LL;
typedef pair<int,int> PII;

LL bits[64],ans;
map< pair< PII , LL > , bool > mp;

inline const int Cnt(LL p){
	int x = 0;
	while( p ) p &= (p-1) , x++;
	return x;
}

void go(int i,int r,LL bit,LL sel){
	if( r > Cnt( bit ) || i == 40) return;
	if( mp.count( make_pair(PII(i,r),bit) ) ) return;
	mp[ make_pair(PII(i,r),bit) ] = true;	
	ans >?= r;
	go( i+1 , r+1 , bit&bits[i] , sel | (1<<i) );
	go( i+1 , r , bit , sel );
}

int main(){
	int T = GI;
	for(int tt = 1;tt <= T;++tt){
		int M = GI;	
		mp.clear();
		REP(i,64) bits[i] = 0;
		REP(i,M){
			int a = GI-1, b = GI-1;
			bits[a] |= (1LL<<b);
		}
		ans = 0;
		
		go(0,0,(1LL<<50)-1,0);
		cout << ans << endl;
	}
}
