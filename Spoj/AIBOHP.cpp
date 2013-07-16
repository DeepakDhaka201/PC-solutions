#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<N;i++)
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i!=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;
typedef short int M;
const int X = 6101;
char str[X];
M vis[X][X];
M memo[X][X],N,cc = 10;


#define INF (1<<30)

M go(M a,M b){
	if(a>=b) return 0;
	if(vis[a][b] == cc) return memo[a][b];
	vis[a][b] = cc;
	if(str[a]==str[b]) return memo[a][b] = go(a+1,b-1);
	return memo[a][b] = (1 + (go(a+1,b) <? go(a,b-1) ));
}

int main(){
	int T = GI;
	char c;
	getchar();
	REP(t,T){
		cc += 10,N = 0;
		while(!feof(stdin) && (c=getchar())!='\n') str[N++] = c;
		str[N] = '\0';
		M x = go(0,N-1);
		cout << x << endl;
	}		
}
