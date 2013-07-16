#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<28)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,int> PII;

struct sq{
	int Z,flag;
	int lx,ly,hx,hy;	
	sq(int a,int b,int c,int d,int e,int f):lx(a),ly(b),hx(c),hy(d),Z(e),flag(f){}
};
bool operator<(const sq& a,const sq& b){
	return a.Z < b.Z;
}
int Ar[2048][2048];

int main(){
	int T = GI;
	while( T-- ){
		int N = GI;
		vector<sq> V;
		set<int> SX,SY;
		REP(i,N){
			int x = GI+1000,y = GI+1000,z = GI+1000,r = GI;
			V.pb( sq(x-r,y-r,x+r,y+r, z-r ,1 ) );
			V.pb( sq(x-r,y-r,x+r,y+r, z+r ,0 ) );
			SX.insert( x-r );SX.insert( x+r );
			SY.insert( y-r );SY.insert( y+r );
		}
		sor(V);
		vector<int> X(SX.begin(),SX.end());
		vector<int> Y(SY.begin(),SY.end());
		
		int Vol = 0;
		int xy = 0,prevZ = 0;
		int markedX[2048] = {};
				
		REPV(i,V){
			sq r = V[i];
			Vol += xy*(r.Z - prevZ);
			prevZ = r.Z;
			
			if( r.flag ){
				markedX[r.lx] += 1;markedX[r.hx] += 1;
				Ar[r.lx][r.ly] += 1;Ar[r.lx][r.hy] -= 1;
				Ar[r.hx][r.ly] -= 1;Ar[r.hx][r.hy] += 1;
			}
			else{
				markedX[r.lx] -= 1;markedX[r.hx] -= 1;
				Ar[r.lx][r.ly] -= 1;Ar[r.lx][r.hy] += 1;
				Ar[r.hx][r.ly] += 1;Ar[r.hx][r.hy] -= 1;
			}
			
			int markedY[2048] = {};
			xy = 0;
			int prevX = 0,len = 0;
			
			REPV(i,X) if( markedX[ X[i] ] ){
				xy += len*(X[i] - prevX);
				prevX = X[i];
				len = 0;
				int prevY = 0,cnt = 0;				
				/* Can put this in the next loop */
				REPV(j,Y) markedY[Y[j]] += Ar[X[i]][Y[j]];
				
				REPV(j,Y){
					if(cnt) len += Y[j] - prevY;
					prevY = Y[j];
					cnt += markedY[Y[j]];
				}				
			}
		}
		cout << Vol << endl;
	}
	return 0;
}
