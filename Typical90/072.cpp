#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
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

int used[16][16];
int ans=-1;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int h,w;
vector<string> c;

void dfs(int sx, int sy, int tx, int ty, int d){
  //printf("%d %d %d %d %d\n",sx,sy,tx,ty,d);
  if(sx == tx && sy == ty && used[tx][ty]){
    chmax(ans,d);
    return;
  }

  used[sx][sy]=1;

  REP(i,4){
    int nx = sx + dx[i];
    int ny = sy + dy[i];

    if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;;
    if(c[nx][ny]=='#')continue;
    if((nx != tx || ny != ty) && used[nx][ny])continue;

    dfs(nx,ny,tx,ty,d+1);
  }
  used[sx][sy]=0;
}


int main(){
  cin >> h >> w;
  c.resize(h);
  REP(i,h)cin >> c[i];

  REP(i,h)REP(j,w){
    if(c[i][j]=='#')continue;
    dfs(i,j,i,j,0);
  }

  cout << (ans <= 2 ? -1 : ans) << endl;

}

