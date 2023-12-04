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
  int query(int gx, int gy){
    return data[gx][gy] - data[0][gy] - data[gx][0]  + data[0][0];
  }
};



int main(){
  int n,q;
  cin >> n >> q;
  CumulativeSum2D sum(n,n);
  REP(i,n)REP(j,n){
    char c;
    cin >> c;
    if(c=='B')sum.add(i,j,1);
  }
  sum.build();

  auto f = [&](ll x, ll y) {
    ll ret = sum.query(n,n)*(x/n)*(y/n);
    ret += sum.query(x%n,y%n);
    ret += sum.query(x%n,n)*(y/n);
    ret += sum.query(n,y%n)*(x/n);
    return ret;
  };

  REP(_,q){
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    cout << f(gx+1,gy+1) - f(sx,gy+1) - f(gx+1,sy) + f(sx,sy) << endl;
  }
}

