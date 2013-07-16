#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <cstdio>


#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define mkp(a,b) make_pair((a),(b))
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;


struct Side {
	string T,B,L,R;
	void mirror(){
		swap(L,R);
		rev(T);rev(R);
	}
	void rotate(){
		string NR = T,NT = L,NL = B,NB = R;
		rev(NT);
		rev(NB);
		T = NT,L = NL,B = NB,R = NR;
	}
};
bool const operator<(const Side& a,const Side& b){
	if( a.T == b.T ){
		if( a.B == b.B){
			if( a.L == b.L ) return a.R < b.R;
			return a.L < b.L;
		}
		return a.B < b.B;
	}
	return a.T < b.T;
}

vector<Side> S[8];
set<Side> Stemp[8];

Side Init[6];
char B[124],used[8];
string Tops[4],Bottoms[4],Cols[4];


inline bool canOverlap(const string& a,const string& b){
	assert( a.sz == b.sz );
	REPV(i,a){
		if( (i == 0 || i == 5 ) ){
			if( a[i] == 'X' && b[i] == 'X' ) return 0;
		}
		else if( a[i] == b[i] ) return 0;	
	}
	return 1;
}

#define P123 ({REP(i,4) cout << Tops[i] <<" -> ";cout << endl;REP(i,4) cout << Bottoms[i] <<" -> ";1;})
#define EITHER(x,y,z) (((x)&&(y)) || ((y)&&(z)) || ((x)&&(z)) )
#define OR(x,y,z) ((x) || (y) || (z))


inline bool check(const Side& x ,const string Tops[]){
	FOR(i,1,5) if(x.T[i] == Tops[0][i]) return 0;
	FOR(i,1,5) if(x.R[i] == Tops[3][i]) return 0;
	FOR(i,1,5) if(x.L[i] == Tops[1][5-i]) return 0;
	FOR(i,1,5) if(x.B[i] == Tops[2][5-i]) return 0;

	if( !OR(Tops[0][0] == 'X',Tops[1][5] == 'X',x.T[0] == 'X') ) return 0;
	if( !OR(Tops[1][0] == 'X',Tops[2][5] == 'X',x.L[5] == 'X') ) return 0;
	if( !OR(Tops[2][0] == 'X',Tops[3][5] == 'X',x.B[5] == 'X') ) return 0;
	if( !OR(Tops[3][0] == 'X',Tops[0][5] == 'X',x.R[0] == 'X') ) return 0;	
	return 1;
}

bool go( int P ){
	if( P == 6 ) return 1;
	REP(i,6) if( !used[i] ) REPV(j,S[i]){
		Side& x = S[i][j];
		used[i] = 1;
		if( P == 0 ){
			Tops[P] = x.T,Bottoms[P] = x.B;
			Cols[P] = x.L,Cols[P+3] = x.R;
			if(go( P+1 )) return 1;
						
		} else if ( P <=2 && canOverlap(x.R,Cols[P-1])){
			Tops[P] = x.T,Bottoms[P] = x.B;
			Cols[P] = x.L;
			if( Tops[P-1][0] == 'X' || Tops[P][5] == 'X' ) Tops[P][5] = Tops[P-1][0] = 'X';
			if( Bottoms[P-1][0] == 'X' || Bottoms[P][5] == 'X' ) Bottoms[P][5] = Bottoms[P-1][0] = 'X';
			
			if(go( P+1 )) return 1;
			
			Tops[P-1][0] = Cols[P-1][0];
			Bottoms[P-1][0] = Cols[P-1][5];
						
		} else if ( P == 3 && canOverlap(x.R,Cols[P-1]) && canOverlap(x.L,Cols[3]) ){
			Tops[P] = x.T,Bottoms[P] = x.B;
			if( Tops[P-1][0] == 'X' || Tops[P][5] == 'X' ) Tops[P][5] = Tops[P-1][0] = 'X';
			if( Bottoms[P-1][0] == 'X' || Bottoms[P][5] == 'X' ) Bottoms[P][5] = 'X',Bottoms[P-1][0] = 'X';
			if( Tops[0][5] == 'X' || Tops[P][0] == 'X' ) Tops[P][0] = Tops[0][5] = 'X';
			if( Bottoms[0][5] == 'X' || Bottoms[P][0] == 'X' ) Bottoms[P][0] = 'X',Bottoms[0][5] = 'X';
			
			if(go( P+1 )) return 1;			
			
			Tops[P-1][0] = Cols[P-1][0];
			Bottoms[P-1][0] = Cols[P-1][5];
			Tops[0][5] = Cols[3][5];
			Bottoms[0][5] = Cols[3][5];
			
		} else if( P == 4 ){			
			if( check( x , Bottoms ) ) if(go( P+1 )) return 1;		
		}
		else if( P == 5 ){
			if( check( x, Tops) ) if(go( P+1 )) return 1;
		}
		used[i] = 0;	
		if(!P) return 0;
	}
	
	return 0;
}

int main(){
	int T = GI;
	FOR(t,1,T){
		REP(i,8) S[i].clear();
		memset(used,0,sizeof(used));
		REP(i,6) Init[i].T = Init[i].L = Init[i].B = Init[i].R = "";
		
		int f = 1;
		REP(i,6){
			scanf("%s",B);
			int pos = 0,cw = 0,cp = 0;
			while( B[pos] ){
				char c = B[pos++];
				if( c == '!') { cp = 0;cw++;continue;}
				if( !i ) Init[cw].T += c;
				else if( i == 5 ) Init[cw].B += c;
				if( cp == 0 ) Init[cw].L += c;
				else if ( cp == 5 ) Init[cw].R += c;
				if( i!=0 && i != 5 && cp != 0 && cp != 5 && c != 'X' ) f = 0;
				cp++;
			}
		}
		if( !f ){
			printf("Scenario #%d:\n",t);		
			printf("No\n\n");		
			continue;	
		}
		
		REP(i,6){
			Side x = Init[i];
			Stemp[i].insert( x );
			REP(j,3) {
				x.rotate();
				Stemp[i].insert( x );
				Side xx = x;
				xx.mirror();
				Stemp[i].insert( xx );
			}
		}
		REP(i,6) S[i] = vector<Side> (Stemp[i].begin(),Stemp[i].end());

		REP(i,4){
			Tops[i] = "",Bottoms[i] = "" , Cols[i] = "";
			REP(j,6) Tops[i] += ".",Bottoms[i] += "." , Cols[i] += ".";
		}
		
		printf("Scenario #%d:\n",t);
		if(!go(0)) {
			printf("No\n");
		} else { printf("Yes\n");}
		printf("\n");		
	
	}
	return 0;
}


