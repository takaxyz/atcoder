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

using mint = modint1000000007;
// using mint = modint998244353;


// 0-indexed
// query は半開区間なのでgx,gyは含まない
struct CumulativeSum2D {
  vector<vector<int>> data;

  CumulativeSum2D(int w, int h) : data(w+1, vector<int>(h+1, 0)) {}

  void add(int x, int y, int z){
    ++x; ++y; 
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++){
      for(int j = 1; j < data[i].size(); j++){
        data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
      }
    }
  }

  // 半開区間なのでgx,gyは含まない
  int query(int sx, int sy, int gx, int gy){
    return data[gx][gy] - data[sx][gy] - data[gx][sy]  + data[sx][sy];
  }
};

int DX[] = {1,0,-1,0};
int DY[] = {0,1,0,-1};
int DLX[] = {1,0,0,0};
int DRX[] = {0,0,-1,0};
int DLY[] = {0,1,0,0};
int DRY[] = {0,0,0,-1};



int main(){
  int h,w;
  cin >> h >> w;

  vector<string> s(h);
  REP(i,h)cin >> s[i];

  int sx =-1,sy=-1;
  REP(i,h)REP(j,w)if(s[i][j]=='T'){sx = i; sy = j;};

  int lx = 0;
  int rx = h - 1;
  int ly = 0;
  int ry = w - 1;

  CumulativeSum2D sum(h,w);

  REP(i,h)REP(j,w){
    if(s[i][j]=='#'){
      sum.add(i, j, 1);
    }
  }

  sum.build();
  //cout << sum.query(lx,ly,rx+1,ry+1) << endl;

  map<tuple<int,int,int,int,int,int>,int> memo;

  queue<tuple<int,int,int,int,int,int>> q;
  q.push({lx,rx,ly,ry,sx,sy});
  memo[{lx,rx,ly,ry,sx,sy}] = 0;

  while(q.size()){
    auto [lx,rx,ly,ry,tx,ty] = q.front();
    q.pop();

    if(sum.query(lx,ly,rx+1,ry+1)==0){
      cout << memo[{lx,rx,ly,ry,tx,ty}] << endl;
      return 0;
    }

    REP(i,4){
      int nx = tx + DX[i];
      int ny = ty + DY[i];

      //if(nx < 0 || nx >= h2 || ny <0 || ny >= w2)continue;
      // int nlx = min(lx + DLX[i],rx+1);
      // int nrx = max(rx + DRX[i],lx-1);
      // int nly = min(ly + DLY[i],ry+1);
      // int nry = max(ry + DRY[i],ly-1);

      //  int nlx0 = lx + DLX[i];
      //  int nrx0 = rx + DRX[i];
      //  int nly0 = ly + DLY[i];
      //  int nry0 = ry + DRY[i];
      int nlx = max(lx, nx-sx); int nrx = min(rx, h-1+(nx-sx));
      int nly = max(ly, ny-sy); int nry = min(ry, w-1+(ny-sy));

      // printf("a %d %d\n",nlx,nlx0);
      // printf("b %d %d\n",nrx,nrx0);
      // printf("c %d %d\n",nly,nly0);
      // printf("d %d %d\n",nry,nry0);


      if(nlx <= nx && nx <= nrx && nly <= ny && ny <= nry && s[nx][ny]=='#')continue;


      if(memo.count({nlx,nrx,nly,nry,nx,ny}))continue;
      q.push({nlx,nrx,nly,nry,nx,ny});
      memo[{nlx,nrx,nly,nry,nx,ny}] = memo[{lx,rx,ly,ry,tx,ty}] + 1;
    }

  }

  cout << -1 << endl;

}

