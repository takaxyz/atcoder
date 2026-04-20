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
using P = pair<int,int>;
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

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];

  vvi edge(n);
  REP(_,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }

  map<int,int> mp;
  int cnt=0;
  vi ans(n);
  auto dfs = [&](int v, int p, auto dfs) -> void {
    mp[a[v]]++;
    if(mp[a[v]] == 2)cnt++;

    ans[v] = cnt;

    for(auto nv: edge[v]){
      if(nv == p)continue;
      dfs(nv,v,dfs);
    }

    mp[a[v]]--;
    if(mp[a[v]] == 1)cnt--;
  };

  dfs(0,-1,dfs);

  REP(i,n)cout << (ans[i] ? "Yes" : "No") << endl;
}

