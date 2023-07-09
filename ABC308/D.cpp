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
const int MOD = 1e9 + 7;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  string sn = "snukes";

  vvi visited(h, vi(w,0));

  auto dfs = [&](auto dfs,int x, int y) -> void{
    visited[x][y]=1;
    if(x == h-1 && y == w-1){
      return;
    }
    char c = s[x][y];
    int p = sn.find(c);
    char nxt = sn[p+1];

    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= h || ny <0 || ny >= w)continue;

      if(s[nx][ny]!=nxt)continue;
      if(visited[nx][ny])continue;
      dfs(dfs,nx,ny);
    }

  };

  if(s[0][0]!='s'){
    cout << "No" << endl;
    return 0;
  }

  dfs(dfs,0,0);
  cout << (visited[h-1][w-1] == 1 ? "Yes" : "No") << endl;
}

