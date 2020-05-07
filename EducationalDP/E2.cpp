#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int MAX_V = 100000;

int main(){
  int N,W;
  cin >> N >> W;
  vector<int> w(N),v(N);
  REP(i,N){
    cin >> w[i] >> v[i];
  }

  vector<ll> dp(MAX_V+1,INF);
  dp[0]=0;

  REP(i,N){
    for(int j = MAX_V; j >=0; j--){
      if(dp[j]==INF)continue;
      if(dp[j]+w[i]>W)continue;
      dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]); 
    }
  }

  int ans=0;
  REP(i,MAX_V+1){
    if(dp[i]==INF)continue;
    ans = max(ans,i);
  }
  cout << ans << endl;
}

