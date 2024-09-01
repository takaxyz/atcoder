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
  int n,k;
  cin >> n >> k;

  vvi a(n,vi(n));
  REP(i,n)REP(j,n)cin >> a[i][j];

  auto f = [&](int x) {
    CumulativeSum2D cs(n,n);

    REP(i,n)REP(j,n)cs.add(i,j, a[i][j] >= x);
    cs.build();

    bool ok = true;
    REP(si,n)REP(sj,n){
      int gi = si + k;
      int gj = sj + k;
      if(gi > n || gj > n)continue;
      if(cs.query(si,sj,gi,gj) < (k*k/2) + 1)ok = false;
    }
    return ok;
  };


  int ok=0, ng=INF;

  while(abs(ok-ng)>1){
    int mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  cout << ok << endl;

}

