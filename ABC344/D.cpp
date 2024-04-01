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

int main(){
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector s(n, vector<string>());
  REP(i,n){
    int a;
    cin >> a;
    s[i] = vector<string> (a);
    REP(j,a)cin >> s[i][j];
  }

  int sz = t.size();
  vvi dp(n+1, vi(sz+1, INF));

  dp[0][0]=0;

  REP(i,n){
    REP(j,sz+1){
      if(dp[i][j]==INF)continue;

      chmin(dp[i+1][j], dp[i][j]);

      for(auto x: s[i]){
        if(sz - j < x.size())continue;

        if(t.substr(j, x.size()) == x){
          chmin(dp[i+1][j + x.size()],dp[i][j]+1);
        }
      }
    }
  }
  // REP(i,n+1)REP(j,sz+1){
  //   cout << i << " " << j << " " << dp[i][j] << endl;
  // }

  if(dp[n][sz]==INF)cout << -1 << endl;
  else cout << dp[n][sz] << endl;
}

