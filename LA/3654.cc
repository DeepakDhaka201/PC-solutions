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

string ar[4];
#define LEFT 2
#define DOWN 1
#define TOP 0
#define RIGHT 3
int NO[256];
int dir[4][4] = { DOWN , RIGHT , TOP , LEFT ,
				 DOWN , LEFT , TOP , RIGHT ,
				 TOP , LEFT , DOWN , RIGHT ,
				 TOP , RIGHT , DOWN , LEFT };
string s[4][2] = { "s" , "q", "r" , "p", "q" , "s", "p" , "r" };

int main(){
	int T = GI;
	NO['p'] = 0,NO['q'] = 1,NO['r'] = 2,NO['s'] = 3;
	
	while( T-- ){
		string str;
		cin >> str;
		REP(i,4) ar[i] = "m";
		
		str.erase(str.begin());
		string curr = "m";
		REPV(i,str) {
			char c = str[i];
			int no = NO[ c ];
			ar[dir[no][0]] = curr + s[no][0];
			ar[dir[no][1]] = curr + s[no][1];
			if( ar[dir[no][2]].sz > 1 ) ar[dir[no][2]] += s[no][0];
			if( ar[dir[no][3]].sz > 1 ) ar[dir[no][3]] += s[no][1];			
			curr += c;
		}
		
		REP(i,4){
			printf("%s%s",(i?" ":""),(ar[i].sz < 2?"<none>":ar[i].c_str()));
		}
		printf("\n");
	}
}



