#include <iostream>
#include <cstdio>
using namespace std;
#define REP(i,N) for(int i = 0;i < (N); ++i)
#define GI ({int t;scanf("%d",&t);t;})
typedef long long int LL;
LL A[1024];
void print( LL x ){
	int ar[4];
	REP(i,4) ar[i] = (x&((1<<8)-1)), x >>= 8;
	REP(i,4) printf("%d%s",ar[3-i],(i<3?".":"\n"));
}

LL get(){
	static char s[128];
	scanf("%s",s);
	LL ret = 0,n = 0;
	for(int i = 0;s[i];i++){
		if( s[i] == '.' ) ret <<= 8, ret |= n, n = 0;
		else n = n*10 + (s[i]-'0');
	}
	ret <<= 8, ret |= n;
	return ret;
}

int main(){
	int N;
	char str[1024];
	while( scanf("%d",&N) == 1 ){
		REP(i,N) A[i] = get();
		
		LL x = (1LL<<32)-1,comp;
		REP(i,33) {
			comp = (A[0]&x);
			int f = 1;
			REP(j,N) if( (A[j]&x) != comp ) f = 0;
			if( f ){
				print(comp);print(x);
				goto bad;
			}
			x <<= 1;
		}
		bad:
		;
	}
	return 0;
}
