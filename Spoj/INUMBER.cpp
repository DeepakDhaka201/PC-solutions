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
typedef pair<PII,int> PIII;
typedef vector<int> VI;
typedef vector<string> VS;

int Seen[1024][1024],Seenid = 1;
PIII Par[1024][1024];
PII Q[1024*1024];


int main(){
	int T = 1;
	int prev = 0;
	while( T-- ){
		int N = GI;
		int x = -1,y = -1,s,r,_s,_r;		
		Seenid++;

		int front = 0,rear = 0;
		Q[rear].first = Q[rear++].second = 0;
		
		while( front <= rear ){
			s = Q[front].first,r = Q[front++].second;
			if( s == N && !r ){ 
				x = s,y = r;
				break;
			}
			
			for(int i = (s?0:1);i <= 9;i++){
				_s = s + i,_r = (r*10 + i)%N;
				if( _s > N || Seen[_s][_r] == Seenid ) continue;
				
				Seen[_s][_r] = Seenid;
				Par[_s][_r].first.first = s,Par[_s][_r].first.second = r;
				Par[_s][_r].second = i;
				Q[rear].first = _s,Q[rear++].second = _r;
			}
		}

		static char buff[1024];
		int bc = 1022;
		while( x || y){
			buff[bc--] = '0' + Par[x][y].second;
			int a = Par[x][y].first.first;
			int b = Par[x][y].first.second;			
			x = a,y = b;
		}
		printf("%s\n",buff+bc+1);
	}
}
