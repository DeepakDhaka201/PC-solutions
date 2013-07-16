#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef double LD;

#define myhypot(a) (sqrt(LL(a.first)*a.first + LL(a.second)*a.second))

int N,M;
vector<PII> Pts;
vector<LD> ang;
map<LL,LL> maxdist;

LD get_ang(PII a,PII b,PII c,int f = 0){
	PII y(a.first - b.first,a.second - b.second);
	PII x(c.first - b.first,c.second - b.second);
	LD sin = (x.first*y.second - x.second*y.first); sin = sin/( myhypot(x)*myhypot(y) );
	LD cos = (x.first*y.first + x.second*y.second); cos = cos/( myhypot(x)*myhypot(y) );
	assert(fabs(sin*sin+cos*cos-1)<1e-9);	
	sin = asin( sin );
	cos = acos( cos );
	LD ret;
		
	if( f ) return cos;
	
	if ( sin > -1e-9 && cos > -1e-9 ) ret = cos;
	else if( sin > -1e-9 ) ret = (M_PI_2 + sin);
	else if( sin < -1e-9 ) ret =  (2*M_PI - cos);
	else ret = (M_PI + M_PI_2 + cos);	

	return ret;
}

bool isOnLine(PII a,PII b,PII p){
	int lox = min(a.first,b.first);
	int loy = min(a.second,b.second);
	int hix = max(a.first,b.first);
	int hiy = max(a.second,b.second);	
	return p.first >= lox && p.first <= hix && p.second >= loy && p.second <= hiy 
			&& ( (a.first-p.first)*(b.second-p.second) == (b.first-p.first)*(a.second-p.second) );
}

bool isInside(PII a,PII b,PII c,PII p){
	bool v = isOnLine( a , b , p ) | isOnLine( b , c , p ) | isOnLine( c , a , p );
	if( v ) return v;
	LD totang = get_ang(a,p,b,1) + get_ang(b,p,c,1) + get_ang(c,p,a,1);
	return fabs(totang-2*M_PI) < 1e-9;
}

int main(){
	int T = GI;
	REP(t,T){
		Pts.clear();ang.clear();maxdist.clear();
		N = GI,M = GI;
		vector<PII> temp;
		REP(i,N){
			int x = GI,y = GI;
			temp.pb( PII(x,y) );
		}
		rev(temp);
		
		double cang = 0;
		const double MEPS = 1.56e-7;
		PII prev;
		int cont = 0;
		REPV(i,temp){
			int x = temp[i].first,y = temp[i].second;
			if( i ) cang = get_ang( Pts[0] , PII(0,0) , PII(x,y) );
			if( ang.sz > 1 && fabs(cang-ang[ang.sz-1])<MEPS && fabs(cang-ang[ang.sz-2])<MEPS ) Pts[Pts.sz-1] = temp[i];
			else {
				ang.pb( cang );
				Pts.pb( temp[i] );
			}
			prev = PII(x,y);
			LL lang = LL(cang*1e6);
			maxdist[ lang ] >?= x*x + y*y;
		}
		
		/*
		REPV(i,Pts) cout << Pts[i].first <<" , " << Pts[i].second << endl;
		REPV(i,ang) printf("%.8lf ",ang[i]);
		cout << endl;
		*/
		ang.pb( 2*M_PI ); Pts.pb( Pts[0] );

		int cnt = 0;
		REP(i,M){
			int x = GI,y = GI;
		
			if(!x && !y ){
				cnt++;
				//printf("%d %d %d\n",x,y,1);
				continue;
			}
			LD subAngle = get_ang( Pts[0], PII(0,0) , PII(x,y) );
			int low = lower_bound( ang.begin() , ang.end() , subAngle ) - ang.begin();
			int hi  = upper_bound( ang.begin() , ang.end() , subAngle ) - ang.begin();assert(hi>0);
			//cout <<" Init low = " << low <<" hi = " << hi << endl;
			int add = 0;
			if( fabs( ang[low] - subAngle ) < MEPS) {
				LL lang = LL(ang[low]*1e6);
				int maxd = maxdist[lang];
				add |= (x*x + y*y <= maxd );
			}
			if( fabs( ang[hi-1] - subAngle ) < MEPS ) {
				LL lang = LL(ang[hi-1]*1e6);
				int maxd = maxdist[lang];
				add |= (x*x + y*y <= maxd );
			}
			if( hi < ang.sz && fabs( ang[hi] - subAngle ) < MEPS ) {
				LL lang = LL(ang[hi]*1e6);
				int maxd = maxdist[lang];
				add |= (x*x + y*y <= maxd );
			}
			
			if( hi > 0 ){
				if( fabs(ang[hi-1] - ang[hi]) < MEPS ) hi--;
				add |= isInside( Pts[hi-1] , PII(0,0) , Pts[hi] , PII(x,y) );			
			}
			//printf("%d %d %d\n",x,y,add);
			//printf("%d %d -> ang = %.8lf  add = %d low = %d , hi = %d\n",x,y,subAngle,add,hi-1,hi);
			cnt += add;
		}
		printf("%d\n",cnt);
		
	}
	return 0;
}

