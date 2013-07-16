#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<N;i++)
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;


int ar[101][101],N,s = 1000;

int go(int x,int y,int no){
	if(!(x>=0 && x<N && y>=0 && y<N) || ar[x][y]!=no ) return 0;
	ar[x][y] = s;
	int ret = 0;
	FOR(i,-1,1) FOR(j,-1,1) if(!i || !j) ret += go(x+i,y+j,no);
	return ret+1;
}

int main(){
	int a,b;
	while(N = GI){
		getchar();
		int x = 1;s+=10;
		REP(i,N-1){
			while( true ){
				a = GI-1,b = GI-1;
				ar[a][b] = i+1;
				char c = getc(stdin);
				if(c=='\n') break;
				else ungetc(c,stdin);
			}
			if(x &&  go(a,b,i+1)!= N ) x = 0;
		}
		int m = -1,n = -1;
		//REP(i,N) REP(j,N) if(ar[i][j]==s){ m = i,n = j;break;}
		//if(x && go(m,n,s)!=N ) x = 0;		
		printf("%s\n",(x?"good":"wrong"));
	}	
}
