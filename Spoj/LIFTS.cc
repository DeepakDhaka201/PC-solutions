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


struct Lift{
	int l,u,s,d;
	Lift(int a,int b,int c,int d1){l = a;u = b;s = c;d = d1;}
	void Move(){
		s += d;
		if( s > u ) s = u-1,d = -d;
		else if( s < l ) s = l+1,d = -d;	
	}
};

vector<Lift> V;
int Seen[256][2],Seenid;
int Lpos;




int main(){
	int T = GI;	
	while( T-- ){
		int N = GI;
		++Seenid;
		V.clear();
		V.pb(Lift(0,0,0,0));
		REP(i,N){
			int a = GI,b = GI,c = GI,d = GI;
			V.pb(Lift(a,b,c,d));
		}
		V.pb(Lift(0,0,0,0));
		
		int Lpos = 0,Cnt = 0,ntime = 0;
		int f = 0;
		
		while( Cnt < 400*100 + 2 ){
			
			if(V[Lpos].s == V[Lpos+1].s && f){
				Lpos++;
				ntime += Cnt;
				if( Lpos == V.sz - 1) break;				
				Cnt = 0;
				REPV(i,V) V[i].Move();
			}
			Cnt++;
			f = 1;
			cout << " In : "<< Lpos << "   ";
			REPV(i,V){
				 V[i].Move();
				 if(i && i<V.sz-1)printf("%3d ",V[i].s);
			}
			cout << " :: "<< Cnt << endl;
			getchar();
			getchar();
			
		}
		
		if( Lpos == V.sz -1 ) cout << ntime << endl;
		else cout << -1 << endl;
		
	}
	return 0;
}

