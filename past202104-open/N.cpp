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
  int n,h;
  cin >> n >> h;
  vector<pair<ll,ll>> ab(n);
  REP(i,n){
    cin >> ab[i].first >> ab[i].second;
  }

  sort(ALL(ab), [](auto const x,auto const y){
    return x.first * y.second > x.second * y.first;
  });

  vector dp(n+1,vector<ll>(h+1,-LINF));

  dp[0][h]=0;
  REP(i,n){
    REP(j,h+1){
      if(dp[i][j]==-LINF)continue;

      chmax(dp[i+1][j], dp[i][j]);

      int nj = max(0LL, j-ab[i].second);
      chmax(dp[i+1][nj], dp[i][j] + (ll)j * ab[i].first);
    }
  }

  ll ans=-LINF;
  REP(i,h+1)chmax(ans, dp[n][i]);

  cout << ans << endl;

}

