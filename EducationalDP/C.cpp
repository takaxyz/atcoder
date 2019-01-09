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

int N;

int main(){
    cin >> N;

    ll dp[N][3];
    REP(i,N)REP(j,3)dp[i][j] = 0;

    REP(i,3)cin >> dp[0][i];

    FOR(i,1,N){
      ll abc[3];
      REP(j,3){
        cin >> abc[j];
      }
      REP(j,3)REP(k,3){
        if(j==k)continue;
        ll tmp = dp[i-1][k] + abc[j];
        if(tmp > dp[i][j])dp[i][j] = tmp;
      }
    }
    ll ans = 0;
    REP(i,3){
      if(ans < dp[N-1][i]) ans = dp[N-1][i];
    }    
    cout << ans << endl;
}
