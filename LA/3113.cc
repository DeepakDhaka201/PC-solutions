#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>


#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<double,PII> PIII;
typedef vector<int> VI;
typedef vector<string> VS;

map<string,int> mp;
string a,b;double x;
int Col[10000];
vector<PIII> V;
int getCol(int x ){
	if( x == Col[x] ) return x;
	return Col[x] = getCol( Col[x] );
}

int main(){
	double l;
	while(cin >> l){
		int cnt = 0;
		int N = GI;mp.clear();V.clear();
		REP(i,N){
			cin >> a;
			mp[a] = ++cnt;
		}
		int M = GI;
		REP(i,N+2) Col[i] = i;
		REP(i,M){
			cin >> a >> b >> x;
			V.pb( PIII(x,PII(mp[a],mp[b])) );		
		}
		sor(V);
		double ret = 0;
		REPV(i,V){
			int r = V[i].second.first,c = V[i].second.second;
			int a = getCol(r), b = getCol(c);
			if( a != b ) Col[getCol(r)] = getCol(c),ret += V[i].first;			
		}
		if( ret < l) printf("Need %.1lf miles of cable\n",ret);
		else printf("Not enough cable\n");
	}
	return 0;
}
