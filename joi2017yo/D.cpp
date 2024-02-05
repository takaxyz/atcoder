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
const int MOD = 1e9 + 7;

int main(){
  int n, m;
  cin >> n >> m;

  vi a(n);
  vi cnt(m);
  vvi sum(m, vi(n+1));
  REP(i,n){
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
    sum[a[i]][i+1] = 1;
  }

  REP(i,m)REP(j,n)sum[i][j+1] += sum[i][j];

  // REP(i,m)REP(j,n+1){
  //   cout << i << " " << j << " " << sum[i][j] << endl;
  // }
  

  vector<int> dp(1<<m, INF);
  dp[0]=0;

  REP(s, 1<<m ){
    int p=0;
    REP(i,m){
      if((s>>i) & 1)p += cnt[i];
    }

    REP(i,m){
      if((s>>i) & 1)continue;
      // [sum, sum+cnt[i]) に i がいくつあるか = x

      int x = sum[i][p+cnt[i]] - sum[i][p];

      //cout << x << endl;
      chmin(dp[s | (1<<i)], dp[s]+cnt[i]-x);

    }
  }
  // REP(i, 1<<m){
  //   cout << i << " " << dp[i] << endl;
  // }
  cout << dp[(1<<m)-1] << endl;
}

