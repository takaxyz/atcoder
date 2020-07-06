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

int dist[403][403];
int mz[403][403];

int dx[6] = {1,0,-1,1,-1,0};
int dy[6] = {1,1,1,0,0,-1};




int main(){
  int N, X, Y;
  cin >> N >> X >> Y;

  REP(i, 403){
    REP(j, 403){
      dist[i][j] = INF;
    }
  }

  X += 201; Y += 201;
  REP(i,N){
    int x,y;
    cin >> x >> y;
    x+=201; y+=201;
    mz[x][y]=1;
  }
  int sx = 201;
  int sy = 201;

  queue<P> q;

  q.push(P(sx, sy));
  dist[sx][sy]=0;

  while(!q.empty()){
    P p = q.front(); q.pop();

    if(p.first == X && p.second == Y)break;
    REP(i,6){
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if(nx < 0 || ny >= 4023 || ny < 0 || ny >= 403)continue;
      if(mz[nx][ny]==1)continue;
      if(dist[nx][ny]!=INF)continue;

      q.push(P(nx,ny));

      dist[nx][ny] = dist[p.first][p.second]+1;
    }
  }

  if(dist[X][Y] != INF){
    cout << dist[X][Y] << endl;
  }else{
    cout << -1 << endl;
  }
}

