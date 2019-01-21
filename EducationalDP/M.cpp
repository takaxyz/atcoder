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

int N, K;
int dp[101][100001];
int csum[100001];
int a[101];

int main(){
  cin >> N >> K;

  REP(i,N)cin >> a[i];

  REP(i,N+1)REP(j,K+1) dp[i][j] = 0;

  dp[0][0] = 1;

  FOR(i,1,N+1){

    csum[0] = dp[i-1][0];

    FOR(j,1,K+1)csum[j] = (csum[j-1]+dp[i-1][j]) % MOD;

    REP(j,K+1){
      if(j-a[i-1]-1 >= 0){
        dp[i][j] = csum[j] - csum[j-a[i-1]-1];
      }else{
        dp[i][j] = csum[j];
      }
      dp[i][j] %= MOD;
    }

  }

  if(dp[N][K] >= 0){
    cout << dp[N][K] << endl;
  }else{
    cout << dp[N][K] + MOD << endl;

  }

}