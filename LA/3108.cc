#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
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

double mins[3][3] = { {4.5,150,200} ,{6,300,500},{5,200,300} };
char *str[] = { "Wide Receiver","Lineman","Quarterback"};
char out[1000];
double ar[3];

int main(){
	while(1){
		REP(i,3) cin >> ar[i];		
		if(fabs(ar[0]) <1e-9 && fabs(ar[1]) < 1e-9 && fabs(ar[2]) < 1e-9 ) break;
		int x = 0;
		REP(i,3){
			int pos = 0;
			REP(j,3){
				 if( j!=0 && mins[i][j]-ar[j] > 1e-9 ) pos = 1;
				 if( j==0 && ar[j]-mins[i][j] > 1e-9 ) pos = 1;
			}	
			if(!pos) x += sprintf(out+x,"%s%s",(x?" ":""),str[i]);
		}
		if(!x) cout << "No positions" << endl;
		else cout << out << endl;
	}
	return 0;
}

