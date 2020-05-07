#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n;
  int a[3][3];

  map<int, pair<int,int>> m;
  REP(i,3)REP(j,3){
    int t;
    cin >> t;
    a[i][j] = t;
    m[t] = make_pair(i,j);

  }
  cin >> n;

  REP(i,n){
    int t;
    cin >> t;
    if(m.find(t) != m.end()){
      int p = m.find(t)->second.first;
      int q = m.find(t)->second.second;
      a[p][q]=0;
    }
  }
  REP(i,3){
    bool f=true;
    REP(j,3){
      if(a[i][j]!=0)f=false;
    }
    if(f){
      cout << "Yes" << endl;
      exit(0);
    }
  }
  REP(i,3){
    bool f=true;
    REP(j,3){
      if(a[j][i]!=0)f=false;
    }
    if(f){
      cout << "Yes" << endl;
      exit(0);
    }
  }
  if((a[0][0]==0 && a[1][1]==0 && a[2][2]==0) ||
      (a[0][2]==0 && a[1][1]==0 && a[2][0]==0)){
      cout << "Yes" << endl;
      exit(0);
    }
  cout << "No" << endl;
}

