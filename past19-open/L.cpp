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

int op(int a, int b) {
  return max(a, b);
}

int e() {
  return (int)(-1);
}

int main(){
  int n;
  cin >> n;
  vi b(n);
  REP(i,n)cin >> b[i];

  vi c = b;
  sort(ALL(c));
  c.erase(unique(ALL(c)),c.end());

  segtree<int, op, e> dp0(n); // >
  segtree<int, op, e> dp1(n); // <

  REP(i,n){
    int p = lower_bound(ALL(c),b[i]) - c.begin();
    int x = max(0,dp0.prod(0,p));
    dp1.set(p,max(dp1.get(p), x+1));
    x = max(0,dp1.prod(p+1,n));
    dp0.set(p,max(dp0.get(p), x+1));
  }
  cout << max(dp0.prod(0,n), dp1.prod(0,n)) << endl;
}

