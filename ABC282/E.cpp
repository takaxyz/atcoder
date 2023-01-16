#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
const int MOD = 1e9 + 7;

using mint = modint;


using Edge = pair<int, pair<int, int>>;

int f(int x, int y){
  return (modint(x).pow(y) + modint(y).pow(x)).val();
}

int main(){
  int n,m;
  cin >> n >> m;
  mint::set_mod(m);

  vi a(n);
  REP(i,n)cin >> a[i];

  vector<Edge> e;
  REP(i,n)REP(j,i){
    e.emplace_back(f(a[i], a[j]),make_pair(i, j));
  }
  sort(ALL(e));
  reverse(ALL(e));

  dsu uf(n);
  ll ans=0;
  for(auto [w, ee]: e){
    auto [a,b] = ee;
    if(uf.same(a,b))continue;
    ans += w;
    uf.merge(a,b);
  }
  cout << ans << endl;
}

