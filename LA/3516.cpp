#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i,N) for(int i = 0;i < (N); ++i)
#define GI ({int t;scanf("%d",&t);t;})
typedef long long int LL;

int Memo[301][301],Seen[301][301],Seenid;
int MOD = int(1e9);
char Str[512];

int main(){
	while( scanf("%s",Str) == 1 ){
		int L = strlen(Str);
		memset(Memo,0,sizeof(Memo));
		
		for(int i = L-1; i >= 0; i-- ) for(int j = i; j < L; j+= 2) if( Str[i] == Str[j] ){
			int& r = Memo[i][j];
			if( j == i ) r = 1;

			for(int k = i+2;k <= j; k += 2 ) if( Str[k] == Str[j] && Str[k-1] == Str[i+1]){
				int x = Memo[i+1][k-1];
				int y = ( k < j ? Memo[k][j] : 1 );
				r += (1LL*x*y)%MOD; r %= MOD;
			}
		}		
		printf("%d\n",Memo[0][L-1]);
	}
	return 0;
}
