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



ll pw(ll x, int p){
  ll ret = 1;
  REP(_,p)ret *= x;
  return ret;
}

ll f(ll x){
  string s = to_string(x);

  ll ret = 0;
  int sz = s.size();

  // sz-1桁のもの
  FOR(i,1,10)ret += pw()

  // sz桁
  int n = s[0] - '0';

  for(int m = 1; m < n; m++){
    // m ^ (sz-1-i)
    ll tmp=1;
    REP(_, sz-1-i)tmp *= m;
    ret += tmp;
  }



  return ret;
}

int main(){
  int l,r;

  cin >> l >> r;
  cout << f(r) << endl;
  cout << f(l-1) << endl;

  cout << f(r) - f(l-1) << endl;
}

