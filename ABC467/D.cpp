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

tuple<ll,ll,ll> f(ll px, ll py, ll qx, ll qy){
  ll a = 2 * (px -  qx);
  ll b = 2 * (py - qy);
  ll c = -px * px - py * py + qx * qx + qy * qy;

  ll g = gcd(gcd(a,b),c);

  a /= g;
  b /= g;
  c /= g;

  if(a < 0){ a = -a; b = -b; c = -c; }

  if(a == 0 && b < 0){b = -b; c = -c; }

  return {a,b,c};
}


int main(){
  int t;
  cin >> t;
  REP(_,t){
    ll px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

    auto [a1,b1,c1] = f(px,py,qx,qy);
    auto [a2,b2,c2] = f(rx,ry,sx,sy);

    if(a1 * b2 == a2 * b1){
      if(a1 == a2 && b1 == b2 && c1 == c2){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else{
      cout << "Yes" << endl;
    }
  }

}

