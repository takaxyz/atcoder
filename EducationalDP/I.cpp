#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N;

int main(){
  cin >> N;

  double dp[N+1][N+1];
  
  REP(i,N+1)REP(j,N+1)dp[i][j]=0;
  dp[0][0] = 1.0;

  vector<double> p(N);

  REP(i,N) cin >> p[i];

  REP(i,N){
    dp[i+1][0] = dp[i][0] * (1.0-p[i]);
    FOR(j,1,i+2){
      dp[i+1][j] = dp[i][j-1] * (p[i]) + dp[i][j] * (1.0-p[i]);
    }
  }

  double ans = 0;
  FOR(i, N/2+1, N+1){
    ans += dp[N][i];
  }
  cout << setprecision(10) << ans << endl;  
}