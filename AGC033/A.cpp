#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main(){
  int h,w;
  cin >> h >> w;

  vector<vector<char> > a(h);
  vector<vector<int> > d(h, vector<int>(w,-1));
  queue<pair<int,int> > q;

  REP(i,h){
    REP(j,w){
      char c;
      cin >> c;
      a[i].push_back(c);
      if(c == '#'){
        q.push(make_pair(i,j));
        d[i][j] = 0;
      }
    }
  }
  int ans = 0;
  while(!q.empty()){
    pair<int,int> pos = q.front();
    q.pop();

    REP(i,4){
      int x = pos.first + dx[i];
      int y = pos.second + dy[i];
      if(x < 0 || x >= h || y < 0 || y >= w) continue;

      if(a[x][y] == '#')continue;

      a[x][y] = '#';
      d[x][y] = d[pos.first][pos.second] + 1;
      ans = max(ans, d[x][y]);
      q.push(make_pair(x,y));

    }
  }

  cout << ans << endl;


}

