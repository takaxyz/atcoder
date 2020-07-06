#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//const ll INF=(ll)1e19;
//const int INF=(1<<30);
const int INF=(1<<29);

int h,w;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,0-1};

vector<vector<int>> dijkstra(int sx, int sy, vector<vector<int>> &a){
  vector<vector<int>> d(h, vector<int>(w, INF));
  d[sx][sy] =0;

  priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> q;

  q.push(make_pair(0, P(sx, sy)));
  while(!q.empty()){
    pair<int, P> p = q.top(); q.pop();

    P v = p.second;
    if(d[v.first][v.second] < p.first){
      continue;
    }

    REP(i,4){
      int nx = v.first + dx[i];
      int ny = v.second + dy[i];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w )continue;
      if(d[nx][ny] > d[v.first][v.second] + a[nx][ny]){
        d[nx][ny] = d[v.first][v.second] + a[nx][ny];
        q.push(make_pair(d[nx][ny], P(nx,ny)));
      }
    }

  }
  // REP(i,h)REP(j,w){
  //   cout << d[i][j] << (j==w-1 ? "\n": " ");
  // }
  return d;
}


int main(){
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  REP(i,h)REP(j,w)cin >> a[i][j];

  auto d1 = dijkstra(h-1,0, a);
  auto d2 = dijkstra(h-1,w-1, a);
  auto d3 = dijkstra(0,w-1, a);

  int ans=INF;
  REP(i,h)REP(j,w){
    chmin(ans, d1[i][j] + d2[i][j] + d3[i][j] - a[i][j]*2);
  }

  cout << ans << endl;


}

