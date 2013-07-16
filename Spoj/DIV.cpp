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
typedef vector<int> VI;
char N[2000000];
int q = 0,n = 0;
char final[2000000];

int main2(){	
	long long int d;
	scanf("%s",N);
	cin >> d;	
	unsigned long long int rem = 0;
	for(int i = 0;N[i]; ++i ){
		double nrem = rem*10 + (N[i]-'0');
		if( nrem >= d ){			
			int q = nrem/d;assert( q < 10 ); 
			rem = (unsigned long long int ) (nrem - q*d );
		}			
		else rem = (unsigned long long int ) nrem;		
	}	
	
	long long int toadd = d - rem;	
	static char temp[2000000];
	sprintf(temp,"%lld",toadd);
	
	
	int e1 = 0,e2 = 0;
	while( N[e1+1] ) e1++;
	while( temp[e2+1] ) e2++;
	
	int r = 0,f = 1500000;
	final[f] = 0;
	while( e1 >= 0 || e2 >= 0 ){
		assert( f >= 0 );
		int c = r;
		if( e1 >= 0 ) c += N[e1]-'0', e1--;
		if( e2 >= 0 ) c += temp[e2]-'0',e2--;		
		final[--f] = ('0' + c%10);		
		r = c/10;
	}
	if( r ) final[--f] = '0' + r;	
	printf("%s\n",final+f);	
	return 0;
}


int main(){
	int T = GI;
	while( T-- ) main2();
}