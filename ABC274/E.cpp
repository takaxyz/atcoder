#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

const double INF = 1e18;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int n,m;
  cin >> n >> m;
  int N=n+m+1;
  vector<double> x(N,0),y(N,0);
  REP(i,n+m)cin >> x[i+1] >> y[i+1];

  int S = 1 << N;

  vector<vector<double>> dp(S, vector<double>(N,INF));
  dp[0][0]=0;

  vector<vector<double>> dist(N, vector<double>(N));
  REP(i,N)REP(j,N){
    dist[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  }


  vector<double> sp(S, 1.0);
  REP(s, S){
    REP(i, m)if( (s >> (n+1+i)) & 1) sp[s] /= 2;
  }

  REP(s, S){
    // u -> v
    REP(u, N){
      if(dp[s][u]==INF)continue;
      
      REP(v, N){

        if( (s>>v) & 1)continue;
        if(u==v)continue;

        chmin(dp[ s | (1<<v)][v], dp[s][u] + dist[u][v] * sp[s]);

      }
    }
  }

  double ans = INF;
  int t = (1<<(n+1))-1;
  REP(s,S){
    if((s & t) == t)chmin(ans, dp[s][0]);
  }
  printf("%.10f\n",ans);

}

