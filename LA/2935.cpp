#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i = 0;i < (N); ++i )
#define pb push_back
#define sz size()

char Store[3002][3002],nxt = 0;
char S[3002],S1[3002];

bool comp(int a,int b){
	return strcmp(Store[a],Store[b]) <= 0;
}

int norm(int x){
	vector<int> C;
	if( x > 18 ) exit(0);
	int ox = x;
	while( S[x] != '1' ){
		cout <<" in x = " << ox <<" calling norm " << x+1 << endl;
		int p = norm(++x);
		C.pb( p );
		cout <<"   x = " << ox <<" child = "<< Store[p] << endl;
		x += strlen( Store[p] )-1;
	}
	sort(C.begin(),C.end(),comp);
	int p = 0;	
	REP(i,C.sz) {
		Store[nxt][p++] = '0';
		for(int j=0;Store[C[i]][j]; ++j ) Store[nxt][p++] = Store[C[i]][j];
	}
	Store[nxt][p++] = '1';
	Store[nxt][p++] = 0;
	return nxt++;
}

int main(){
	int T = GI;
	while( T-- ){
		nxt = 0;
		scanf("%s",S);
		int p = norm( 0 );
		memcpy(S1,Store[p],3002);
		
		nxt = 0;
		scanf("%s",S);p = norm( 0 );
		printf("%s\n",strcmp(S1,Store[p]) == 0 ? "same":"different");
		exit(0);
	}
	return 0;
}


