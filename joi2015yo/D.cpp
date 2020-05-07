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

//const ll INF=(ll)1e19;
const int INF=(1<<30);

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> c(m+1);
  vector<int> d(n+1);

  vector<vector<int>> dp(m+1, vector<int>(n+1, INF));

  REP(i,n)cin >> d[i+1];
  REP(i,m)cin >> c[i+1];

  // dp_ij: i日目に都市jにいるときの疲労度の最小値
  dp[0][0] = 0;
  FOR(i,1,m+1){
    FOR(j,0,i+1){
      dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + c[i]*d[j]);
    }
  }

  
  // REP(i,n)cout << d[i+1] << " ";
  // cout << endl << endl;
  // REP(i,m)cout << c[i+1] << " "; 
  // cout << endl << endl;

  int ans = INF;
  REP(i,m+1){
    chmin(ans, dp[i][n]);
  }

  // REP(i,dp.size()){
  //   REP(j,dp[i].size()){
  //     cout << dp[i][j] << (j==dp[i].size()-1 ? "\n" : " ");
  //   }
  // }
  cout << ans << endl;
}

