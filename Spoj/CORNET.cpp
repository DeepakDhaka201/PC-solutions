#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>

#define pb push_back
#define VI vector<int> 
#define VS vector<string>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define GI GETNUM()
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
using namespace std;

int mp[20001],N;
LL score[20001];
int path[20001];

#define ok(a,b) ((a)>=0 && (b)>=0 && (a)<N && (b)<M)
#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
   int
      i ;

   ITYPE
      j ;

   i = GETCHAR () ;
   while ( ! DIG( i ) )
      i = GETCHAR () ;

   j = ( i - '0' ) ;

   i = GETCHAR () ;
   while ( DIG( i ) )
   {
      j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
      i = GETCHAR () ;
   }
   return ( j ) ;
}


int find_set(int x){
	int p=x,root,sc = 0,pcnt = 0;
	
 	while(mp[p]!=-1){
 			 path[pcnt++] = p;
			 p=mp[p];
	} 	
	root=p;
	
	for(int i = pcnt-1;i>=0;i--){
		sc += score[path[i]];
		score[path[i]] = sc;
		mp[path[i]] = root;		
	}
	
	
	return root;
}

int get_score(int a){
	 int p = a,ret = 0,root,pcnt = 0;
	 
	 while(mp[p] > 0 ){
		path[pcnt++] = p;
		p = mp[p];		
	 }
	 root = p;
	 
	 for(int i = pcnt-1;i>=0;i--){
	 	ret += score[path[i]];
	 	score[path[i]] = ret;
		mp[path[i]] = root; 				
	 }
	 	 
	 return ret;
}


inline void make_set(int a){mp[a] = -1;}

inline void union_set(int a,int b){
	int x = a,y = find_set(b);
	mp[x] = y;
	score[x] += get_score(b) + abs(x-b)%1000;
}



int main(){
	int T = GI;
	char s[10];
	while( T-- ){
		N = GI;
		//cout << " N = " << N << endl;
		memset(score,0,sizeof(score));
		memset(mp,-1,sizeof(mp));
		while(1){
			scanf("%s",s);
			if( s[0] == 'O' ) break;
			if( s[0] == 'E' ){
				int a = GI;
				printf("%d\n",get_score(a));
					
			}
			else if( s[0] == 'I'){
				int a = GI,b = GI;
				union_set(a,b);
			}
		}
	}
	
}
