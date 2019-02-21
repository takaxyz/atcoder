#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cstdio>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;


int N;
vector<vector<int> > a;
vector<bool> visited;

vector<vector<ll> > memo;

ll dp(int n, char c, int parent){
  if(c == 'W' && memo[n][0] != 0){
    return memo[n][0];
  }else if(c == 'B' && memo[n][1] != 0){
    return memo[n][1];
  }

  ll ret = 1;
  REP(i,a[n].size()){
    if(a[n][i] == parent)continue;
    if(c == 'W'){
      ret *= (dp(a[n][i], 'B', n) + dp(a[n][i], 'W', n));
      ret %= MOD;
    }else{
      ret *= dp(a[n][i], 'W', n);
      ret %= MOD;
    }
  }

  if(c == 'W'){
    return memo[n][0] = ret;
  }else{
    return memo[n][1] = ret;
  }

}

int main(){
  cin >> N;

  a.resize(N+1);

  memo.resize(N+1);
  FOR(i,1,N+1)memo[i].resize(2);

  visited.resize(N+1);
  FOR(i,1,N+1)visited[i] = false;

  REP(i,N-1){
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  ll ans = 0;
  ans += dp(1, 'B', 0);
  ans += dp(1, 'W', 0);

  cout << ans % MOD << endl;

}