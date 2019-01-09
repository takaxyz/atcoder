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
const int MAXV=100000;

int N,W;

int main(){
    cin >> N >> W;

    ll dp[N+1][MAXV+1];
    REP(i,N+1)REP(j,MAXV+1)dp[i][j] = INF;

    dp[0][0] = 0;

    FOR(i,1,N+1){
      ll w,v;
      cin >> w >> v;
      REP(j,MAXV+1){
        if(dp[i-1][j] == INF)continue;

        // i個目を選ばない
        if(dp[i][j] > dp[i-1][j])dp[i][j] = dp[i-1][j];

        // i個目を選ぶ
        if(dp[i-1][j] + w <= W){
          if(dp[i][j+v] > dp[i-1][j] + w)dp[i][j+v] = dp[i-1][j] + w;
        }
      }

    }
    ll ans = 0;
    for(int i = MAXV; i >= 0; i--){
      if(dp[N][i] != INF){
        ans = i;
        break;
      }
    }
    cout << ans << endl;
}
