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
enum Operator { AND , OR ,XOR , COPY , NOT};
#define ok(r,c) (r>=0 && r < N && c>=0 && c < M )

struct Item {
	VI ip;
	Operator operation;
	int op;		
	Item():op(-1),operation(COPY){}	
};

int Map[256][256],leq_cnt,heq_cnt;
int N,M,Cnt = 0;
int dx[] = { -1 , 0 , 1, 0 },
	dy[] = { 0, -1 , 0 ,1 };
Item Mp[250*250+1];
int Outputs[26],Nop;
bool Seen[26];
int MSeen[256][256],Seenid = 1;

bool input();
void gather_output();
void gather_gates();
void gather_inputs();
void gather_nots();
bool calc(int G);

void go(int r,int c,int d,int G){
	if( !ok(r,c) ) return;
	if( MSeen[r][c] == Seenid ) return;
	MSeen[r][c] = Seenid;
	if( -Map[r][c] > leq_cnt && -Map[r][c] <= heq_cnt ){
		Mp[-Map[r][c]].ip.pb( G );
		return;
	}
	else if( Map[r][c] == '-' && (d == 1 || d == 3) ) go(r+dx[d],c+dy[d],d,G);
	else if( Map[r][c] == '|' && (d == 0 || d == 2) ) go(r+dx[d],c+dy[d],d,G);
	else if( Map[r][c] == 'x' ) go(r+dx[d],c+dy[d],d,G);
	else if( Map[r][c] == '+' ){
		REP(i,4)
			if( i != (d+2)%4 ) go( r+dx[i],c+dy[i],i,G);
	}
}

bool calc(int G){
	Item& I = Mp[G];
	if( I.op != -1 ) return I.op;	
	EACH(it,I.ip) calc( *it );
	if( I.operation == NOT || I.operation == COPY ){
		assert( I.ip.sz == 1 );
		return I.op = (calc(I.ip[0]) + I.operation == NOT )%2;
	}
	I.op = I.operation == AND;
	EACH(it,I.ip) {
		if( I.operation == AND ) I.op &= calc( *it );
		else if( I.operation == OR ) I.op |= calc( *it );
		else I.op ^= calc( *it );
	}
	return I.op;
}

int main(){	
	while( input() ){		
		Cnt = 1;
		memset(Seen,0,sizeof(Seen));
		REP(i,250*250+1) Mp[i] = Item();
		
		gather_output();
		gather_gates();
		gather_inputs();		
		gather_nots();
		
		leq_cnt = Cnt;
		REP(i,N) REP(j,M) if( Map[i][j] == '=' && Map[i][j+1] < 0 ){
			Item I;
			I.operation = COPY;
			if( Map[i][j-1] < 0 ) I.ip.pb( -Map[i][j-1] );
			Mp[-Map[i][j+1]].ip.pb( Cnt+1 );
			Map[i][j] = -(Cnt+1);
			Mp[++Cnt] = I;
		}
		heq_cnt = Cnt;
		REP(i,N) REP(j,M) if( Map[i][j] == '=' && Map[i][j-1] < 0){
			Item I;
			I.operation = COPY;
			I.ip.pb( -Map[i][j-1] );
			++Seenid;
			go(i,j+1,3,(Cnt+1));
			Map[i][j] = -(Cnt+1);
			Mp[++Cnt] = I;			
		}
		//REP(i,N) REP(j,M) printf("%c%s",char(Map[i][j]),j == M-1 ? "\n":"");
		
		REP(i,26) if( Seen[i] ){			
			int G = Outputs[i];
			calc( G );
			printf("%c=%d\n",char('A'+i),Mp[G].op);
		}
		puts("");
	}
	return 0;
}

bool input(){
	memset(Map,0,sizeof(Map));
	char temp[256];	
	N = 0,M = 0;	
	while( true ){
		gets(temp);
		if( temp[0] == '*' ) break;
		M >?= strlen( temp );
		for(int i = 0;temp[i]; ++i ) Map[N][i] = temp[i];
		N++;
	}	
	return bool(N);	
}

void gather_output(){
	REP(i,N) REP(j,M) if( Map[i][j] >= 'A' && Map[i][j] <= 'Z' ){
		Item I;I.operation = COPY;
		Outputs[Map[i][j]-'A'] = (Cnt+1);
		Seen[Map[i][j]-'A'] = 1;
		Map[i][j] = -(Cnt+1);
		Mp[++Cnt] = I;		
	}
}

Operator fill(int r,int c){	
	int a = r,b = c;char ret = 0;
	while( Map[r][c+1] == '#' ) Map[r][c] = -(Cnt+1),c++;
	while( Map[r+1][c] == '#' ) Map[r][c] = -(Cnt+1),r++;
	for(int i = a;i <= r; ++i ) for(int j = b; j <= c; j++){
		if( Map[i][j] =='1' || Map[i][j] == '&' || Map[i][j] == '=' ) ret = Map[i][j];
		Map[i][j] = -(Cnt+1);
	}
	if( !ret ) assert(1>2);
	return ( ret == '&' ? AND : ret == '1' ? OR : XOR );	
}

void gather_gates(){
	REP(i,N) REP(j,M) if( Map[i][j] == '#' ){
		Item I;I.operation = fill(i,j);		
		Mp[++Cnt] = I;
	}
}

void gather_inputs(){
	REP(i,N) REP(j,M) if( Map[i][j] == '1' || Map[i][j] == '0' ){
		Item I;I.op = Map[i][j]-'0';
		Map[i][j] = -(Cnt+1);
		Mp[++Cnt] = I;
	}
}

void gather_nots(){
	REP(i,N) REP(j,M) if( Map[i][j] == 'o' ){
		Item I;I.operation = NOT;
		I.ip.pb( -Map[i][j-1] );assert( Map[i][j-1] < 0 );
		Map[i][j] = -(Cnt+1);
		Mp[++Cnt] = I;
	}
}
