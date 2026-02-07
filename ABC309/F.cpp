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

int op(int a, int b) {
    return min(a, b);
}

int e() {
    return (int)(1e9);
}

segtree<int, op, e> seg(10);
int main(){
  int n;
  cin >> n;
  vi h(n),w(n),d(n);
  REP(i,n){
    vi vs(3);
    REP(i,3)cin >> vs[i];
    sort(ALL(vs));
    h[i] = vs[0];
    w[i] = vs[1];
    d[i] = vs[2];
  }

  auto compress = [&](vi vs){
    vi x = vs;
    sort(ALL(x));
    REP(i,n)vs[i] = lower_bound(ALL(x), vs[i]) - x.begin(); 
    return vs;
  };

  h = compress(h);
  w = compress(w);
  d = compress(d);

  vi ids(n);
  iota(ALL(ids),0);

  sort(ALL(ids),[&](const int& i, const int& j){
      if(h[i] == h[j]){
        if(w[i] != w[j])return w[i] > w[j];
        else return d[i] < d[j];
      }else{
        return h[i] < h[j];
      }
    }
  );

  segtree<int,op,e> seg(n);
  for(auto i : ids){
    if(seg.prod(0,w[i]) < d[i]){
      cout << "Yes" << endl;
      return 0;
    }else{
      if(seg.get(w[i]) > d[i])seg.set(w[i], d[i]);
    }
  }
  cout << "No" << endl;


}

