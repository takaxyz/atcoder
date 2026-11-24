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

ll op1(ll a, ll b) { return max(a, b); }

ll e1() { return -LINF; }

ll op2(ll a, ll b) { return min(a, b); }

ll e2() { return LINF; }

int main(){
  int n,q;
  cin >> n >> q;
  segtree<ll, op1, e1> seg1(n);
  segtree<ll, op2, e2> seg2(n);

  REP(i,n){
    ll a;
    cin >> a;
    if(a != -1){
      seg1.set(i,a);
      seg2.set(i,a);
    }
  }

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int i;
      ll x;
      cin >> i >> x;
      i--;
      if(x==-1){
        seg1.set(i,e1());
        seg2.set(i,e2());
      }else{
        seg1.set(i,x);
        seg2.set(i,x);
      }
    }else{
      int l,r;
      cin >> l >> r;
      l--;
      if(seg1.prod(l,r) == seg2.prod(l,r) || (seg1.prod(l,r) == e1() && seg2.prod(l,r) == e2())){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }

  }



}

