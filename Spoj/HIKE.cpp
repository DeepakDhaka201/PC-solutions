#include <iostream>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,a) for(int i=0;i<a.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define sz size()
#define INF (1<<28)
#define LINF ((int) 1e18)
#define GI ({int t;scanf("%d",&t);t;})
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
char ar[51][51];
char s[10];
int Cost[51][51][51];
VI V(3);
#define CH(a,b,c1,d) if(!Cost[a][b][c1]) Cost[a][b][c1] = d+1,Q.push(PIII(PII(a,b),c1));	
#define PER(a,b,c,d) CH(a,b,c,d);CH(a,c,b,d);CH(b,a,c,d);CH(b,c,a,d);CH(c,a,b,d);CH(c,b,a,d);

int main(){
	int N,a,b,c;
	while((N=GI)){
		a = GI-1,b = GI-1,c = GI-1;
		REP(i,N) REP(j,N) scanf("%s",s),ar[i][j] = s[0];
		int ret = INF;
		sor(V);
		REP(i,N) REP(j,N) REP(k,N) Cost[i][j][k] = 0;
		queue<PIII> Q;
		PER(a,b,c,0);
		int f = INF;
			
		while( Q.sz ){
			PIII p = Q.front();Q.pop();
			int x = p.first.first,y = p.first.second,z = p.second;
			int c = Cost[x][y][z];
				
			if( x==y && z==x){f = c;break;}				
				
			REP(i,N){
					if(ar[x][i] == ar[y][z]){PER(i,y,z,c);}
					if(ar[y][i] == ar[x][z]){PER(x,i,z,c);}
					if(ar[z][i] == ar[x][y]){PER(x,y,i,c);}
			}
		}
		ret <?= (f-1);

		if( ret >= INF-1 ) cout << "impossible" << endl;
		else cout << ret << endl;
	}	
}
