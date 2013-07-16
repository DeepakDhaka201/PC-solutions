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
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF LINF
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int N,L;

double area( const vector<PII>& Pts, const double& lo ){
	double area = 0;
	double minht = INF;
	const double hi = lo + L;
	
	for(int i = 0;i+1 < Pts.sz ; ++i ){		
		const double lox = max( lo , 1.*Pts[i].first ),
					 hix = min( hi , 1.*Pts[i+1].first );
		if( hix < lox ) continue;
		//cout <<" lox =  "<< lox <<" hix = " << hix << endl;
		const double slope = ( Pts[i+1].second - Pts[i].second )*1. / ( Pts[i+1].first - Pts[i].first );
		//cout <<"   slope = " << slope << endl;
		const double loy = Pts[i].second + slope*(lox-Pts[i].first),
					 hiy = Pts[i].second + slope*(hix-Pts[i].first);
		//cout <<" loy = " << loy <<" hiy = " << hiy << endl;
		area += ( (hix-lox)*min(hiy,loy) + (hix-lox)*fabs(hiy-loy)/2.0 );
		minht <?= min(hiy,loy);
	}
	//cout <<"  Calc area @ : "<< lo <<" -> "<< hi << " Area = " << area - minht*L << endl;
	return area - minht*L;
}


int main(){
	int T = GI;
	while( T-- ){
		vector< pair<int,int> > Pts;
		N = GI,L = GI;
		REP(i,N){
			int a = GI,b = GI;
			Pts.pb( PII(a,b) );
		}		
		double ans = LINF;
		REP(i,N-1){
			double low = Pts[i].first + L,high = Pts[i+1].first + L;			
			REP(j,N-1) {
				const double lob = max( low , 1.*Pts[j].first ),
							 hib = min( high , 1.*Pts[j+1].first );
				if( hib < lob ) continue;
				
				double a = lob-L,b = hib-L;
				REP(i,40){
					const double left = (a*2+b)/3;
					const double right = (a+2*b)/3;
					if( area(Pts,left) > area(Pts,right) ) a = left;
					else b = right;
				}
				ans <?= area(Pts,a);
			}
		}
		printf("%.4lf\n",ans);		
	}
	return 0;
}