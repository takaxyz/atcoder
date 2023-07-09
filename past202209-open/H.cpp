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
  int n,x;
  cin >> n >> x;
  vi a(n),b(n),c(n);
  REP(i,n)cin >> a[i] >> b[i] >> c[i];

  vector<vector<P>> dp(n+1,vector<P>(x+1, {-INF, -INF}));

  dp[0][x] = {0,1000000000};
  REP(i,n){
    REP(j,x+1){
      if(dp[i][j].first == -INF) continue; 

      if(j - b[i] >= 0 && dp[i][j].second - a[i] >= 0){
        if(dp[i+1][j-b[i]].first < dp[i][j].first + c[i])dp[i+1][j-b[i]] = {dp[i][j].first + c[i], dp[i][j].second - a[i]};
        else if(dp[i+1][j-b[i]].first == dp[i][j].first + c[i] && dp[i+1][j-b[i]].second < dp[i][j].second - a[i])dp[i+1][j-b[i]] = {dp[i][j].first + c[i], dp[i][j].second - a[i]};    
      }

      if(dp[i+1][j].first < dp[i][j].first)dp[i+1][j] = dp[i][j];
      else if(dp[i+1][j].first == dp[i][j].first && dp[i+1][j].second < dp[i][j].second)dp[i+1][j] = dp[i][j];

    }
  }

  int id = -1;
  int mg = 0;
  int ms = 0;
  REP(i,x+1){
    if(mg < dp[n][i].first){
      mg = dp[n][i].first;
      ms = dp[n][i].second;
      id = i;
    }else if(mg == dp[n][i].first && ms <= dp[n][i].second){
      mg = dp[n][i].first;
      ms = dp[n][i].second;
      id = i;
    }
  }

  cout << dp[n][id].first << " " << dp[n][id].second << " " << id << endl;


}

