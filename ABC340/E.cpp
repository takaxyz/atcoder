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

struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
  int n,m;
  cin >> n >> m;

  vector<S> v(n, {0, 1});
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  REP(i,n){
    ll a;
    cin >> a;
    seg.set(i,{a,1});
  }
  vi b(m);
  REP(i,m)cin >> b[i];


  REP(i,m){
    int p = b[i];

    ll x = seg.prod(p,p+1).value;

    ll c = x / n;

    seg.apply(p, -x);

    seg.apply(0,n,c);

    int m = x % n;
    // p+1 から p+m まで

    if(p+1<n){
      seg.apply(p+1, min(n,p+m+1), 1);
    }

    if(p+m >= n){
      seg.apply(0, p+m+1-n, 1);
    }


  }

  REP(i,n){
    cout << seg.prod(i,i+1).value << endl;
  }

}
