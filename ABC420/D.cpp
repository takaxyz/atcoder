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
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  REP(i,h)cin >> a[i];

  int sx,sy,gx,gy;
  REP(i,h)REP(j,w){
    if(a[i][j]=='S'){
      sx = i; sy = j;
    }else if(a[i][j]=='G'){
      gx = i; gy = j;
    }
  }

  vector dist(2, vvi(h,vi(w,INF)));
//  vvi visited1(h,vi(w));

  int sw=0;
  
  queue<tuple<int,int,int>> q;
  q.push({sx,sy,sw});
  dist[sw][sx][sy]=0;
  while(!q.empty()){
    auto[x, y, sw] = q.front();
    q.pop();

    int old = dist[sw][x][y];
    if(a[x][y]=='?')sw ^= 1;

    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;


      if(a[nx][ny]=='#')continue;
      if(sw == 0 && a[nx][ny]=='x')continue;
      if(sw == 1 && a[nx][ny]=='o')continue;
      if(dist[sw][nx][ny]!=INF)continue;

      dist[sw][nx][ny] = old + 1;
      q.push({nx,ny,sw});
    }
  }
  if(dist[0][gx][gy] == INF && dist[1][gx][gy] == INF){
    cout << -1 << endl;
  }else{
    cout << min(dist[0][gx][gy], dist[1][gx][gy]) << endl;
  }
}

