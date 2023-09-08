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

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  REP(i,h)cin >> a[i];

  auto in = [&](int i, int j) -> bool {
    return (i >= 0 && i < h && j >= 0 && j < w);
  };

  string dir = "^v><";
  int dx[] ={-1,1,0,0};
  int dy[] ={0,0,1,-1};

  vvi viewd(h,vi(w,0));

  int sx = -1;
  int sy = -1;
  int gx = -1;
  int gy = -1;
  REP(i,h)REP(j,w){
    if(a[i][j]=='S')sx = i, sy = j;
    if(a[i][j]=='G')gx = i, gy = j;
  }

  REP(k,4)REP(i,h)REP(j,w){
    if(a[i][j]!=dir[k])continue;

    int nx = i;
    int ny = j;
    while(1){
      nx += dx[k];
      ny += dy[k];

      if(!in(nx,ny))break;

      if(a[nx][ny]!='.')break;

      viewd[nx][ny]=1;
    }
  }
  vvi dist(h, vi(w,-1));

  queue<P> q;
  q.push({sx,sy});
  dist[sx][sy]=0;

  while(!q.empty()){
    auto [x,y] = q.front();
    //cout << x << " " << y << endl;
    q.pop();

    REP(k,4){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(!in(nx,ny))continue;

      if(a[nx][ny]!='.' && a[nx][ny]!='G')continue;
      if(viewd[nx][ny])continue;
      if(dist[nx][ny]!=-1)continue;

      q.push({nx,ny});
      dist[nx][ny]=dist[x][y]+1;
    }

  }

  // REP(i,h)REP(j,w){
  //   cout << i << " " << j << " " << viewd[i][j] << endl;
  // }

  cout << dist[gx][gy] << endl;
}

