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

  vi a(n),b(n);
  REP(i,n)cin >> a[i] >> b[i];

  int sum = 0;
  REP(i,n)sum += b[i];
  if(sum % 3 > 0){
    cout << -1 << endl;
    return 0;
  }

  vvi dp(sum/3+1, vi(sum/3+1, INF));
  dp[0][0] = 0;

  int s = 0;
  REP(i,n){
    vvi dp2(sum/3+1, vi(sum/3+1, INF));

    s += b[i];

    REP(j,sum/3+1)REP(k,sum/3+1){
      if(dp[j][k]==INF)continue;

      // team 1
      if(a[i]==1){
        if(j+b[i]<=sum/3)chmin(dp2[j+b[i]][k],dp[j][k]);
      }else{
        if(j+b[i]<=sum/3)chmin(dp2[j+b[i]][k],dp[j][k]+1);
      }

      // team 2
      if(a[i]==2){
        if(k+b[i]<=sum/3)chmin(dp2[j][k+b[i]],dp[j][k]);
      }else{
        if(k+b[i]<=sum/3)chmin(dp2[j][k+b[i]],dp[j][k]+1);
      }

      // team 3
      if(a[i]==3){
        if(s - j - k<=sum/3)chmin(dp2[j][k],dp[j][k]);
      }else{
        if(s - j - k<=sum/3)chmin(dp2[j][k],dp[j][k]+1);
      }

    }

    swap(dp,dp2);

    //REP(j,sum/3+1)REP(k,sum/3+1)printf("%d %d %d : %d\n",i,j,k,dp[j][k]);
  }

  cout << (dp[sum/3][sum/3] == INF ? -1 : dp[sum/3][sum/3]) << endl;
}

