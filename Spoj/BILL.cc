#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<N;i++)
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i!=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define p_b push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;

int main(){
	int a,b,v,A,S;
	while((a=GI) + (b=GI) + (v=GI) + (A=GI) + (S=GI)){
		double hor = v*cos(A*M_PI/180.00);
		double vert = v*sin(A*M_PI/180.00);
		cout << " hor = " << hor << " vert = " << vert << endl;
		double hdist = hor*S;
		double vdist = vert*S;
		int a1 = 0,b1 = 0;
		if( hdist > (a/2.00) ) a1++,hdist -= (a/2.00);
		if( vdist > (b/2.00) ) b1++,vdist -= (b/2.00);
		
		a1 += int(hdist/a);
		b1 += int(vdist/b);
		cout << b1 << " " << a1 << endl;
	}

}
