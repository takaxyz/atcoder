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

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int n;
vector<ll> a;

ll dp[2000][2000];

ll dfs(int l, int r){
  int turn = (r-l+n)%n;

  if(dp[l][r]!=-1)return dp[l][r];

  if(l==r){
    if(n%2==1)return dp[l][r] = a[l];
    else return dp[l][r] = 0;
  }

  if(turn%2==1){
    return dp[l][r] = max(dfs((l+n-1)%n, r) + a[l], dfs(l, (r+1)%n)+a[r]);
  }else{
    if(a[l]<a[r]){
      r = (r+1)%n;
    }else{
      l = (l+n-1)%n;
    }
    return dp[l][r] = dfs(l,r);
  }
  
}

int main(){
  cin >> n;

  // JOI -> IOI（大きい方）
  // 奇数ターン JOI、偶数ターン IOI
  a.resize(n);
  REP(i,n)cin >> a[i];
  REP(i,n)REP(j,n)dp[i][j]=-1;

  ll ans = -1;
  REP(i,n){
    chmax(ans, dfs((i+n-1)%n, i));
  }
  cout << ans << endl;
}

