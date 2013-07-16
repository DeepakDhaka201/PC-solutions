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


bool isLeap(int year ){
	if( !year ) return 1;
	if( year%400 == 0 ) return 1;
	if( year%100 == 0 ) return 0;
	return year%4 == 0;
}
int DAYS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	int T = GI;
	while( T-- ){
		int CC = GI;
		VI V;REP(i,3) V.pb( GI );
		VI ret;REP(i,3) ret.pb( INF );		
		sor(V);
		
		do{
			int year = CC*100 + V[0];
			int month = V[1];
			int day = V[2];
			int leap = isLeap(year);
			if( month > 12 || month < 1 || day < 1) continue;
			if( leap && month == 2 ){ if( day > 29 ) continue;}
			else if( day > DAYS[month-1] ) continue;
			if( V < ret ) ret = V;
		}while( next_permutation(V.begin(),V.end()) );
		if( ret[0] == INF ) printf("-1");
		else REP(i,3) printf("%s%02d",i?" ":"",ret[i]);
		printf("\n");
	}

}
