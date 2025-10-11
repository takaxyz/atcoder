#include <bits/stdc++.h>
#include <atcoder/all>
#include <optional>
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

//using mint = modint1000000007;
using mint = modint998244353;

struct S{
    mint value;
    int size;
};
using F = optional<mint>;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f) x.value = *f *x.size;
    return x;
}
F composition(F f, F g){ return (f  ? f : g); }
F id(){ return nullopt; }

int main(){
  int n,m;
  cin >> n >> m;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  REP(i,n){
    ll a;
    cin >> a;
    seg.set(i,{mint(a),1});
  }
  REP(_,m){
    int l,r;
    cin >> l >> r;
    l--;
    mint x = seg.prod(l,r).value;
    x /= r-l;
    seg.apply(l,r,x);
  }
  REP(i,n){
    cout << seg.get(i).value.val() << endl;
  }
}

