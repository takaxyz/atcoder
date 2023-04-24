#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  ll n;
  cin >> n;
  vector<vector<P>> edge(n);
  REP(i,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].emplace_back(v,i);
    edge[v].emplace_back(u,i);
  }

  ll ans=n*(n-1)/2;
  auto dfs = [&](int v, ll mi, ll mx, int p, auto dfs) -> void{
    //cout << v << " " << mi << " " << mx << " " << (mi + 1) * (n - mx - 1) << endl;
    ans += (mi + 1) * (n - mx - 1);
    for(auto [nv, i]: edge[v]){
      if(nv==p)continue;
      ll mi2 = min(mi, i);
      ll mx2 = max(mx, i);
      dfs(nv,mi2,mx2,v,dfs);
    }
  };

  for(auto [v, i]: edge[0]){
    dfs(v,i,i,0,dfs);
  }
  cout << ans << endl;
}

