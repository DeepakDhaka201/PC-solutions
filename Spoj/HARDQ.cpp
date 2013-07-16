#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <list>
//defines	
#define GI GETNUM()
#define p_b push_back
#define pb push_back
#define sz size()
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();i++)
#define VI vector<int>
#define VS vector<string>
#define abs(x) ((x)>0?(x):-(x))
#define ALL(ar) ar.begin(),ar.end()
typedef long long int LL;
using namespace std;
typedef pair<int,int> PII;
vector<PII> Poly;


vector< pair<PII,PII> > Shapes;

long double PI = 3.1415926535897932;
ostream &operator<<(ostream& out,PII p){
  out << " " << p.first << ":" << p.second << " ";        
}

inline double get_area(PII A,PII B,PII C){
	   #define x1 A.first
	   #define y1 A.second
	   #define x2 B.first
	   #define y2 B.second
	   #define x3 C.first 
	   #define y3 C.second
       return (x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2))/2.00;
}


bool is_inside(PII pt){
     int r = pt.first,c = pt.second,b,c1,a;
     long double ang = 0;
     bool flag = false;
     double area;
     
     REPV(i,Poly){
        PII A = Poly[i];
        PII B = Poly[(i+1)%Poly.size()];
        if(A == pt ) return true;
        area = get_area(pt,A,B);
        if(abs(area) < 1e-7){
                     if(!flag)
                       flag = (r>=(A.first <? B.first) && r<=(A.first >? B.first) &&
                              c>=(A.second <? B.second) && c<=(A.second >? B.second));
        }
        else{
            b = (A.first-r)*(A.first-r)+(A.second-c)*(A.second-c);
            c1 = (B.first-r)*(B.first-r)+(B.second-c)*(B.second-c);
            a = (A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second);
            ang += ((area>1e-9)?1:-1)*acos((b + c1 - a)/(2*sqrt(b)*sqrt(c1)));
        }        
        if(flag) return true;
     }
     
    double temp = fabs(ang) - 2*PI;
    if(fabs(temp)<1e-7) return true;
    return false;
     
}

inline double get_area(pair<PII,PII> p){
       return fabs((p.first.first-p.second.first)*(p.first.second-p.second.second));
}

#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )
 
inline ITYPE GETNUM ( void )
{
int
i,flag = 1;
 
ITYPE
j ;
 
i = GETCHAR () ;
while ( ! DIG( i ) ){if(i=='-') flag = 0;i = GETCHAR () ;}

j = ( i - '0' ) ;
 
i = GETCHAR () ;
while ( DIG( i ) )
{
j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
i = GETCHAR () ;
}
if(flag) return ( j ) ;
else return (-j);
}


int main(){
    int N,M;
    
    while((N=GI) && (M=GI)){
         Poly.clear();Shapes.clear();
         int flag = 1;
         double PArea = 0,calc = 0;
         
         int h = 0,v = 0;
         REP(i,N){
            int a = GI,b = GI,f = 0;
            if(i>=1) if(!(a==Poly.back().first || b==Poly.back().second)) flag = 0;
            Poly.p_b(PII(a,b));
         }


         REP(i,M){
             int a = GI,b = GI,c = GI,d = GI;
             Shapes.p_b(make_pair(PII(a,b),PII(c,d)) );
         }
         
         if(Poly[0].first==Poly[Poly.size()-1].first || Poly[0].second==Poly[Poly.size()-1].second) flag *=1;
         else flag = 0;         
         if(!flag) goto end;
         
         REPV(i,Poly) if(i+1<Poly.size()) PArea += get_area(Poly[0],Poly[i],Poly[i+1]); 
         PArea = abs(PArea);

         calc = 0;

         REPV(i,Shapes){
             if(is_inside(Shapes[i].first) && is_inside(Shapes[i].second) &&
                is_inside(PII(Shapes[i].first.first,Shapes[i].second.second)) &&
                is_inside(PII(Shapes[i].second.first,Shapes[i].first.second)) 
               )  calc += get_area(Shapes[i]);
               
         }
         

		 	
         if( abs(calc-PArea) < 1e-7) flag *=1;
         else flag = 0;
         
         end:
             if(flag) cout << "YES" << endl;
             else cout << "NO" << endl;
    }
    
}



 
