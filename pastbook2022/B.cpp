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
  int n,m;
  cin >> n >> m;

  string s,t;
  cin >> s >> t;

  vvi dp(n+1, vi(m+1,INF));
  dp[0][0]=0;

  REP(i,n+1)REP(j,m+1){
    // 変更
    if(i < n && j < m){
      if(s[i]==t[j]){
        chmin(dp[i+1][j+1], dp[i][j]);
      }else{
        chmin(dp[i+1][j+1], dp[i][j]+1);
      }
    } 

    // 削除
    if(i<n)chmin(dp[i+1][j], dp[i][j]+1);

    // 挿入
    if(j<m)chmin(dp[i][j+1], dp[i][j]+1);

  }
  cout << dp[n][m] << endl;

}

