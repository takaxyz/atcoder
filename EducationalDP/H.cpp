#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<vector<int>> dp(H, vector<int>(W,0));

  REP(i,H)REP(j,W){
    cin >> a[i][j];
  }

  dp[0][0]=1;
  REP(i,H)REP(j,W){
    if(a[i][j]=='#')continue;
    if(i>0){
      dp[i][j] += dp[i-1][j];
      dp[i][j] %= MOD;
    }
    if(j>0){
      dp[i][j] += dp[i][j-1];
      dp[i][j] %= MOD;
    }
  }

  cout << dp[H-1][W-1] << endl;

}

