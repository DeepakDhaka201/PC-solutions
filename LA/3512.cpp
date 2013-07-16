#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i = 0;i <(N); ++i)
#define sz size()
#define pb push_back
#define INF (int(1e9))

char Ans[128];
struct Node {
	char Shape;
	int x,y;
}G;
double xcord;
int printed = 0;
double getAngle(const Node& n){
	if( fabs(n.x - xcord) < EPS ) return M_PI_2;
	else if( n.x > xcord ) return M_PI - atan( n.y / ( n.x - xcord ) );
	return atan( n.y/(xcord - n.x) );
}
bool operator<(const Node& a,const Node& b){
	return getAngle( a ) < getAngle( b );
}

void print(){
	
}

int main(){
	int N;
	while( scanf("%d",&N) == 1 ){
		printed = 0;
		vector<Node> V;
		
		REP(i,N){
			string s;int a,b;
			cin >> s >> a >> b;
			G.Shape = s[0];
			G.x = a,G.y = b;
			V.pb( G );
		}
		set<double> XCons;
		XCons.insert( INF );XCons.insert( -INF );
		for(int i = 0;i < N; ++i ) for(int j = 0;j < i; ++j ){
			double x1 = V[ i ].x, y1 = V[ i ].y;
			double x2 = V[ j ].x, y2 = V[ j ].y;
			if( fabs( y1 - y2) < EPS ) continue;
			double rx = x1 - y1 * ( x2 - x1 ) / ( y2  -y1 );
			XCons.insert( rx );
		}
	}	
	vector<double> Xcords( XCons.begin(), XCons.end() );
	double prev = -INF;
	for(int i = 1;i < Xcords.sz; ++i ) if( fabs( Xcords[ i ] - prev ) > EPS ){
		double mid = ( Xcords[ i ] + prev ) / 2;
		if( check( mid ) ) print( check );
		prev = Xcords[ i ];				
	}
	return 0;
}



