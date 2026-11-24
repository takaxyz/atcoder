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

void solve(){
  int n;
  cin >> n;
  vvi edge(n,vi());
  vi d(n);

  REP(_,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
    d[a]++; d[b]++;
  }

  vi dp(n);
  int ans=1;
  auto dfs = [&](auto dfs, int v, int p=-1) -> int{

    vi vs;

    for(auto nv: edge[v]){
      if(nv == p)continue;
      vs.pb(dfs(dfs, nv, v));
    }
    sort(ALL(vs));
    reverse(ALL(vs));

    if(d[v]>=4){
      chmax(ans, vs[0] + vs[1] + 1);

      return vs[0] + 1;
    }

    if(d[v]==3){
      chmax(ans, vs[0] + 1);

      return 1;
    }
    return 0;
  };

  dfs(dfs,0,-1);
  cout << ans << endl;
}



int main(){
  int q;
  cin >> q;
  REP(_,q)solve();
}

