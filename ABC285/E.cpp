#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINTV(a)  REP(i,(int)a.size())cout << a[i] << (i == (int)a.size()-1 ? "\n" : " ")
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
  vector<ll> a(n);
  REP(i,n)cin >> a[i];
  vector<ll> b(n);
  FOR(i,1,n)b[i] = b[i-1]+a[(i-1)/2];

  vector<ll> dp(n+1);

  // dp[i] : i日を休日とした場合の最大値(0-index)
  
  // PRINTV(a);
  // PRINTV(b);

  FOR(i,1,n+1){
    REP(j,i){
      chmax(dp[i], dp[j] + b[i-j-1]);
    }
  }

  // PRINTV(dp);

  cout << dp[n] << endl;

}

