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

//using mint = modint1000000007;
using mint = modint998244353;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  vi a(n);
  REP(i,n)cin >> a[i];
  vector<ll> s(n+1);
  REP(i,n)s[i+1] = s[i] + a[i];

  vector<mint> dp(n+1);
  dp[0]=1;

  mint all = dp[0];

  map<ll, mint> mp;
  mp[s[0]] = dp[0];

  REP(i,n){
    dp[i+1] = all;
    if(mp.count(s[i] - k + a[i]))dp[i+1] -= mp[s[i] - k + a[i]];  
    mp[s[i+1]] += dp[i+1];
    all += dp[i+1];
  }
  cout << dp[n].val() << endl;
}

