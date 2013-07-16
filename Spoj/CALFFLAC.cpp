/*
  ID : gcdart1
  TASK : calfflac
  LANG : C++
*/
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


#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define rev(ar) reverse(ar.begin(),ar.end())
#define p_b push_back
#define mset(ar,i) memset(ar,i,sizeof(ar))
#define VI vector<int> 
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define ALL(ar) ar.begin(),ar.end()
typedef long long int LL;
using namespace std;

char buffer[20001];
char old[20001];
#define COND (buffer[i] && buffer[j])      
#define EXC  if((j-i+1) > ret ) ret = (j-i+1),f1=i,f2=j;

int main(){
    int pos = 0;
    int f1,f2,ret = 0;
    char temp[81];    
    FILE *f = fopen("calfflac.in","r");
    while( !feof(f) ){
            char c = fgetc(f);
            old[pos++] = c; 
    }
    fclose(f);
    
    for(int i=0;old[i];i++) buffer[i] = tolower(old[i]);
    
    for(int mid=0;buffer[mid];mid++){
            if(!isalpha(buffer[mid])) continue;

            int i = mid,j = mid;
             
            while(COND && (buffer[i] == buffer[j])){
              EXC
              i--;j++;
              while(buffer[i] && !isalpha(buffer[i])) i--;
              while(buffer[j] && !isalpha(buffer[j])) j++;
            }
            
            i = mid,j = mid+1;
            while(buffer[j] && !isalpha(buffer[j])) j++;            
            
            while(COND && (buffer[i] == buffer[j])){
              EXC
              i--;j++;
              while(buffer[i] && !isalpha(buffer[i])) i--;
              while(buffer[j] && !isalpha(buffer[j])) j++;
            }
    }
    
    
    f = fopen("calfflac.out","w");
    int cnt = 0;
    FOR(i,f1,f2) if(isalpha(old[i])) cnt++;
    fprintf(f,"%d\n",cnt);
    FOR(i,f1,f2) fprintf(f,"%c",old[i]);
    fprintf(f,"\n");
    fclose(f);
}
