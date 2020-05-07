#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> h(N);
  REP(i,N){
    cin >> h[i];
  }

  vector<int> dp(N,INF);
  dp[0]=0;
  REP(i,N){
    FOR(j,1,K+1){
      if(i+j<N){
        dp[i+j] = min(dp[i] + abs(h[i]-h[i+j]), dp[i+j]);
      }
    }
  }
  cout << dp[N-1] << endl;
}

