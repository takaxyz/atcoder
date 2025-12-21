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

int main(){
  int n;
  cin >> n;
  vvi data(2001, vi(2001));

  vi u(n),d(n),l(n),r(n);
  REP(i,n){
    cin >> u[i] >> d[i] >> l[i] >> r[i];
    u[i]--; l[i]--;
  }

  REP(i,n){
    data[u[i]][l[i]]++;
    data[u[i]][r[i]]--;
    data[d[i]][r[i]]++;
    data[d[i]][l[i]]--;
  }

  // for(int i = 0; i < 8; i++){
  //   for(int j = 0; j < 8; j++){
  //     cout << data[i][j] << (j == 7 ? "\n" : " ");
  //   }
  // }  

  REP(i,2001)FOR(j,1,2001){
    data[i][j] += data[i][j-1];
  }
  // cout << endl;
  // for(int i = 0; i < 8; i++){
  //   for(int j = 0; j < 8; j++){
  //     cout << data[i][j] << (j == 7 ? "\n" : " ");
  //   }
  // }  
  REP(j,2001)FOR(i,1,2001){
    data[i][j] += data[i-1][j];
  }

  // cout << endl;
  // for(int i = 0; i < 8; i++){
  //   for(int j = 0; j < 8; j++){
  //     cout << data[i][j] << (j == 7 ? "\n" : " ");
  //   }
  // }  

  CumulativeSum2D sum(2001,2001);
  int cnt=0;
  REP(i,2001)REP(j,2001){
    if(data[i][j] == 1)sum.add(i,j,1);
  }
  REP(i,2000)REP(j,2000){
    if(data[i][j] == 0)cnt++;
  }

  sum.build();
  REP(i,n){
    cout << cnt + sum.query(u[i],l[i],d[i],r[i]) << endl;
  }

}

