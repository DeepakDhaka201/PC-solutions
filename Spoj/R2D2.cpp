#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i=GI;i;i--) V.pb( GI )
#define REP(i,N) for(int i = 0;i<N;i++)
#define sz size()
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<28)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector< vector<int> > VVI;
typedef long long int LL;
char str[16];
VVI ar;
VI Max;

PII Search(int val,int start){
	int l1 = -1,l2 = -1;
	for(int i=start;i<ar.sz;i++) if(Max[i]>=val){ l1 = i;break;}	
	assert(l1>-1);
	Max[l1] = -1;
	REPV(i,ar[l1]){		 
		 if(ar[l1][i]>=val){ l2 = i;break;}
		 Max[l1] >?= ar[l1][i];
	}
	assert(l2>-1);
	return PII(l1,l2);
}

void print(){
	REPV(i,ar){
		REPV(j,ar[i]) cout << ar[i][j] <<" ";
		cout << " :::: "<< Max[i] << endl;
		cout << endl;	
	}
	cout << " --------- " << endl;
}
#define NN 1000

int main(){
	int T = GI;
	while( T-- ){
		int K = GI;
		ar.clear();ar.resize(NN+1);
		Max.clear();Max.resize(NN+1,K);
		REP(i,NN) REP(j,NN) ar[i].pb(K);
		
		vector<PII> V;
		int N = GI;
		getchar();
		for(int i=0;i<N;){
			int a,b = 1;
			gets(str);	
			if(str[0]=='b') sscanf(str+2,"%d %d",&b,&a);
			else sscanf(str,"%d",&a);			
			V.pb(PII(a,b));
			i += b;
		}
		
		int prev = INF;
		PII res(-1,-1);		
		int USED = 0,WASTE = 0;
		
		
		for(int i=0;i<V.size();){		
			int val = V[i].first,cnt = V[i].second;
			if(val>=prev) res = Search(val,res.first);
			else res = Search(val,0);
			//print();
			int Cap = ar[res.first][res.second];
			int nt = (cnt <? (Cap/val));
			Cap -= val*nt; 
			
			if(!Cap){
				ar[res.first].erase(ar[res.first].begin()+res.second);USED++;
				if(!ar[res.first].sz) ar.erase(ar.begin()+res.first),Max.erase(Max.begin()+res.first);
				else Max[res.first] >?= Cap;
			}
			else ar[res.first][res.second] = Cap,Max[res.first] >?= Cap;		

			V[i].second -= nt;
			if(!V[i].second) i++;
			prev = V[i].first;				
		}
		//print();
		REPV(i,ar) REPV(j,ar[i]) if(ar[i][j]<K) USED++,WASTE += ar[i][j];
		cout << USED <<" "<<WASTE << endl;		
	}	
}
