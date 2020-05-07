#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  REP(i,h)REP(j,w)cin >> a[i][j];

  vector<bool> r(h,false);
  vector<bool> c(w,false);

  REP(i,h)REP(j,w){
    if(a[i][j]=='#'){
      r[i]=true; c[j]=true;
    }
  }

  REP(i,h){
    if(!r[i])continue;
    REP(j,w){
      if(!c[j])continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}

