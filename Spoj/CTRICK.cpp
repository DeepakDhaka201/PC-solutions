#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>


#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define GI ({int t;scanf("%d",&t);t;})
#define VS vector<string>
typedef long long int LL;
using namespace std;

vector<VI> ar;
int toput = -1,N;
int poss[20002],sz;



void skip(int& r,int &c,int amt){
	if(c + amt < ar[r].size()){
		c += amt;
		poss[ar[r][c]] = toput;
		ar[r].erase(ar[r].begin()+c);
		if(!ar[r].size()){
			 ar.erase(ar.begin()+r),c = 0;
			 r = (r==ar.size()?0:r);
		}
		return;	
	}
	else{
	    amt = amt - (ar[r].size()-c);
		c = 0;
		r = (r+1)%ar.size();
		skip(r,c,amt);
	}
	
}
char prints[20001][6];

int main(){
	int T = GI;
	FOR(i,1,20001) sprintf(prints[i],"%d",i);

	REP(t,T){
		N = GI;
		ar.clear();
		sz = ((int)sqrt(N)) + 1;
		ar.resize(sz);
		REP(i,N) ar[i/sz].pb(i);
 		int r = 0,c = 0;
		FOR(i,1,N){
			toput = i;
			skip(r,c,i);
		}
		REP(i,N){
			printf("%s ",prints[poss[i]]);
		}
		printf("\n");
	}
}


