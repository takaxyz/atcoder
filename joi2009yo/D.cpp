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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct pos{
  int x;
  int y;
};

int n,m;
int maze[90][90];
int dist[90][90];
bool visited[90][90];
int ans=0;

void dfs(int x, int y, int depth){
//  printf("%d %d %d\n",x,y, depth);
  chmax(ans, depth);
  visited[x][y]=true;
  REP(i,4){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
    if(visited[nx][ny])continue;
    if(maze[nx][ny]==0)continue;
    dfs(nx, ny, depth+1);
  }
  visited[x][y]=false;
}

int main(){
  cin >> m >> n;

  REP(i,n)REP(j,m)cin >> maze[i][j];

  REP(i,n)REP(j,m){
    if(maze[i][j]==0)continue;
    dfs(i,j,1);
  }
  
  cout << ans << endl;


}

