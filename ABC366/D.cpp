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
struct CumulativeSum3D {
  vector<vector<vector<int>>> data;

  CumulativeSum3D(int x, int y, int z) : data(x+1, vector<vector<int>>(y+1, vector<int>(z+1, 0))) {}

  void add(int x, int y, int z, int val){
    ++x; ++y; z++; 
    if(x >= data.size() || y >= data[0].size() || z >= data[0][0].size()) return;
    data[x][y][z] += val;
  }

  void build() {
    for(int i = 1; i < data.size(); i++){
      for(int j = 1; j < data[i].size(); j++){
        for(int k = 1; k < data[0][0].size(); k++){
          data[i][j][k] += data[i][j-1][k] + data[i-1][j][k] + data[i][j][k-1] - data[i][j-1][k-1] - data[i-1][j][k-1] - data[i-1][j-1][k] + data[i-1][j-1][k-1];
        }
      }
    }
  }

  // 半開区間なのでgx,gyは含まない
  int query(int sx, int sy, int sz, int gx, int gy, int gz){
    return data[gx][gy][gz] - data[sx][gy][gz] - data[gx][sy][gz] - data[gx][gy][sz] + data[gx][sy][sz] + data[sx][gy][sz]+ data[sx][sy][gz] - data[sx][sy][sz];
  }
};

int main(){
  int n;
  cin >> n;
  CumulativeSum3D cs(n,n,n);
  REP(i,n)REP(j,n)REP(k,n){
    int a;
    cin >> a;
    cs.add(i,j,k,a);
  }
  cs.build();
  int q;
  cin >> q;
  REP(_,q){
    int lx,rx,ly,ry,lz,rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    cout << cs.query(lx-1,ly-1,lz-1,rx,ry,rz) << endl;
  }
}

