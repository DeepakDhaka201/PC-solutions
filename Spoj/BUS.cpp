#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>

#define pb push_back
#define VI vector<int> 
#define INF (1<<28)
#define VS vector<string>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define GI ({int y;scanf("%d",&y);y;})
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
using namespace std;
int N;
VI line[51];
LL news[51],pos[51];




int main(){

    while(N = GI){
		 
		 REP(i,N){
			line[i].clear();
			news[i] = (1LL<<i);
			pos[i]  = 0;
			for(int S=GI;S;S--) line[i].pb( GI );
		 }

		 int ct = 0,maxe = N*N+1,tt = 0;
			 
		 while( maxe ){
			bool ex = false;
			REP(i,N) FOR(j,i+1,N-1) if(line[i][pos[i]] == line[j][pos[j]] && (news[i]^news[j]) ){
				maxe = N*N+1;
//				cout << " ex " << i << " " << j << endl;
				news[i] = news[j] = (news[i] | news[j]);
				ex = true;
			}
			if(ex) tt = ct;
			REP(i,N) pos[i] = (pos[i] + 1)%line[i].size();
			maxe--;
			ct++;			
		 }

		 int f = 0;
		 REP(i,N) if( news[i] != (1LL<<N)-1 ) f = 1;
		 
		 if( f ) cout << "NEVER" << endl;
		 else cout << tt << endl;
	 }
}


