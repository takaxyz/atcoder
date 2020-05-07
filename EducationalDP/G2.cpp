#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int dfs(int n, vector<int> &dp, vector<vector<int>> &edge){
  if(dp[n] != -1)return dp[n];

  int tmp=0;
  REP(i,edge[n].size()){
    tmp = max(tmp, dfs(edge[n][i], dp, edge)+1);
  }
  return dp[n]=tmp;
}

int main(){
  int N,M;
  cin >> N >> M;

  vector<vector<int>> edge(N, vector<int>());

  REP(i,M){
    int x,y;
    cin >> x >> y;
    edge[--x].push_back(--y);
  }

  vector<int> dp(N,-1);

  REP(i,N){
    dfs(i,dp,edge);
  }

  int ans=0;
  REP(i,N){
    ans=max(ans,dp[i]);
  }
  cout << ans << endl;

}

