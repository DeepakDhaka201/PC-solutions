#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <sstream>
using namespace std;
#define REP(i,N) for(int i = 0;i < (N); ++i)
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it)
#define pb push_back
#define sz size()
#define GI ({int t;scanf("%d",&t);t;})
#define mkp make_pair
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;

int main(){
	int N = GI;
	for(int i = 0;i < N; ++i ){
		long long int a = GI;
		int f = 0;
		if( a == 0 ) f = 1;
		else if ( a == 1 ) f = 1;
		else if( a == 2 ) f = 0; 
		else {			
			for(long long int i = 2; i*i <= a; ++i ) if( a%i == 0 ){ f = 1;break;}
		}		
		printf(f?"No":"Yes");
		puts("");
	}
}