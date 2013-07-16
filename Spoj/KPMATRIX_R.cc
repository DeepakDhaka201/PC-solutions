#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main(){
    int cnt = -1;
    while( true ){
	++cnt;
	char temp[100];
	sprintf(temp,"KPMATRIX%02d.in",cnt);
	FILE *f = fopen(temp,"r");
	if( f == NULL ) return 0;
	fclose(f);
	char com[100];
	sprintf(com,"./kpmatrix < %s > KPMAT%02d.out",temp,cnt);
	//cout << com << endl;
	system(com);
    }
}
