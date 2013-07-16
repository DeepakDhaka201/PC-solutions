#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(_typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<30)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
#define sz size()
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;

int Seen[20001][2],Seenid = 1;
PII Par[20001][2];

int main(){
	int T = GI;
	while( T-- ){
		++Seenid;
		int N = GI;
		queue<PII> Q;
		Q.push(PII(1%N,1));
		Par[1%N][1] = PII(-1,-1);
		Seen[1%N][1] = Seenid;
		
		
		PII back(-1,-1);
		while( Q.sz ){
			int n = Q.front().second,rem = Q.front().first;Q.pop();			
			if(!rem){ 
				back = PII(rem,n);
				break;
			}
			REP(i,2){
				 int next = (rem*10 + i)%N;
				 if(Seen[next][i] == Seenid) continue;Seen[next][i] = Seenid;
 				 Par[next][i] = PII(rem,n);
				 Q.push(PII(next,i));
			}
		}
		
		string s = "";
		while(back.first>=0){
			s = char(back.second+'0') + s;
			back = Par[back.first][back.second];
		}
		cout << s << endl;
	}
}

