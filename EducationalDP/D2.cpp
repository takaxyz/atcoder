#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);

int main(){
  int N,W;
  cin >> N >> W;
  vector<int> w(N),v(N);
  REP(i,N){
    cin >> w[i] >> v[i];
  }

  vector<ll> dp(W+1,-1);
  dp[0]=0;

  REP(i,N){
    for(int j = W; j >=0; j--){
      if(dp[j]==-1)continue;
      if(j+w[i]>W)continue;

      dp[j+w[i]] = max(dp[j+w[i]], dp[j]+v[i]); 
    }
  }

  ll ans=0;
  REP(i,W+1){
    if(dp[i]==-1)continue;
    ans = max(ans,dp[i]);
  }
  cout << ans << endl;
}

