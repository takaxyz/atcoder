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
using mint = modint998244353;

int main(){
  int n, x;
  cin >> n >> x;
  vi t(n);
  REP(i,n)cin >> t[i];

  // i秒のときに曲の再生が完了している確率
  vector<mint> dp(x+1, 0);

  mint r = mint(1)/n;

  dp[0]=1;
  REP(i,x){
    REP(j,n){
      if(i + t[j] > x)continue;
      dp[i + t[j]] += dp[i] * r;
    }
  }
  mint ans=0;

  //REP(i,x+1)cout << i << " " << dp[i].val() << endl;


  REP(i, t[0]){
    if(x-i>=0)ans += dp[x-i] * r;
  }
  cout << ans.val() << endl;
}

