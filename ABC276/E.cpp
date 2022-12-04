#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
const int MOD = 1e9 + 7;

int h,w;
vector<string> c;
int dx1[6] = {1,1,1,-1,-1,0};
int dy1[6] = {0,0,0, 0, 0,1};
int dx2[6] = {-1,0,0, 0,0,0};
int dy2[6] = {0,1,-1, 1,-1,-1};

int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};


void dfs(int x, int y, vector<vector<bool>> &visited){
  //printf("%d %d\n",x,y);
  visited[x][y]=true;
  REP(i,4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || nx >=h || ny <0 || ny >= w)continue;
    if(visited[nx][ny])continue;
    if(c[nx][ny]=='#')continue;
    dfs(nx,ny,visited);
  }

}

bool check(int x0, int y0, int xs, int ys, int xg, int yg){
  //printf("%d %d %d %d\n",xs,ys,xg,yg);

  vector<vector<bool>> visited(h, vector<bool>(w,false));
  visited[x0][y0]=true;

  dfs(xs,ys,visited);
  return visited[xg][yg];
}


int main(){
  cin >> h >> w;
  c.resize(h);
  REP(i,h)cin >> c[i];

  int x0, y0;
  REP(i,h)REP(j,w){
    if(c[i][j]=='S'){
      x0=i;
      y0=j;
    }
  }

  REP(i,6){
    int xs = x0+dx1[i];
    int ys = y0+dy1[i];
    int xg = x0+dx2[i];
    int yg = y0+dy2[i];

    if(xs<0 || xs >= h)continue;
    if(ys<0 || ys >= w)continue;
    if(xg<0 || xg >= h)continue;
    if(yg<0 || yg >= w)continue;
    if(c[xs][ys]=='#')continue;
    if(c[xg][yg]=='#')continue;



    if(check(x0,y0,xs,ys,xg,yg)){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

}

