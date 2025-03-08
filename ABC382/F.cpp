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

//const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

using mint = modint1000000007;
// using mint = modint998244353;

using S = int;
using F = int;

const S INF = 1001001001;
const F ID = 1001001001;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vi r(n),c(n),l(n);
  REP(i,n){
    cin >> r[i] >> c[i] >> l[i];
  }

  vi ord(n);
  REP(i,n)ord[i]=i;

  auto comp = [&](int a, int b){ return r[a] > r[b]; };
  sort(ALL(ord), comp);
//  for(auto x: ord) cout << x << endl;
  vector<S> v(w+1, h+1);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  vi ans(n);
  REP(i,n){
    int id = ord[i];
    ans[id] = seg.prod(c[id], c[id]+l[id]) - 1;
    seg.apply(c[id], c[id]+l[id],ans[id]);
  }

  for(auto x: ans)cout << x << endl;

}

