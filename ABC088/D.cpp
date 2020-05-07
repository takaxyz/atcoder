#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e19;
const int INF=(1<<30);

int H,W;
char g[51][51];
int dist[51][51];

struct pos{
  int x;
  int y;
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  cin >> H >> W;
  REP(i,H)REP(j,W)cin>>g[i][j];
  REP(i,H)REP(j,W)dist[i][j] = INF;

  stack<pos> st;

  st.push({0,0});
  dist[0][0] = 0;

  int ans = 0;
  REP(i,H)REP(j,W)if(g[i][j]=='.')ans++;

  while(!st.empty()){
    pos p = st.top(); st.pop();

    REP(i,4){
      int nx = p.x + dx[i];
      int ny = p.y + dy[i];

      if(nx<0 || nx >= H || ny <0 || ny >= W)continue;
      if(g[nx][ny] == '#')continue;
      if(dist[nx][ny] <= dist[p.x][p.y] + 1)continue;

      dist[nx][ny] = dist[p.x][p.y] + 1;
      st.push({nx,ny});
    }
  }

  if(dist[H-1][W-1]==INF){
    cout << -1 << endl;
  }else{
    cout << ans - dist[H-1][W-1] - 1 << endl;
  }
}

