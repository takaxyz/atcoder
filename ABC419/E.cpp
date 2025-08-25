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
  int n,m,l;
  cin >> n >> m >> l;
  vi a(n);
  REP(i,n)cin >> a[i];

  vvi cost(l,vi(m));

  REP(i,l){
    REP(j,m){
      for(int k = i; k < n; k+=l){
        cost[i][j] += (j + m - a[k]) % m;
      }
    }
  }

  // REP(i,l)REP(j,m){
  //   printf("%d %d: %d\n",i,j,cost[i][j]);
  // }

  vi dp = cost[0];
  REP(i,l-1){
    vi old(m,INF);
    swap(old,dp);
    REP(j,m){
      REP(k,m){
        chmin(dp[(j+k)%m], old[j] + cost[i+1][k]);
      }
    }
  }
  cout << dp[0] << endl;
}

