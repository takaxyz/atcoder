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
  vi mi(n+1), mx(n+1), cnt(n+1);
  REP(i,n){
    int x,c;
    cin >> x >> c;
    if(cnt[c] ==0){
      mi[c] = x;
      mx[c] = x;
    }else{
      chmax(mx[c],x);
      chmin(mi[c],x);
    }
    cnt[c]++;
  }
  vector<vector<ll>> dp(n+1, vector<ll>(2, LINF));
  dp[0][0]=0; dp[0][1]=0;
  FOR(i,1,n+1){
    if(cnt[i]){
      chmin(dp[i][0], dp[i-1][0] + abs(mx[i]-mi[i-1]) + abs(mx[i]-mi[i]));
      chmin(dp[i][1], dp[i-1][1] + abs(mi[i]-mx[i-1]) + abs(mx[i]-mi[i]));
      chmin(dp[i][0], dp[i-1][1] + abs(mx[i]-mx[i-1]) + abs(mx[i]-mi[i]));
      chmin(dp[i][1], dp[i-1][0] + abs(mi[i]-mi[i-1]) + abs(mx[i]-mi[i]));
    }else{
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      mi[i] = mi[i-1];
      mx[i] = mx[i-1];
    }
  }
  // FOR(i,1,n+1){
  //   printf("%d %d %d\n", i, dp[i][0], dp[i][1]);
  // }


  cout << min(dp[n][0] + abs(mi[n]), dp[n][1] + abs(mx[n])) << endl;
}

