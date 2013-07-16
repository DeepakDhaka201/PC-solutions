#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

char str[16][124];
int Len[16];
int memo[1<<16][124],next[1<<16][124],Seen[1<<16][124],N;
int Gr[16][16],Seenid,k;


void input(){
	VS temp;
	N = GI;
	REP(i,N){
		string t;cin >> t;
		temp.pb( t );
	}
	sort(temp.begin(),temp.end());
	REPV(i,temp){
		sprintf(str[i],"%s",temp[i].c_str());
		Len[i] = temp[i].sz;
	}	
	
	REP(i,N) REP(j,N) {
		Gr[i][j] = Len[j];
		REP(s,Len[i]){
			for(k=0;str[i][s+k] && str[i][s+k] == str[j][k];k++);
			if( !str[i][s+k] || !str[j][k])	Gr[i][j] <?= Len[j] - k;		
		}
		cout << str[i] <<" : "<< str[j] <<" -> " << Gr[i][j] << endl;
	}
	exit(0);

}

int go(int bit,int c){
	if( bit == (1<<N)-1 ) return 0;

	int& ret = memo[bit][c];
	if( Seen[bit][c] == Seenid ) return ret;Seen[bit][c] = Seenid;
	
	ret = INF;
	REP(i,N) if( (bit&(1<<i)) == 0 ){
		int cost = Gr[c][i] + go( bit | (1<<i) , i );
		if( cost < ret ) ret = cost , next[bit][c] = i;	
	}
	return ret;
}

//aaaabbaab
int main(){
	int T = GI;
	FOR(tt,1,T){
		input();
		++Seenid;
		int ret = INF,start = -1;
		REP(i,N) if( go(1<<i,i) + Len[i] < ret ) ret = go(1<<i,i) + Len[i] , start = i;
		assert( start != -1 );
		
		int bit = (1<<start);
		printf("%s",str[start]);
		
		REP(i,N-1){
			int n = next[bit][start];
			printf("%s",str[n] + Len[n] - Gr[start][n]);
			start = n,bit |= (1<<start);
		}
		printf("\n");
		
	}
	return 0;
}



