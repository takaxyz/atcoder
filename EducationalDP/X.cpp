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
  int n;
  cin >> n;
  vector<tuple<int,int,int>> b(n);

  REP(i,n){
    int w,s,v;
    cin >> w >> s >> v;
    b[i] = {w,s,v};
  }

  sort(ALL(b), [](const tuple<int,int,int> &x, const tuple<int,int,int> &y){
    auto [w1,s1,v1] = x;
    auto [w2,s2,v2] = y;

    return min(s1, s2-w1) > min(s2, s1-w2);
  });

  const int MAXW = 20000;
  vector dp(n+1, vector<ll>(MAXW+1, -INF));

  dp[0][0] = 0;
  REP(i,n){
    auto [w,s,v] = b[i];

    REP(j,MAXW+1){
      if(dp[i][j]==-INF)continue;
      chmax(dp[i+1][j], dp[i][j]);

      int nj = j + w;
      if(j + w > MAXW)continue;
      if(j > s)continue;
      chmax(dp[i+1][nj], dp[i][j] + v);
    }

  }

  ll ans=0;
  REP(i,MAXW+1)chmax(ans,dp[n][i]);

  cout << ans << endl;


}

