#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,a) for(int i=0;i<a.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define sz size()
#define INF (1<<28)
#define LINF ((int) 1e18)
#define GI ({int t;scanf("%d",&t);t;})
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;


int main(){
	int T = GI;
	while(T--){
		int N = GI,L = GI;
		set<int> V;REP(i,N) V.insert(GI);
		int Seen[V.size()];
		memset(Seen,0,sizeof(Seen));
		
		int ret = 0;
		while( V.sz ){
			int tof = L-(*V.begin());
			set<int>::iterator it = lower_bound(V.begin(),V.end(),tof);			
			if( it!=V.end()){
				 cout << " Matching : "<< (*V.begin()) << " "<< (*it) << endl;
				 V.erase(it);
			}
			else{
				cout << " Separate : "<< (*V.begin()) << endl;
			}
			V.erase(V.begin());
			ret++;			
		}
		cout << ret << endl;
	}
}
