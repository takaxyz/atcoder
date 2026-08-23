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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int h,w,t;
  cin >> h >> w >> t;

  vector<string> a(h);
  REP(i,h)cin >> a[i];

  vector<P> node;
  REP(i,h)REP(j,w)if(a[i][j]=='S')node.pb({i,j});
  REP(i,h)REP(j,w)if(a[i][j]=='o')node.pb({i,j});
  REP(i,h)REP(j,w)if(a[i][j]=='G')node.pb({i,j});

  int n = node.size();

  vector d(n,vvi(h,vi(w,INF)));
  REP(s,n){
    d[s][node[s].first][node[s].second]=0;
    queue<P> q;
    q.push({node[s].first, node[s].second});

    while(q.size()){
      auto[i,j] = q.front();
      q.pop();
      REP(k,4){
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
        if(a[ni][nj]=='#')continue;
        if(d[s][ni][nj]!=INF)continue;

        chmin(d[s][ni][nj], d[s][i][j]+1);
        q.push({ni,nj});
      }
    }
  }
  
  vvi dp((1<<n), vi(n, INF));

  dp[1][0]=0;

  REP(i, (1<<n))REP(u,n)REP(v,n){
    if(((i>>u) & 1) == 0 || ((i>>v) & 1) == 1)continue;
    int ni = i | (1<<v);
    chmin(dp[ni][v], dp[i][u] + d[u][node[v].first][node[v].second]);
  }

  int ans=-1;
  REP(i, (1<<n)){
    if(dp[i][n-1] > t)continue;
    chmax(ans, __builtin_popcount(i) - 2);
  }
  cout << ans << endl;  

}

