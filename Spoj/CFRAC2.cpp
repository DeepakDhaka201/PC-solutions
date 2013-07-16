#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <cassert>
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
typedef vector<int> VI;
typedef vector<string> VS;

char c;
int N,M;	

int main(){
	while((N=GI)){
		int M = GI;
		vector<LL> V;
		getchar();getchar();
		REP(i,N){
			LL r = 0;
			if(i%2){
				REP(j,M+2){
					c = getchar();				
					if( c >='0' && c<='9') r = r*10 + (c-'0');
				}
				V.pb( r );
			}
			else while(1){ c = getchar();if( c == '\n') break;}			
		}
		LL n = 1,d = 1;
		for(int i = V.sz-1;i>=0;i--){
			LL _d = d*V[i] + n,_n = d;
			n = _n,d = _d;
		}
		swap(n,d);
		cout << n <<" "<< d << endl;
	}
}
