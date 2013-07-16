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
#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );
typedef long long int LL;
typedef pair<int,int> PII;
#define SZ 1024
int Sums[SZ][SZ];
int Ar[SZ][SZ];
int ASums[SZ][SZ];
int BSums[SZ][SZ];
int N,M,A,B,D,C;

#define ok(a,b) (a>=1 && a<N && b>=1 && b<M)
#define ok1(a,b) ((a)>=1 && (a)<=N && (b)>=1 && (b)<=M)
inline int getSum(int a,int b,int c,int d){
	return Sums[c][d] - Sums[c][b-1] - Sums[a-1][d]	+ Sums[a-1][b-1];
}
inline int getCD(int a,int b){
	return getSum(a,b,a+C-1,b+D-1);	
}

void print(int ar[SZ][SZ]){
	FOR(i,1,N){
		 FOR(j,1,M) printf("%5d ",ar[i][j]);
		 cout << endl;
	}
	cout <<"================== "<< endl;
}
int main(){
	int T = GI;
	REP(t,T){
		N = GI,M = GI,A = GI,B = GI,C = GI,D = GI;		

		FOR(i,1,N) FOR(j,1,M){
			Ar[i][j] = ((j == 1) ? GI: 1+(Ar[i][j-1]*71+17)%100);
			Sums[i][j] = Sums[i-1][j] + Sums[i][j-1] - Sums[i-1][j-1] + Ar[i][j];
		}
		
		for(int i=1;i<=N-1 && i+C-1<N;i++){
			deque<PII> V;
			for(int j=M-D;j>=1;j--){
				while(V.size() && getCD(V.back().first,V.back().second)>=getCD(i,j)) V.pop_back();
				V.pb(PII(i,j));
				int r = V.front().first,c = V.front().second;
				ASums[i][j] = getCD(r,c);
				if(c-j+1==B-D-1) V.pop_front();
			}		
		}
		int ret = -1,la,lb;
		
		for(int j=1;j<=M-1 && j+D-1<M;j++){
			deque<PII> V;
			for(int i=N-C;i>=1;i--){
				int val = ASums[i][j];
				while(V.size() && ASums[V.back().first][V.back().second]>=val) V.pop_back();
				V.pb(PII(i,j));				
				int r = V.front().first,c = V.front().second;
				BSums[i][j] = ASums[r][c];
				if(ok1(i-1+A-1,j-1+B-1) && ok1(i-1,j-1)) 
						ret >?= getSum(i-1,j-1,i-1+A-1,j-1+B-1) - BSums[i][j];
				if(r-i+1==A-C-1) V.pop_front();
			}
		}
		cout << ret << endl;		
	}
}
