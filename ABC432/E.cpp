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
  int n,q;
  cin >> n >> q;
  
  const int mx = 500001;
  vi a(n);
  REP(i,n)cin >> a[i];

  fenwick_tree<int> tree1(mx);
  fenwick_tree<ll> tree2(mx);

  REP(i,n){
    tree1.add(a[i], 1);
    tree2.add(a[i], a[i]);
  }

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int x,y;
      cin >> x >> y;
      x--;
      tree1.add(a[x], -1);
      tree2.add(a[x], -a[x]);
      a[x] = y;
      tree1.add(a[x], 1);
      tree2.add(a[x], a[x]);

    }else{
      int l,r;
      cin >> l >> r;
      if(l >= r){
        cout << (ll)l*n << endl;
      }else{
        ll ans=0;
        ans += (ll)tree1.sum(0,l+1) * l;
        ans += tree2.sum(l+1,r);
        ans += (ll)tree1.sum(r,mx) * r;
        cout << ans << endl;

      }

    }
    
  }


}

