#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i = 0;i < (N); ++i ) 
#define sz size()
#define pb push_back
#define SUM(a,b) ( (a) >= 0 && (b) >= 0 ? Sum[a][b] : 0 )

int main(){
	int R,C,K;
	int A[512][512],Sum[512][512];
	
	while( R=GI,C=GI,K=GI ){
		REP(i,R) REP(j,C) A[i][j] = GI;
		REP(i,R) REP(j,C) Sum[i][j] = SUM(i,j-1) + SUM(i-1,j) + SUM(i-1,j-1);
		
		REP(up,R) REP(down,R) if( down >= up ) REP(bar,C){
			int low = 0;
			while( RECT(up,low,down,bar) >= K ) low++, ans <?= ( down - up + 1 ) * ( bar - low + 1 );
		
		}
	}
	return 0;
}
