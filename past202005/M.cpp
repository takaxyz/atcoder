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
  vvi edge(n,vi());
  REP(_,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }

  int s,k;

  cin >> s >> k;
  k++;
  vi t(k);
  s--;
  t[0]=s;
  REP(i,k-1)cin >> t[i+1], t[i+1]--;

  vvi dist(k, vi(k));

  REP(i,k){
    vi d(n,INF);

    queue<int> q;
    q.push(t[i]);
    d[t[i]]=0;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto nv: edge[v]){
        if(d[nv]!=INF)continue;
        d[nv] = d[v] + 1;
        q.push(nv);
      }
    }
    REP(j,k){
      dist[i][j] = d[t[j]];
    }
  }

  // REP(i,k)REP(j,k){
  //   printf("%d %d: %d\n",i,j,dist[i][j]);
  // }

  vector dp(1<<k, vector<ll>(k,LINF));
  dp[1][0]=0;
  FOR(i,1,1<<k){

    REP(x,k)REP(y,k){
      if(x==y)continue;
      if((i & (1<<x)) == 0)continue;
      if((i * (1<<y)) == 1)continue;
      chmin(dp[i | (1<<y)][y], dp[i][x] + dist[x][y]);
    } 
  }
  ll ans = LINF;
  REP(i,k)chmin(ans,dp[(1<<k)-1][i]);
  cout << ans << endl;
}

