#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N, M;
vector<vector<int> > e;
vector<ll> memo;


ll dp(int node){
  if(memo[node] != -1)return memo[node];
  ll ret = 0;
  for(auto v : e[node]) ret = std::max(ret, dp(v)+1);
  return memo[node] = ret;

}

int main(){
  cin >> N >> M;

  e.resize(N+1);

  REP(i,M){
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
  }

  memo.resize(N+1,-1);

  FOR(i,1,N+1)dp(i);

  cout << *max_element(memo.begin(), memo.end()) << endl;
}