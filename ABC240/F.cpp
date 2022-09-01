#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
const int MOD = 1e9 + 7;

void solve(){
  int n,m;
  cin >> n >> m;

  ll a = 0, b = 0;
  ll ans = -LINF;;
  REP(_, n){
    ll x, y;
    cin >> x >> y;

    chmax(ans,a+b+x);
    if(b > 0 && x < 0){
      ll ni = b / -x;
      if(ni < y){
        chmax(ans, a + b * ni + x * ni * (ni+1)/2);
      }
    }
    a += b * y + x * y * (y+1) / 2;
    b += x * y;
    chmax(ans, a);

  }
  cout << ans << endl;
}




int main(){
  int t;
  cin >> t;
  REP(_,t){
    solve();
  }
}

