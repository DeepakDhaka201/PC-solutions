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
#define EACH(it,mp) for(_typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<30)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
#define sz size()
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;

int Seen[50*50*50*50+1];
int c[4],Tar[4],N;
int CAP[4];


inline int Encode(){
	int ret = 0;
	REP(i,N) ret = ret*50 + c[i];
	assert(ret<=50*50*50*50);
	return ret;
}
inline int Decode(int ret){
	REP(i,N) c[N-1-i] = ret%50,ret /= 50;
}

inline bool done(){
	REP(i,N) if(c[i] != Tar[i]) return false;
	return true;
}

#define DO x = Encode();if(Seen[x]==-1){ Seen[x] = step+1,Q.push(x);}
void print(){
	REP(i,N) cout << c[i] <<" ";
	cout << endl;
}

int main(){
	int T = GI,ox,oy;
	
	while( T-- ){
		N = GI;
		REP(i,N) CAP[i] = c[i] = GI;
		REP(i,N) Tar[i] = GI;
		
		int y = Encode();
		queue<int> Q;
		
		memset(Seen,-1,sizeof(Seen));
		
		Q.push(y);
		Seen[y] = 0;
		int f = INF,x;
		
		while( Q.sz ){
			int ret = Q.front();Q.pop();
			int step = Seen[ret];
			Decode(ret);
			if(done()){ f = step;break;}
			
			REP(i,N) FOR(j,-1,N-1) if(i!=j){
					ox = c[i];
					if(j==-1){
						c[i] = 0;
						DO;
	      				c[i] = ox;
					}
					else if(c[i]>0){
						oy = c[j];
						if(CAP[j]-c[j]>c[i]) c[j] += c[i],c[i] = 0;
						else c[i] -= CAP[j]-c[j],c[j] = CAP[j];
						
						DO;
						c[i] = ox,c[j] = oy;
					}

			}
			
		}
		if( f == INF ) cout << "NO" << endl;
		else cout << f << endl;
		
		
	}
	return 0;
}


