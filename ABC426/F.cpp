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

using S = long long;
using F = long long;

S op(S a, S b){ return std::min(a, b); }
S e(){ return LINF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

bool G(ll x){ return x >= 0;}

int main(){
  int n;
  cin >> n;
  fenwick_tree<int> fw(n);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  REP(i,n){
    ll a;
    cin >> a;
    seg.set(i,a);
    fw.add(i,1);
  }
  int q;
  cin >> q;
  REP(_,q){
    int l,r;
    ll k;
    cin >> l >> r >> k;
    l--;
    ll ans=0;
    ans = k * fw.sum(l,r);
    seg.apply(l,r,-k);
    int pos = seg.max_right(l, G);
    while(pos<n){
      int val = seg.get(pos);
      ans += val;
      seg.set(pos, LINF);
      fw.add(pos,-1);
      pos = seg.max_right(l, G);
    }
    cout << ans << endl;


  }
}

