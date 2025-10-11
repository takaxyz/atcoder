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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

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

int main(){
  int n;
  cin >> n;
  vector<string> s(n);

  CumulativeSum2D sum(n,n);

  int sx=0,sy=0;
  REP(i,n){
    cin >> s[i];
    REP(j,n){
      if(s[i][j]=='S'){
        sx = i; sy=j;
      }
      if(s[i][j]=='X')sum.add(i,j,1);
    }
  }
  sum.build();

  vvi d(n,vi(n,INF));
  FOR(k,1,n){
  
    queue<P> q;
    vector<P> vs;
    q.push({sx,sy});
    d[sx][sy]=0;
    vs.pb({sx,sy});
    
    int ans = INF;

    while(!q.empty()){
      auto [i,j] = q.front();
      q.pop();
      REP(l,4){
        int ni = i + dx[l]*k;
        int nj = j + dy[l]*k;
        if(ni < 0 || ni >= n || nj < 0 || nj >=n)continue;

        if(s[ni][nj]=='X')continue;

        int si=i,gi=ni,sj=j,gj=nj;
        if(gi < si)swap(si,gi);
        if(gj < sj)swap(sj,gj);

        if(sum.query(si,sj,gi+1,gj+1))continue;

        if(d[ni][nj]!=INF)continue;

        q.push({ni,nj});
        vs.pb({ni,nj});
        d[ni][nj]=d[i][j]+1;

        if(s[ni][nj]=='G'){
          ans = d[ni][nj];
          while(!q.empty())q.pop();
          break;
        }
      }
    }
    for(auto [x,y]: vs)d[x][y]=INF;

    cout << (ans == INF ? -1 : ans) << endl;


  }



}

