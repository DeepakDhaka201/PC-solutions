#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define GI ({int y;scanf("%d",&y);y;})
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

bool isp(int x){
	if( x == 1 || x == 0 ) return 0;
	if( x == 2 ) return 1;
	for(int i = 2;i*i <= x;i++) if( x%i == 0 ) return false;
	return true;	
}
int Nways[10000][4];

int go(int n,int k){
	if( n <= 0 ) return (n == 0);	
	int& ret = Nways[n][k];	
	if( ret != -1 ) return Nways[n][k];
	
	ret = 0;
	FOR(j,1,k) ret += go(n-j,j);
	return ret;
}

int main(){
	VI V;
	FOR(i,0,90) FOR(j,0,90) if(i<=j){
		int x = i*i + j*j;		
		if( isp(x) ) V.pb( x );		
	}
	sor(V);	
	int T = GI;
	memset(Nways,-1,sizeof(Nways));
	while( T-- ){
		int N = GI-1,K = GI;
		int no = V[N];		
		cout << go(no,K) << endl;
	}	
	return 0;
}