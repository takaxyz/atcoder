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

//using mint = modint1000000007;
using mint = modint998244353;


// 区間加算・区間の0乗和、1乗和、2乗和を求める
struct S {
  mint s0, s1, s2;
};
S op(S a, S b) {
  return S(a.s0+b.s0, a.s1+b.s1, a.s2+b.s2);
}
S e() { return S(0,0,0);}

S mapping(mint f, S x) {
  x.s2 += x.s1*f*2 + x.s0*f*f;
  x.s1 += x.s0*f;
  return x;
}
mint composition(mint f, mint g) { return f+g;}
mint id() { return 0;}


int main(){
  int n,q;
  cin >> n >> q;

  lazy_segtree<S, op, e, mint, mapping, composition, id> seg(vector<S>(n, S(1,0,0)));

  REP(_,q){
    int l,r,a;
    cin >> l >> r >> a;
    l--;
    seg.apply(l,r,mint(a));

    S s = seg.prod(l,r);
    cout << ((s.s1 * s.s1 - s.s2) / 2).val() << endl;
  }
}

