#include <iostream>
#include <map>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define repv(i,ar) for(int i=0;i<ar.size();i++)
using namespace std;
int cost,V,E;
int mp[1200];
int rank[1200];
void makeset(int x){
 mp[x]=-1;
 rank[x]=0;     
}
int find(int x);
void union_set(int x1,int y1){
int x=find(x1);int y=find(y1);     
if(rank[x]>rank[y])  mp[y]=x;
else if(rank[x]<rank[y]) mp[x]=y;
else mp[y]=x,rank[x]++;
}

int find(int x){
    int p=x,root;
    while(mp[p]!=-1) p=mp[p];
    root=p;
    p=x;
    while(p!=root){
     int next=mp[p];
      mp[p]=root;
      p=next;              
     }
     return root;
}

struct node{
  int from,to,cost;
  node(int a,int b,int c):from(a),to(b),cost(c){}     
};
vector<node> v;
bool operator<(const node& a,const node& b){return a.cost < b.cost;}

int ff(){
int ret=0;
rep(i,1200) makeset(i);
sort(v.begin(),v.end()); 
repv(i,v) if(find(v[i].from)!=find(v[i].to)){
     ret+=v[i].cost;
     union_set(v[i].from,v[i].to);     
  }
return ret;               
}


int main(){
int a,b,c;    
int t; cin >> t;
rep(tloop,t){
memset(mp,0,sizeof(mp));memset(rank,0,sizeof(rank));
cin >> cost >> V >> E;
rep(i,E){ cin >>a>> b>>c;v.push_back(node(a,b,c));}
int temp=ff();
cout << cost*temp<< endl;
}
}
