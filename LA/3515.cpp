#include <iostream>
#include <cstdio>
using namespace std;
#define REP(i,N) for(int i = 0; i < (N) ; ++i )
#define GI ({int t;scanf("%d",&t);t;})
#define REF(x) x[ar[0]][ar[1]][ar[2]][ar[3]][ar[4]][ar[5]][ar[6]][ar[7]][ar[8]]

double Dp[5][5][5][5][5][5][5][5][5];
int Seen[5][5][5][5][5][5][5][5][5],Seenid = 1;
char Str[9][4][3];
int ar[9];


double go(){
	int& s = REF(Seen);
	double& ret = REF(Dp);
	if( s == Seenid ) return ret;
	s = Seenid,ret = 0;
	
	int cnt = 0,f = 1;
	REP(i,9) if( ar[i] < 4 ) f = 0;
	if( f ) return ret = 1;
	
	REP(i,9) if( ar[i] < 4 ) REP(j,9) if( j < i && ar[j] < 4 && Str[i][ar[i]][0] == Str[j][ar[j]][0] ){
		ar[i]++,ar[j]++;
		ret += go();
		ar[i]--,ar[j]--,cnt++;
	}
	if( cnt ) ret /= cnt;
	return ret;
}

int main(){
	while( true ){	
		++Seenid;
		REP(i,9) REP(j,4) if( scanf("%s",Str[i][3-j]) != 1 ) return 0;
		REP(i,9) ar[i] = 0;
		double r = go();
		printf("%.6lf\n",r);
	}
	return 0;
}
