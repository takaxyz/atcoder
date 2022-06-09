#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>

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

int op(int x, int y){
  return x ^ y;
}

int e(){
  return 0;
}


int main(){
  int n,q;
  cin >> n >> q;

  atcoder::segtree<int, op, e> seg(n);

  REP(i,n){
    int a;
    cin >> a;
    seg.set(i,a);
  }

  REP(i,q){
    int t, x, y;
    cin >> t >> x >> y;
    if(t==1){
      x--;
      int v = seg.get(x);
      seg.set(x, v^y);
    }else{
      x--; y--;
      cout << seg.prod(x, y+1) << endl;
    }
  }
}

