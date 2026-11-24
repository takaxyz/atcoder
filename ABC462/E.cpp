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

void solve(){
  ll a,b,x,y;
  cin >> a >> b >> x >> y;

  auto f = [&](ll a, ll b, ll x, ll y){
    x = abs(x);
    y = abs(y);
    if(x > y)swap(x,y);
    if(a > b)swap(a,b);
    return min(a*x*2 + (y-x)/2*(a+b), y*a*2);
  };

  if((x+y)%2==0){
    cout << f(a,b,x,y) << endl;
  }else{
    ll ans=f(a,b,x-1,y)+a;
    chmin(ans, f(a,b,x+1,y)+a);
    chmin(ans, f(a,b,x,y-1)+b);
    chmin(ans, f(a,b,x,y+1)+b);
    cout << ans << endl;
  }
}

int main(){
  int t;
  cin >> t;
  REP(_,t)solve();

}

