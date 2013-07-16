#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <sstream>
#include <string>
#include <cassert>

#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i = 0;i <(N); ++i)
const int MN = 2048;
using namespace std;

int main(){
	int N,n;
	static char temp[64];
	string str;

	while( true ){
		temp[0] = 0;
		gets( temp );
		if( !temp[0] ) break;
		sscanf(temp,"%d",&N);
		if( !N ) break;		

		int off = 0,print = 0;
		int poss[ 2048 ] = {},lo = 1;
		REP(i,MN) poss[ i ] = 1;
		
		REP(i,N){
			gets( temp );stringstream ss(temp);
			ss >> str >> n;
			if( str == "IN") off += n;
			else if( str == "OUT" ){
				off -= n;
				if( off < 0 ) lo >?= -off + 1;
			}
			else if( str == "PAY" ){
				print = 1;
				REP(i,MN){
					if( i+off <= n && i+off > 0 && n%(i+off) == 0 ) continue;
					poss[ i ] = 0;
				}
			}
		}
		if( print ){
			int pp = 0;
			for(int i = 1;i < MN; ++i ) if( poss[ i ] && i >= lo ) printf("%s%d",pp?" ":"",i),pp = 1;
			if( !pp ) puts("IMPOSSIBLE");
			else puts("");
		} else printf("SIZE >= %d\n",lo);

	}
	return 0;
}
