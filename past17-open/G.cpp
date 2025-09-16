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
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {0,-1,1,1,-1,1,0,-1};

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> g(h);
  REP(i,h)cin >> g[i];
  int n;
  string s;
  cin >> n >> s;

  vvi visited(h,vi(w,0));

  auto dfs = [&](int i, int j, int d, auto dfs) -> void{
    if(d==n){
      cout << "Yes" << endl;
      exit(0);
    }

    visited[i][j] = 1;

    REP(k,8){
      int ni = i + dx[k];
      int nj = j + dy[k];
      if(ni < 0 || ni >= h || nj <0 || nj >=w)continue;
      if(visited[ni][nj])continue;
      if(g[ni][nj]==s[d])dfs(ni,nj,d+1,dfs);
    }
    visited[i][j] = 0;

  };
  
  REP(i,h)REP(j,w){
    if(g[i][j]==s[0])dfs(i,j,1,dfs);
  }

  cout << "No" << endl;
}

