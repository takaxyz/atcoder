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

int h, w;
int m[102][102];
bool visited[102][102];

int dx[2][6] = {-1,0,1,0,-1,-1,  0,1,1,1,0,-1};
int dy[2][6] = {-1,-1,0,1,1,0,   -1,-1,0,1,1,0};
int ans = 0;

void bfs(int yy, int xx){
  if(visited[yy][xx])return;

  queue<pair<int, int>> q;

  q.push(make_pair(yy,xx));
  visited[yy][xx] = true;

  while(!q.empty()){
    pair<int, int> p = q.front(); q.pop();
    int y = p.first;
    int x = p.second;


    REP(i,6){
      int ny = y + dy[y%2][i];
      int nx = x + dx[y%2][i];

      if(nx < 0 || nx > w+1 || ny < 0 || ny > h+1)continue;
      if(visited[ny][nx])continue;

      if(m[ny][nx]==1){
        ans++;
        continue;
      }

      q.push(make_pair(ny,nx));
      visited[ny][nx] = true;
    }

  }

}


int main(){
  cin >> w >> h;

  REP(i,h)REP(j,w)cin >> m[i+1][j+1];

  REP(i,w+2)bfs(0,i);
  REP(i,w+2)bfs(h+1,i);
  REP(i,h+2)bfs(i,0);
  REP(i,h+2)bfs(i,w+1);

  cout << ans << endl;
}

