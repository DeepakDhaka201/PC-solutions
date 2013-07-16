#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <cassert>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>


#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

char str[16][124],Len[16];
int Gr[16][16],Seen[16][1<<16],Seenid,Par[16][1<<16];
int COST[16][1<<16];

int main(){
	int T = GI;
	FOR(tt,1,T){
		int nN = GI;
		VS S; 
		REP(i,nN) { 
			string temp;cin >> temp;
			S.pb( temp );
		}
		sort(S.begin(),S.end());
		REP(i,nN) sprintf(str[i],"%s",S[i].c_str());
		REP(i,nN) Len[i] = strlen(str[i]);
		
		REP(i,nN) REP(j,nN) if( i != j ){			
			Gr[i][j] = Len[i]+Len[j];
			for(int s = 0;str[i][s]; ++s ){
				int k = 0;
				for(k = 0;str[i][s+k] && str[i][s+k] == str[j][k];k++);
				if( !str[i][s+k] || !str[j][k]) Gr[i][j] <?= Len[j] - k;				
			}			
		}
		
		++Seenid;
		set< pair<int,PII> > Q;
		Q.insert( make_pair(0,PII(0,-1)) );

		REP(i,16) REP(j,(1<<16)) COST[i][j] = INF;
		int back = -1;

		while( Q.sz ){
			int c = Q.begin()->first,bit = Q.begin()->second.first, cur = Q.begin()->second.second;
			Q.erase( Q.begin() );
			cout << bit <<"  "<< cur << " -> "<< c << endl;
			if( cur != -1 ){if( Seen[cur][bit] == Seenid) continue;Seen[cur][bit] = Seenid;}
			if( bit == (1<<nN)-1 ){ back = cur;break;} 
			
			REP(i,nN) if( i != cur ){
				int add = ( cur == -1 ?Len[i]: Gr[cur][i] );
				int nbit = bit | (1<<i);
				int ncur = (!add) ? cur: i;
				if( c+add >= COST[ncur][nbit] ) continue;COST[ncur][nbit] = c+add;
				Par[ncur][nbit] = cur;
				cout <<"     Pushing : "<< nbit <<"," << ncur <<" -> "<< c+add << endl;
				Q.insert( make_pair(c+add,PII(nbit,ncur)) );
			}		
		}
		
		VI V;
		int c = back,bit = (1<<nN)-1,t;
		REP(i,nN){
			int p = Par[c][bit];
			V.pb( c );
			bit = bit & (~(1<<c)),c = p;			
		}
		reverse(V.begin(),V.end());
		
		printf("Scenario #%d:\n",tt);
		printf("%s",str[V[0]]);
		REPV(i,V) if( i ){
			int p = V[i-1],c = V[i];
			printf("%s",str[c] + Len[c]-Gr[p][c]);
		}
		puts("");
		
	}
}
