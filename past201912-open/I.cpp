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
//const int INF=(1<<29);

int main(){
  int n,m;
  cin >> n >> m;

  vector<ll> dp(1<<n, INF);
  dp[0]=0;

  REP(i,m){
    string s;
    ll c;
    cin >> s >> c;

    int t=0;
    REP(j,s.size()){
      if(s[j]=='Y'){
        t |= (1<<j);
      }
    }
    REP(j, (1<<n)){
      if(dp[j]==INF)continue;
      chmin(dp[j|t], dp[j] + c);
    }
  }

  if(dp[(1<<n)-1]==INF){
    cout << -1 << endl;
  }else{
    cout << dp[(1<<n)-1] << endl;
  }

}

