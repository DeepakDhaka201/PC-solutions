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
string S;
struct node{
	int x;
	node(int a):x(a){}	
};
int Dp[128];
vector<node> Par[128];
char Str[128],pos;
bool operator<(const node& a,const node& b){
	return S[a.x] < S[b.x];	
}
void go(int pos,int c){	
	 Str[c] = S[pos];
	 if(Par[pos].sz == 0){
		printf("%s\n",Str+c);
		return;
	 }
	 
	 REPV(i,Par[pos]) go(Par[pos][i].x,c-1);
	 return;
}

int main(){
	int T = GI;
	REP(t,T){
		memset(Dp,0,sizeof(Dp));
		memset(Str,0,sizeof(Str));
		REP(i,128) Par[i].clear();
		cin >> S;
		Dp[0] = 1;
		int maxx = 0;
		REPV(i,S){
			int ret = 0;
			FOR(j,0,i-1) if(S[j]<=S[i]){
				if(Dp[j]>ret){
					 Par[i].clear();	
					 Par[i].pb(node(j));					 
				}
				else if(ret == Dp[j]) Par[i].pb(node(j));
				ret >?= Dp[j];
			}
			maxx >?= (Dp[i] = 1+ret);
		}
		REP(i,128) sor(Par[i]);
		REPV(i,S) if(Dp[i]== maxx){
			int c = 102;
			Str[c] = '\0';
			go(i,c-1);
		}
	}	
}
