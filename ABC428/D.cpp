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
ll f (ll x) {
	ll y = sqrt(x);
	while (y * y > x) y--;
	while ((y+1) * (y+1) <= x) y++;
	return y;
}

void solve(){
  ll c,d;
  cin >> c >> d;

  ll ans = 0;
  for(int i = 0; i < 10; i++){
    ll m = 10;
    REP(_,i)m *= 10;
    ll r = m - 1;
    ll l = m/10;

    if(c+1 > r)continue;
    if(l > c+d)continue;

    chmin(r,c+d);
    chmax(l,c+1);

    ans += f(c*m + r);
    ans -= f(c*m + l - 1);
  }
  cout << ans << endl;


}


int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

