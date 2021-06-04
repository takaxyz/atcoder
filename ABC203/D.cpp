#include <bits/stdc++.h>
using namespace std;

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

int n,k;
vvi a;

struct CumulativeSum2D {
  vector<vector<int>> data;

  CumulativeSum2D(int w, int h) : data(w+1, vector<int>(h+1, 0)) {}

  void add(int x, int y, int z){
    ++x; ++y; // 0-indexedの場合
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

  int query(int sx, int sy, int gx, int gy){
    return data[gx][gy] - data[sx][gy] - data[gx][sy]  + data[sx][sy];
  }
};

// 中央値がx以上かどうか == x以上の値がk*k/2+1個以上あるか
bool f(int x){
  CumulativeSum2D cs = CumulativeSum2D(n,n);

  REP(i,n)REP(j,n){
    if(a[i][j]>=x)cs.add(i,j,1);
    else cs.add(i,j,0);
  }
  cs.build();

  REP(i,n-k+1)REP(j,n-k+1){
    if(cs.query(i,j,i+k,j+k) < k*k/2+1)return false;
  }

  return true;
}

int main(){
  cin >> n >> k;
  a.resize(n,vi(n));
  REP(i,n)REP(j,n)cin >> a[i][j];

  int ok=0, ng=INF;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  cout << ok << endl;
}

