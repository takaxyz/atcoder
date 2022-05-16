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
  cin >> n;
  vector<ll> a(n), b(n);
  REP(i,n){
    cin >> a[i];
    if(i==n-1){
      b[0] = a[n-1];
    }else{
      b[i+1] = a[i];      
    }

  }


  vector<ll> dp(n+1,LINF);

  // a0は上げる場合
  dp[0] = a[0];
  dp[1] = a[0];
  FOR(i,1,n){
    chmin(dp[i+1], dp[i] + a[i]);
    chmin(dp[i+1], dp[i-1] + a[i]);
  }

  vector<ll> dp2(n+1,LINF);
  dp2[0] = b[0];
  dp2[1] = b[0];
  FOR(i,1,n){
    chmin(dp2[i+1], dp2[i] + b[i]);
    chmin(dp2[i+1], dp2[i-1] + b[i]);
  }

  ll ans=LINF;
  chmin(ans, dp[n]);
  chmin(ans, dp[n-1]);
  chmin(ans, dp2[n-1]);
  chmin(ans, dp2[n]);

  cout << ans << endl;

}

