#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
const int N=10;
int ar[N];

void merge(int *ar,int p,int q,int r){
static int ar1[N];
for(int i=p;i<=q;i++) ar1[i-p]=ar[i];
for(i=r;i>q;i--) ar1[r-i+(q-p)+1]=ar[i];

int i1=0,i2=r-p;
for(int k=p;k<=r;k++){
   if(ar1[i1]<=ar1[i2]) ar[k]=ar1[i1++];
   else ar[k]=ar1[i2--];
 }
return;
}

void mergesort(int *ar,int p,int r){
if(p>=r) return;
mergesort(ar,p,(p+r)/2);
mergesort(ar,(p+r)/2+1,r);
merge(ar,p,(p+r)/2,r);
}

int main(){
	clrscr();
	for(int i=0;i<N;i++) ar[i]=random(100);
	mergesort(ar,0,N-1);
	for(i=0;i<N;i++) cout << ar[i]<<"  ";

}