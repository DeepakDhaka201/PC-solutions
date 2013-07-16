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
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923
#define MY_PI (int(1e7*M_PI))
#define MY_PI_2 (int(1e7*M_PI_2))
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,double> PID;

int N;
PII Pts[1200];
int Angles[1200];

void print(char *s,pair<int,double> a){printf("%s -> %lf\n",s,a.second*180/M_PI);}

// Gives the angle between the line segments ( PII(Pts[i].first, Pts[i].second) to PII(Pts[i].first,0) ) and ( Pts[j] and Pts[i] ), 
inline double get_angle(const int& i,const int& j){
	#define x (Pts[j].first - Pts[i].first)
	#define y (Pts[j].second - Pts[i].second)	
	const double r = acos( -y/sqrt(y*y+x*x) );	
	if( x < 0 ) return  2*M_PI - r;
	#undef x
	#undef y
	return r; // return is bet 0 and 359
}

inline bool toremove(int a,int b,int x){ // a is to be removed if it is not between  the angles b-x and b
	int diff = a>=b ? (2*MY_PI-a+b) : (b-a);
	return !(diff >=0 && diff <= x );	
}

int main(){
	int tt = 1;
	while((N=GI)){
		REP(i,N) Pts[i].first = GI,Pts[i].second = GI;
		sort(Pts,Pts+N);
		LL ans = 0;
		
		REP(i,N){			
			int cnt = 0;			
			REP(j,N) if( i != j ) Angles[cnt++] = int(get_angle(i,j)*1e7);
			sort(Angles,Angles+cnt);
			deque<int> D1,D2; // if X is current angle , D1 contains all the pts with angle bet X-90 and X , and D2 contains X-180 and X-90
			for(int i = cnt-1,x;i>= 1 && (x=(2*MY_PI-Angles[i]+Angles[0])) < MY_PI; i-- ){
				if( x > MY_PI_2 ) D2.push_front( Angles[i] );
				else D1.push_front( Angles[i] );
			}	
			
			REP(i,cnt){
				while( D1.sz && toremove(D1.front(),Angles[i],MY_PI_2) )
					D2.pb( D1.front() ),D1.pop_front(); // Once the first angle in D1 is sep by more than 90degrees with X , then put in D2
				while( D2.sz && toremove(D2.front(),Angles[i],MY_PI) ) // similarly if the sep is more than 180 remove it from D2
					D2.pop_front();
				D1.pb( Angles[i] );
				ans += D2.sz; // add the no of line segments that can produce an obtuse angle
			}			
		}
		printf("Scenario %d:\n",tt++);
		printf("There are %lld sites for making valid tracks\n",(LL(N)*(N-1)*(N-2)/6 - ans) );
	}
	return 0;
}
