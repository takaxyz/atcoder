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
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n)cin >> s[i];
  vvi c(n,vi(n+1));

  REP(i,n){
    int cnt_b = 0;
    int cnt_w = 0;
    REP(j,n)if(s[i][j]=='.')cnt_w++;
    REP(j,n+1){
      c[i][j] = cnt_b + cnt_w;
      if(j<n && s[i][j] == '.')cnt_w--;
      if(j<n && s[i][j] == '#')cnt_b++;
    }
  }
  // REP(i,n)REP(j,n+1){
  //   cout << c[i][j] << (j==n ? "\n" : " ");
  // }

  vi dp = c[0];

  FOR(i,1,n){
    vi old(n+1);
    swap(old,dp);

    int mi = INF;
    for(int j = n; j >=0; j--){
      chmin(mi,old[j]);
      dp[j] = c[i][j] + mi;
    }
  }

  int ans = INF;
  for(auto x: dp)chmin(ans,x);
  cout << ans << endl;

}

