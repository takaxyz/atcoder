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

ll f(ll x, ll y){
  ll rx = x % 4;
  x -= rx;
  ll ry = y % 2;
  y -= ry;

  ll ret = (x / 4) * (y / 2) * 8;

  if(ry)ret += 4 * (x / 4);

  if(rx > 0){
    ret += y / 2 * 3;
    if(ry)ret += 2;
  }
  if(rx > 1){
    ret += y / 2 * 3;
    if(ry)ret += 1;
  }
  if(rx > 2){
    ret += y / 2;
  }

  return ret;

}

int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;

  a += 1e9;
  b += 1e9;
  c += 1e9;
  d += 1e9;

  cout << f(c,d) - f(a,d) - f(c,b) + f(a,b) << endl;

}

