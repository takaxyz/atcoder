#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n,m,x;
  cin >> n >> m >> x;

  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));

  REP(i,n){
    cin >> c[i];
    REP(j,m)cin >> a[i][j];
  }

  int ans=(1<<30);
  REP(i,(1<<n)){
    vector<int> s(m,0);
    int tmp=0;
    REP(j,n){
      if((i>>j) & 1){
        REP(k,m)s[k] += a[j][k];
        tmp += c[j];
      }
    }

    bool ok=true;
    REP(j,m){
      if(s[j] < x)ok=false;
    }

    if(ok)chmin(ans,tmp);
  }

  cout << (ans==(1<<30) ? -1 : ans) << endl;
}

