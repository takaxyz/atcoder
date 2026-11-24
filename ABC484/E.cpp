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
  ll l,r;
  cin >> n >> l >> r;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];
  vector<ll> sum(n+1);
  REP(i,n)sum[i+1] = sum[i]+a[i];

  vector<ll> vs;
  for(auto x: sum){
    vs.pb(x);
    vs.pb(x+l);
    vs.pb(x+r);
  }
  sort(ALL(vs));
  vs.erase(unique(vs.begin(), vs.end()), vs.end());
  auto f = [&](ll x){
    return (int)(lower_bound(vs.begin(), vs.end(), x) - vs.begin());
  };

  fenwick_tree<int> fw(vs.size()+1);

  ll ans = 0;
  for(int i = n; i > 0; i--){
    fw.add(f(sum[i]), 1);
    int nl = f(l + sum[i-1]);
    int nr = f(r + sum[i-1]);

    ans += fw.sum(nl, nr+1);
    //cout << ans << endl;
  }
  cout << ans << endl;



}

