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
typedef long long int LL;
typedef pair<int,int> PII;
//#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );

inline int GI(){int t;scanf("%d",&t);return t;}

vector< long long int > K;
LL Mat[101][101];
LL Res[101][101];
LL RESULT[101][101];
long long int N;
long long int X,MOD = 123456789LL;

void Mult(const LL a[101][101],const LL b[101][101]){	
	REP(i,N) REP(j,N){
		 RESULT[i][j] = 0 ;
		 REP(k,N){
			RESULT[i][j] = (RESULT[i][j]+(a[i][k]%MOD*b[k][j]%MOD)%MOD)%MOD;
		}
	}
}

int sub();
int main(){
	int T = GI();
	while(T--){
		K.clear();
		memset(Res,0,sizeof(Res));
		memset(Mat,0,sizeof(Mat));
		sub();		
	}	
}

int sub(){
	long long int nn;	
	cin >> nn;
	cin >> N;
	
	REP(i,N) Mat[i][0] = GI();
	REP(i,N) Mat[i][i+1] = 1;
	REP(i,101) Res[i][i] = 1;
	REP(i,N) K.pb( GI());
	rev(K);
	X = nn - N;
	if( X<= 0 ){
		cout << K[X+N-1] << endl;
		return 0;
	}
	VI bits;	
	while(X){
		bits.pb(X%2);
		X/=2;	
	}
	//cout << " MAT : "<< endl;
	//print(Mat);
	//cout <<" ------- " << endl;
	rev(bits);
	REPV(i,bits){
		Mult(Res,Res);
		memcpy(Res,RESULT,sizeof(RESULT));
		if(bits[i]){
			 Mult(Res,Mat);
			 memcpy(Res,RESULT,sizeof(RESULT));
		}
	}
	LL ans = 0;
	REP(i,N) ans = (ans + K[i]*Res[i][0])%MOD;
	cout << ans << endl;
}
