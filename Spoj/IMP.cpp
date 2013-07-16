#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>


#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define VS vector<string>
#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );
typedef long long int LL;
using namespace std;
typedef pair<int,int> PII;

PII operator-(PII a,PII b){
	return PII(a.first-b.first,a.second-b.second);	
}
double D(PII a){return hypot(a.first,a.second);}
	
int main(){
	int T = 10;
	while( T-- ){
		int a = GI,b = GI,c = GI,d = GI;
		PII X(a,b);
		PII Y(c,d);
		if( D(X) > D(Y) ) swap(X,Y);		
		while( D(Y)-D(X)>1e-3 ){
			PII p = Y-X;
			if( D(Y) - D(p)>1e-6 ){
				 if( D(X)-D(p) > 1e-6){
					Y = X;
					X = p;		
				 }
				 else Y= p;		
			}
			else break;
		}
		printf("%d\n",abs(X.first)+abs(X.second));
	}	
}
