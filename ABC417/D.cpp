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
  vector<tuple<int,int,int>> P(n);
  int mx=0;
  REP(i,n){
    int p,a,b;
    cin >> p >> a >> b;
    P[i] = {p,a,b};
    chmax(mx,p+a);
  }
  vvi dp(n+1,vi(mx+1));

  REP(i,mx+1)dp[n][i]=i;

  for(int i = n-1; i >=0; i--){
    auto [p,a,b] = P[i];
    REP(j,mx+1){
      if(j <= p){
        dp[i][j] = dp[i+1][j+a];
      }else{
        dp[i][j] = dp[i+1][max(0,j-b)];
      }
    }
  }

  // REP(i,n+1)REP(j,mx+1){
  //   printf("%d %d: %d\n",i,j,dp[i][j]);
  // }

  vi sb(n+1);
  REP(i,n)sb[i+1] = sb[i]+ get<2>(P[i]);

  //for(auto x: sb)cout << x << endl;

  int q;
  cin >> q;
  REP(_,q){
    int x;
    cin >> x;

    if(x > mx){
      int id = lower_bound(ALL(sb), x-mx) - sb.begin();
      if(id <= n){
        cout << dp[id][x - min(x,sb[id])] << endl;
      }else{
        cout << x - sb.back() << endl;
      }


    }else{
      cout << dp[0][x] << endl;
    }

  }


}

