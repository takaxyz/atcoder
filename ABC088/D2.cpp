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

struct pos{
  int x;
  int y;
};

int h,w;
char s[50][50];
int dist[50][50];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


// x : 縦 y : 横  BFSバージョン
int main(){
  cin >> h >> w;

  int cnt=0;
  REP(i,h)REP(j,w){
    cin >> s[i][j];
    if(s[i][j]=='.')cnt++;
  }

  queue<pos> q;

  q.push({0,0});
  dist[0][0]=1;

  while(!q.empty()){
    int x = q.front().x;
    int y = q.front().y;
    q.pop();

    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
      if(s[nx][ny]=='#')continue;
      if(dist[nx][ny]!=0)continue;

      dist[nx][ny] = dist[x][y]+1;
      q.push({nx,ny});
    }

  }

  if(dist[h-1][w-1]==0){
    cout << -1 << endl;
  }else{
    cout << cnt - dist[h-1][w-1] << endl;
  }

}

