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
  vvi edge(n);

  REP(i,n-1){
    int p;
    cin >> p;
    edge[p-1].pb(i+1);
  }

  vvi ds(n);
  int c = 0;
  vi id1(n), id2(n);
  auto dfs = [&](int v, int dep, auto dfs) -> void{
    ds[dep].pb(c);
    id1[v] = c++;
    for(auto nv: edge[v]){
      dfs(nv, dep+1, dfs);
    }
    id2[v] = c;
  };

  dfs(0, 0, dfs);

  // REP(i,ds.size()){
  //   cout << i << endl;
  //   for(auto x: ds[i])cout << " " << x << endl;
  // }


  int q;
  cin >> q;
  REP(_,q){
    int u, d;
    cin >> u >> d;
    u--;
    //cout << ":: " << id1[u] << " " << id2[u] << endl;
    auto it1 = ds[d].end() - lower_bound(ALL(ds[d]), id1[u]);
    auto it2 = ds[d].end() - lower_bound(ALL(ds[d]), id2[u]);
    cout << it1  -  it2 << endl;

  }
}
