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

ll op1(ll x, ll y){
  return max(x,y);
}

ll e1(){
  return (ll)-LINF;
}

ll op2(ll x, ll y){
  return min(x,y);
}

ll e2(){
  return (ll)LINF;
}

int main(){
  int n,q;
  cin >> n >> q;
  segtree<ll,op1,e1> mx1(n), mx2(n);
  segtree<ll,op2,e2> mi1(n), mi2(n);

  REP(i,n){
    int x,y;
    cin >> x >> y;
    mx1.set(i,x+y);
    mi1.set(i,x+y);
    mx2.set(i,x-y);
    mi2.set(i,x-y);
  }

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int i;
      ll x,y;
      cin >> i >> x >> y;
      i--;
      mx1.set(i,x+y);
      mi1.set(i,x+y);
      mx2.set(i,x-y);
      mi2.set(i,x-y);

    }else{
      int l,r;
      ll x,y;
      cin >> l >> r >> x >> y;
      l--;
      ll ans = -1;
      chmax(ans,abs(mx1.prod(l,r) - x - y));
      chmax(ans,abs(mi1.prod(l,r) - x - y));
      chmax(ans,abs(mx2.prod(l,r) - x + y));
      chmax(ans,abs(mi2.prod(l,r) - x + y));
      cout << ans << endl;
    }



  }

}

