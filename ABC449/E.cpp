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

ll op(ll a, ll b) {
    return a+b;
}

ll e() {
    return (ll)(0);
}

int main(){
  int n,m;
  cin >> n >> m;

  vi a(n);
  segtree<ll, op, e> seg(m);

  vi cnt(m);
  REP(i,n){
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }


  int q;
  cin >> q;
  vector<pair<ll,int>> vs;

  vi ans(q);

  REP(i,q){
    ll x;
    cin >> x;
    x--;
    if(x < n)ans[i] = a[x];
    else vs.pb({x, i});
  }
  sort(RALL(vs));

  vvi adds(n+1);
  REP(i,m){
    adds[cnt[i]].pb(i);
  }

  int num = 0;
  ll l = n;
  REP(i,n+1){
    for(auto j: adds[i]){
      seg.set(j, 1);
      num++;
    }

    while(vs.size() && vs.back().first < l + num){
      auto [x, qi] = vs.back();
      vs.pop_back();
      ans[qi] = seg.max_right(0, [&](ll y) { return y <= x-l;});
    }
    l += num;
  }

  while(vs.size()){
    auto [x, qi] = vs.back();
    vs.pop_back();
    ans[qi] = (x - l)%m;
  }

  for(auto x: ans)cout << x + 1 << endl;

}

