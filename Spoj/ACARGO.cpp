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
#define FOR(i,a,b) for(int i=(a);i<=(b); ++i )
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin()); it != mp.end() ; ++it )
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define LINF ((LL)1e18)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int N,L;
VI V;
LL Sums[200001];
LL getCost(int a,int b){
	
	if( b > a ){
		LL n = b-a;
		LL t1 = (Sums[b] - Sums[a]) - n*V[a] - n*(n+1)/2;		
		LL n1 = a;
		LL n2 = (N-1) - b;
		LL t2 = (n1*V[a] - (Sums[a] - V[a]));
		t2 += (L-V[b] + V[a])*n2 - (Sums[N-1] - Sums[b] - n2*V[b]);
		t2 -= (n1+n2)*(n1+n2+1)/2;
		return t1 + t2;
	}
	else if( a < b ){
		swap(a,b);
		return getCost(a,b);
	}
	else return LINF;
}
int next( int x ){
	x++;
	if( x == N ) x = 0;
	return x;
}

int main(){
	while( (N=GI) + (L=GI) ){
		
		V.clear();
		memset(Sums,0,sizeof(Sums));
		REP(i,N) V.pb( GI );
		sort(V.begin(),V.end());
		REPV(i,V){
			if( i ) Sums[i] = Sums[i-1] + V[i];
			else Sums[i] = V[i];
		}
		if( N == 1 ){
			cout << 0 << endl;
			continue;
		}
		
		LL cost = LINF,temp;
		REP(start,N){
			int end = next(start);
			
			if( (temp=getCost(start,end)) < ct){
				ct= temp;
				while( (temp=getCost( start , next(end) )) < ct){
					ct = temp,end = next(end); 
				}
			}			
			cost <?= ct;
		}
		cout << cost << endl;
	}
}