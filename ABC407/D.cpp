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

int dx[] = {0,1};
int dy[] = {1,0};

int main(){
  int h,w;
  cin >> h >> w;
  vector a(h,vector<ll>(w));
  REP(i,h)REP(j,w) cin >> a[i][j];

  ll ans = 0;
  vvi d(h, vi(w));

  auto dfs = [&](int p, auto dfs) -> void {
    if(p == h * w){
      ll x=0;
      REP(i,h)REP(j,w){
        if(d[i][j]==0)x ^= a[i][j];
      }
      chmax(ans,x);
      return;
    }

    int x = p / w;
    int y = p % w;

    if(d[x][y]==1){
      dfs(p+1, dfs);
    }else{
      REP(i,2){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= h || ny >= w)continue;
        if(d[nx][ny] == 1)continue;
        d[x][y] = 1;
        d[nx][ny] = 1;
        dfs(p+1, dfs);
        d[x][y] = 0;
        d[nx][ny] = 0;
      }
      dfs(p+1, dfs);
    }
  };

  dfs(0, dfs);
  cout << ans << endl;
}

