#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n,m;
  cin >> n >> m;

  VI s(m);
  REP(i,m){
    int k;
    cin >> k;

    int ss=0;
    REP(j,k){
      int t;
      cin >> t;
      ss += (1 << --t);
    }
    s[i] = ss;
  }
  
  VI q(m);
  REP(i,m){
    cin >> q[i];
  }

  int ans=0;
  REP(i,(1<<n)){
    int t=0;
    bool ok=true;
    REP(j,m){
      if(__builtin_popcount((i & s[j])) % 2 != q[j])ok=false;
    }

    if(ok)ans++;
  }

  cout << ans << endl;

}

