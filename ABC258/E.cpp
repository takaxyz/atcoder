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

int main(){
  int n,q;
  ll x;
  cin >> n >> q >> x;
  vector<ll> w(n);
  REP(i,n)cin >> w[i];

  ll sw = 0;
  REP(i,n)sw += w[i];

  vector<ll> a(n);
  ll na = x / sw * n;
  ll rem = x % sw;

  REP(i,n){
    while(rem >= 1){
      rem -= w[(i+na)%n];
      na++;
    }
    a[i] = na;
    rem += w[i];
    na--;
  }
  int logK = 42;
  //while((1ll << logK) <= k)logK++;

  vvi dp(logK+1, vi(n));
  REP(i,n)dp[0][i] = (i + a[i])%n;
  REP(i,logK)REP(j,n)dp[i+1][j] = dp[i][dp[i][j]];


  REP(i,q){
    ll k;
    cin >> k;
    k--;
    int now = 0;
    for(int i = logK; i >= 0; i--){
      if((k >> i) & 1)now = dp[i][now];
    }
    cout << a[now] << endl;
  }
}

