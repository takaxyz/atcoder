#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);

int main(){
  int N;
  cin >> N;
  vector<int> h(N);
  REP(i,N){
    cin >> h[i];
  }

  vector<int> dp(N,INF);
  dp[0]=0;
  REP(i,N){
    if(i+1<N){
      dp[i+1] = min(dp[i] + abs(h[i]-h[i+1]), dp[i+1]);
    }
    if(i+2<N){
      dp[i+2] = min(dp[i] + abs(h[i]-h[i+2]), dp[i+2]);
    }
  }
  cout << dp[N-1] << endl;
}

