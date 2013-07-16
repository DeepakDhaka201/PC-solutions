#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;


int main(){
	int T = GI;
	while( T-- ){
		LL x;
		cin >> x;
		x = x/5 + bool(x%5);
		LL a = INF,b = 0,A = LL(1e18);
		
		for(LL l = 4;l*l <= x*(48*10*5) ; l += 44 ){
			LL fit = ( (l-4)/44 );if( !fit ) continue;			
			LL w = (x/fit + bool(x%fit))*10 + 2;			
			long long tl = l,tw = w;
			if( tl < w ) swap(tl,tw);
			
			if( tl*tw < A ) A = tl*tw, a = tl,b = tw;
			if ( A == tl*tw && (tl-tw) < (a-b) ) a = tl,b = tw;		
		}
		cout << a <<" X "<< b <<" = " << A << endl;
	}
	return 0;
}
