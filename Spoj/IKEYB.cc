using namespace std;
#include <cassert>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <list>

#define GI ({int i;scanf("%d",&i);i;})
#define pb push_back
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define INF (1<<30)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();i++)
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;
int K,L;
string A,B;
VI V;
int cnt = 0;
int memo[100][100][100];

int go(int pos,int len,int rem){
    if( memo[pos][len][rem] != -1 ) return memo[pos][len][rem];
    if( !rem ) return INF;
    if( pos == L ) return 0;

    int a = go(pos+1,len+1,rem) + V[pos]*len;
    int b  = INF;
    if(pos) b = go(pos+1,2,rem-1) + V[pos];

    return memo[pos][len][rem] = ( a <? b );
}


void retr(int pos,int len,int rem){
    if( pos == L ) return;
    if( !rem ) return;

    int a = go(pos+1,len+1,rem) + V[pos]*len;
    int b = go(pos+1,2,rem-1) + V[pos];
    int ret = memo[pos][len][rem];
    
    if( ret == b ){
       printf("\n%c: %c",A[++cnt],B[pos]);
       retr(pos+1,2,rem-1);
    }
    else {
        printf("%c",B[pos]);
        retr(pos+1,len+1,rem);    
    }
    return;
}


int main(){
    int T = GI;
    FOR(t,1,T){
        K = GI,L = GI;
        V.clear();
        cnt = 0;
        memset(memo,-1,sizeof(memo));
        cin >> A >> B;
        REPV(i,B) V.pb( GI );
        go(0,1,K);
        printf("Keypad #%d:\n",t);
        printf("%c: ",A[cnt]);
        retr(0,1,K);
        printf("\n");
    }
}

