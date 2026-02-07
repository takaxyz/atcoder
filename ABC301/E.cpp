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

  vector<P> sw;
  int si=-1,sj=-1,gi=-1,gj=-1;
  REP(i,h)REP(j,w){
    if(a[i][j]=='o')sw.pb({i,j});
    if(a[i][j]=='S'){si =i; sj = j;}
    if(a[i][j]=='G'){gi=i,gj=j;}
  }


  auto get_dist = [&](int si, int sj) -> vvi {
    vvi dist(h,vi(w,INF));

    queue<P> q;
    dist[si][sj] = 0;
    q.push({si,sj});

    while(q.size()){
      auto [i,j] = q.front();
      q.pop();

      REP(k,4){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
        if(a[ni][nj]=='#')continue;
        if(dist[ni][nj]!=INF)continue;
        dist[ni][nj] = dist[i][j]+1;
        q.push({ni,nj});
      }
    }
    return dist;
  };

  vector<vvi> ds;

  for(auto [i,j]: sw){
    ds.pb(get_dist(i,j));
  }

  int sz = sw.size();
  vector dp(1 << sz, vi(sz, INF));

  vvi d1 = get_dist(si,sj);
  vvi d2 = get_dist(gi,gj);

  REP(i,sz)dp[1<<i][i] = d1[sw[i].first][sw[i].second];

  REP(k,1<<sz){
    REP(u,sz)REP(v,sz){
      int vi = sw[v].first;
      int vj = sw[v].second;

      if(((k >> u) & 1) == 0)continue;
      if(((k >> v) & 1) == 1)continue;

      int nk = k | (1<<v);

      chmin(dp[nk][v], dp[k][u] + ds[u][vi][vj]);
    }
  }

  if(d1[gi][gj] > t){
    cout << -1 << endl;
    return 0;
  }


  int ans = 0;
  REP(k,1<<sz){
    int x = __builtin_popcount(k);

    REP(i,sz){
      if(dp[k][i] + d2[sw[i].first][sw[i].second] <= t)chmax(ans,x);
    }
  }
  cout << ans << endl;
}

