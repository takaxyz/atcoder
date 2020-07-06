#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

bool check(string &s, string &p){
  REP(i,s.size()-p.size()+1){
    bool ng=false;
    REP(j,p.size()){
      if(s[i+j]!=p[j] && p[j]!='.')ng=true;
    }
    if(!ng){
//      PRINT(p);
      return true;
    }
  }
  return false;
}

int main(){
  string s;
  cin >> s;

  string p = "abcdefghijklmnopqrstuvwxyz.";
  
  int ans = 0;
  for(auto c1: p){
    string pat = {c1};
    if(check(s, pat))ans++;
  }
  if(s.size()==1){
    PRINT(ans);
    return 0;
  }
  for(auto c1: p){
    for(auto c2: p){
      string pat = {c1, c2};
      if(check(s, pat))ans++;
    }
  }
  if(s.size()==2){
    PRINT(ans);
    return 0;
  }
  for(auto c1: p){
    for(auto c2: p){
      for(auto c3: p){
        string pat = {c1, c2, c3};
        if(check(s, pat))ans++;
      }
    }
  }
  PRINT(ans);
}

