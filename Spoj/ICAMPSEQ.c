#include <cstdio>
#define REP(i,N) for(i = 0;i<(N);i++)

double sets[8];
double msets[8];


int main(){
	int N,i,bit;
	scanf("%d",&N);
	REP(i,8) sets[i] = msets[i] = -(1e10);
	REP(i,N){
		double a,b,c,d;
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		REP(bit,8){
			register const double x =
			a * ( (bit&1) ? 1 : -1 ) + b * ( (bit&2) ? 1 : -1 ) + c * ( (bit&4) ? 1 : -1 ) + d;
			sets[bit] >?= -x;
			msets[bit] >?= x;			
		}
	}	
	double ret = 0;
	REP(bit,8){
		double x = fabs(sets[bit]+msets[bit]);
		ret >?= x;		
	}
	printf("%.3lf\n",ret);
	return 0;
}
