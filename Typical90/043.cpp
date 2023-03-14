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

// 右、下、左、上
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
int d[1005][1005][4];

vector<string> mz;

struct Node{
  int x,y,dir;
  //Node(int x,int y,int dir) : x=x, y=y, dir=dir {}; 
};

int main(){
  int h,w,rs,cs,rt,ct;
  cin >> h >> w >> rs >> cs >> rt >> ct;
  rs--;cs--;rt--;ct--;
  mz.resize(h);
  REP(i,h)cin >> mz[i];

  REP(i,h)REP(j,w)REP(k,4)d[i][j][k]=INF;

  REP(i,4)d[rs][cs][i]=0;
  deque<Node> q;

  REP(i,4)q.push_front({rs,cs,i});

  while(!q.empty()){
    Node v = q.front();
    q.pop_front();

    REP(i,4){
      int nx = v.x + dx[i];
      int ny = v.y + dy[i];

      if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
      if(mz[nx][ny]=='#')continue;


      int nc = d[v.x][v.y][v.dir] + (i == v.dir ? 0 : 1);
      if(d[nx][ny][i] > nc){
        //printf("%d %d %d %d\n",nx,ny,i,nc);
        d[nx][ny][i] = nc;
        if(i == v.dir){
          q.push_front({nx,ny,i});
        }else{
          q.push_back({nx,ny,i});
        }
      }
    }

  }

  int ans = INF;
  REP(i,4)chmin(ans, d[rt][ct][i]);
  cout << ans << endl;


}

