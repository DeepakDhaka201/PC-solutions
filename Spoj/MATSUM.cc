#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(_typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI GETNUM()
#define INF (1<<30)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;

int dp[1024][1024];
int mat[1024][1024];
#define IN getchar_unlocked()

void print(int N){
	REP(i,N){
		REP(j,N) cout << dp[i][j] <<" ";
		cout << endl;
	}	
}


#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
int
i ;
 
ITYPE
j ;
 
i = GETCHAR () ;
while ( ! DIG( i ) )
i = GETCHAR () ;
 
j = ( i - '0' ) ;
 
i = GETCHAR () ;
while ( DIG( i ) )
{
j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
i = GETCHAR () ;
}
return ( j ) ;
} 

int main(){
	int T = GI;
	char c;
	
	REP(t,T){		
		memset(dp,0,sizeof(dp));
		memset(mat,0,sizeof(mat));
		int N = GI;
		while(true){
			while((c=IN)<='A');			
			if(c=='E'){ REP(i,2) IN;break;}
			if((c=IN)=='E'){
				IN;
				int a = GI,b = GI,c = GI;				
				mat[a][b] = c;
				for(int i=b;i<N;i++) dp[a][i] = (i>0?dp[a][(i-1)]:0) + mat[a][i];
			}
			else{
				IN;
				int a = GI,b = GI,c = GI,d = GI,ret = 0;				
				FOR(i,a,c) ret += dp[i][d] - (b>0?dp[i][(b-1)]:0);
				printf("%d\n",ret);
			}
		}
	}
}
