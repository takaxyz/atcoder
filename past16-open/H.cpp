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
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];
  vector dp(m+1,vector<ll>(2, -1));

  dp[0][0]=0;
  REP(i,n){
    vector old(m+1,vector<ll>(2, -1));
    swap(old,dp);
    REP(j,m+1){
      if(old[j][0]!=-1){
        chmax(dp[j][0], old[j][0] + a[i]);
        chmax(dp[min(m,j+1)][1], old[j][0]);
      }
      if(old[j][1]!=-1){
        chmax(dp[j][0], old[j][1] + a[i]);
      }
    }
    //REP(j,m+1)REP(k,2)printf("%d %d %d\n", i+1, j, k, dp[j][k]);
  }
  cout << max(dp[m][0], dp[m][1]) << endl;
}

