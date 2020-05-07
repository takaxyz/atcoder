#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;

  vector<double> p(N+1);
  REP(i,N)cin >> p[i+1];

  vector<vector<double>> dp(N+1, vector<double>(N+1,0));
  dp[0][0]=1.0;
  FOR(i,1,N+1){
    REP(j,i){
      dp[i][j] += dp[i-1][j] * (1-p[i]);
      dp[i][j+1] += dp[i-1][j] * p[i];
    }
  }

  double ans=0;
  FOR(i,N/2+1, N+1){
    ans += dp[N][i];
  }

  printf("%.10f\n", ans);
}

