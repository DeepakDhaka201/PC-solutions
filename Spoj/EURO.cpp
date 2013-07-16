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
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define GI ({int y;scanf("%d",&y);y;})
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

int Ar[8],mAr[8],Vis[8];
int DONE[100000];

VI V;
int ret = INF;
int done = 0;

void go(int c){	
	if( c > 5 ) return;
	if( done == V.sz ){	
		if( ret > c ){
			REP(i,c) mAr[i] = Ar[i];
			ret = c;			
		}
		return;
	}	
	REPV(x,V) if(!Vis[x]){		
		Vis[x] = 1;
		done++;
		REP(i,c) REP(j,i) if(fabs(Ar[i] - Ar[j]) == V[x] ){			
			go(c);			
			break;
		}
		REP(i,c){
			Ar[c] = Ar[i] - V[x];go(c+1);
			Ar[c] = Ar[i] + V[x];go(c+1);
		}
		done--;
		Vis[x] = 0;
	}
}

int main(){
	int T = GI;
	//clock_t t = clock();
	FOR(t,1,T){
		int N = GI;
		ret = INF;
		V.clear();
		Ar[0] = 0;
		REP(i,N) V.pb( GI );		
		go(1);		
		printf("Scenario #%d\n %d:",t,ret);
		sort(mAr,mAr+ret);
		int disp = 0-mAr[0];		
		REP(i,ret) printf(" %d",mAr[i]+disp);
		
		REPV(k,V){
			int f = 0;
			REP(i,ret) REP(j,i) if( mAr[i] - mAr[j] == V[k] ) f = 1;
			if(!f) cout <<" Not Found : "<< V[k] << endl;
			assert(f);
		}
		
		printf("\n\n");
	}
	//cout << (clock()-t)*1./CLOCKS_PER_SEC << endl;
	return 0;
}
