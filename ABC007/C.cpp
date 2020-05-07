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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
  int R,C;
  int sx,sy,gx,gy;

  cin >> R >> C;
  cin >> sy >> sx >> gy >> gx;
  sx--;sy--;gx--;gy--;
  char c[50][50];
  REP(i,R)REP(j,C){
    cin >> c[i][j];
  }

  int d[50][50];
  REP(i,50)REP(j,50)d[i][j]=-1;

  queue<pair<int, int>> q;

  d[sy][sx]=0;
  q.push({sy,sx});
  while(!q.empty()){
    pair<int,int> p = q.front(); q.pop();

    REP(i,4){
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if(c[ny][nx] == '#' || d[ny][nx] != -1)continue;
      d[ny][nx] = d[p.first][p.second] + 1;

      q.push({ny,nx});
    }
  }

  cout << d[gy][gx] << endl;
}

