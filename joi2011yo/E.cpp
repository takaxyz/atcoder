#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

char m[1000][1000];
int H, W, N;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int sy, int sx, int gy, int gx){
  int dist[1000][1000];
  REP(i,H)REP(j,W)dist[i][j]=-1;

  queue<pair<int,int>> q;
  q.push(make_pair(sy,sx));
  dist[sy][sx]=0;

  while(!q.empty()){
    pair<int,int> p = q.front(); q.pop();

    REP(i,4){
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if(nx < 0 || nx >= W || ny < 0 || ny >= H )continue;
      if(m[ny][nx]=='X' || dist[ny][nx]!=-1)continue;

      dist[ny][nx] = dist[p.first][p.second] + 1;
      if(gy == ny && gx == nx)return dist[ny][nx];

      q.push(make_pair(ny,nx));
    }

  }
  return(-1);
}

int main(){
  cin >> H >> W >> N;


  vector<pair<int, int>> route(N+1);

  REP(i,H)REP(j,W){
    cin >> m[i][j];
    if(m[i][j] == 'S'){
      route[0] = make_pair(i,j);
    }else if('1' <= m[i][j] && m[i][j] <= '9'){
      route[m[i][j]-'0'] = make_pair(i,j);
    }
  }

  int ans = 0;
  REP(i, route.size()-1){
    ans += bfs(route[i].first, route[i].second, route[i+1].first, route[i+1].second);
  }
  cout << ans << endl;

}

