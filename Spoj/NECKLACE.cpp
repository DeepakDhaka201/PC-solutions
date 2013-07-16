/*
ID: gcdart1
PROG: beads
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <map>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
#define repv(i,ar) for(int i=0;i<ar.size();i++)
#define sor(ar) sort(ar.begin(),ar.end())
#define VS vector<string>
#define VI vector<int>
#define p_b push_back
#define ll long long int 
#define sz size()
using namespace std;

string g_str;

string get_back(int i){
int j=i-1;if(j<0) j=g_str.length()-1;
char c=g_str[j];
string ret="";
while(c=='w'){
ret+=c;           
j--;if(j<0) j=g_str.length()-1;                 
c=g_str[j];
}

while(g_str[j]==c || g_str[j]=='w'){
ret+=c;
j--;if(j<0) j=g_str.length()-1;                 
}
return ret;       
}

string get_front(int i){
int j=i;string ret="";
char c=g_str[i];      

while(c=='w'){
ret+=c;           
j++;if(j==g_str.length()) j=0;                   
c=g_str[j];
}

while(g_str[j]==c || g_str[j]=='w'){
ret+=c;
j++;if(j==g_str.length()) j=0;                   
} 
return ret;
}

int main(){
 ifstream fin("beads.in");
 ofstream fout("beads.out");
 int waste;fin >> waste;
 string str;fin >>  str;
 g_str=str;
 bool flag1=false,flag2=false;
 repv(i,str) {
 if(str[i]=='r') flag1=true;
 else if(str[i]=='b') flag2=true;
}
if(!flag1 || !flag2){
          fout <<  str.length() << endl;exit(0);}
int maxcnt=-1;
repv(i,str){
string s1=get_back(i);
string s2=get_front(i);
int cnt=s1.length()+s2.length();
if(cnt > str.size()) cnt=str.size();
if(cnt > maxcnt) maxcnt=cnt;
}
 fout << maxcnt << endl;
 exit(0);
}

