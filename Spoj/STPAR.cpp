#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define repv(i,ar) for(int i=0;i<ar.size();i++)
using namespace std;
int v1[1001];
int v2[1001];
int v3[1001];
int top1=-1,top2=-1;
int top3=-1;

void push(int *v,int *top,int x){
 v[++(*top)]=x;
}

int pop(int *v,int *top){
 return v[(*top)--];
}



string possi(){
int i=0;

while(top1>=0){
int x=pop(v1,&top1);
while(top2>=0 && v2[top2]<x) if(top3>=0 && v2[top2]!=v3[top3]+1) return "no";
                             else push(v3,&top3,pop(v2,&top2));
push(v2,&top2,x);
}
while(top2>=0) push(v3,&top3,pop(v2,&top2));
for(i=0;i<top3;i++) if(v3[i]!=(i+1)) return "no";
return "yes";
}


int main(){
int t,x;
while(1){
cin >> t;if(t==0) break;top3=-1;top2=-1;top1=-1;
rep(i,t){ cin >> x;push(v2,&top2,x);}
rep(i,t)push(v1,&top1,pop(v2,&top2));
cout << possi() << endl;
}
return(0);
}
