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

int main(){
  int h,w,q;
  cin >> h >> w >> q;
  vector vs(q+1,tuple<int,int,char>());
  vs[q] = {h-1,w-1,'A'};

  vector s(h, vector<char>(w, ' '));

  REP(i,q){
    int r,c;
    char x;
    cin >> r >> c >> x;
    vs[q-i-1] = {r-1,c-1,x};
  }

  for(auto [r,c,x] : vs){
    for(int ri = r; ri >= 0; ri--){
      if(s[ri][c] != ' ')break;
      for(int ci = c; ci >= 0; ci--){
        if(s[ri][ci] != ' ')break;
        s[ri][ci] = x;
      }
    }
  }

  REP(i,h)REP(j,w)cout << s[i][j] << (j == w-1 ? "\n" : "");
}

