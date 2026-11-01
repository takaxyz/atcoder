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

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }


int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<S> v(n+1);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  REP(i,n){
    if(s[i]=='A')seg.apply(i+1,n+1,1);
    else seg.apply(i+1,n+1,-1);
  }

  int q;
  cin >> q;
  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int i;
      char c;
      cin >> i >> c;
      i--;
      if(s[i]=='A')seg.apply(i+1,n+1,-1);
      else seg.apply(i+1,n+1,1);
      s[i]=c;
      if(s[i]=='A')seg.apply(i+1,n+1,1);
      else seg.apply(i+1,n+1,-1);
    }else{
      int l,r;
      cin >> l >> r;
      l--;
      if(seg.prod(l,r+1) == seg.get(l)){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}

