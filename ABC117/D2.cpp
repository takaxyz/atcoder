#include <bits/stdc++.h>
using namespace std;

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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  vi b(50);
  REP(i,n){
    REP(j,50){
      b[j] += (a[i] >> j) & 1;
    }
  }

  // REP(i,50){
  //   cout << i << " " << b[i] << endl;
  // }

  int cnt = 0;
  ll kk=k;
  REP(i,50){
    if(kk > 0)cnt=i+1;
    kk = kk >> 1;
  }

  vector<vector<ll>> dp(50, vector<ll>(2));

  for(int i = 0; i < cnt; i++){
    int ii = cnt - 1  - i;
    int d = ( k >> ii ) & 1;
    for(int smaller=0; smaller<2; smaller++){
      for(int di = 0; di <= (smaller ? 1 : d) ; di++){
        chmax(dp[i+1][smaller || di < d], dp[i][smaller] + (1L << ii) * ( di ? b[ii] : n - b[ii]));
      }
    }
  }

  if(k==0){
    ll ans = 0;
    REP(i,n)ans += a[i];
    cout << ans << endl;
    return 0;
  }

  cout << max(dp[cnt][0], dp[cnt][1]) << endl;
}

