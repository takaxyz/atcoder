#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N,W;

int main(){
    cin >> N >> W;

    ll dp[N+1][W+1];
    REP(i,N+1)REP(j,W+1)dp[i][j] = -1;

    dp[0][0] = 0;

    FOR(i,1,N+1){
      ll w,v;
      cin >> w >> v;
      REP(j,W+1){
        if(dp[i-1][j] == -1)continue;

        // i個目を選ばない
        if(dp[i][j] < dp[i-1][j])dp[i][j] = dp[i-1][j];

        // i個目を選ぶ
        if(j+w <= W){
          if(dp[i][j+w] < dp[i-1][j] + v){
            dp[i][j+w] = dp[i-1][j] + v;
          }
        }
      }

    }
    ll ans = 0;
    REP(i,W+1){
      if(ans < dp[N][i]) ans = dp[N][i];
    }    
    cout << ans << endl;
}
