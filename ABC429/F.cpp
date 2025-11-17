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

using A = array<int,3>;
using S = array<A,3>;

S op(S x, S y){
  S res = S{A{INF,INF,INF}, A{INF,INF,INF},A{INF,INF,INF}};

  REP(i,3)REP(j,3)REP(k,3)chmin(res[i][j], x[i][k]+y[k][j]);

  return res;
}

S e(){
  return S{A{0,INF,INF}, A{INF,0,INF},A{INF,INF,0}};
}

S toS(string& s){
  S res = S{A{0,1,2}, A{1,0,1},A{2,1,0}};

  REP(i,3){
    if(s[i]=='#'){
      REP(j,3)res[i][j]=res[j][i]=INF;
      if(i==1){
        res[0][2] = res[2][0] = INF;
      }
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;

  vector s(n,string(3, ' '));
  REP(i,3)REP(j,n)cin >> s[j][i];


  vector<S> vs(n);
  REP(i,n)vs[i]= toS(s[i]);
  segtree<S, op, e> seg(vs);

  int q;
  cin >> q;
  REP(_,q){
    int r,c;
    cin >> r >> c;
    r--; c--;

    s[c][r] ^= '#' ^ '.';
    seg.set(c, toS(s[c]));
    S res = seg.all_prod();

    int ans = (res[0][2] == INF ? -1 : res[0][2] + n -1);

    cout << ans << endl;

  }

}

