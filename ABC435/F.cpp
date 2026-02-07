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

P op(P a, P b) {
    return max(a, b);
}

P e() {
    return {0,0};
}

int main(){
  int n;
  cin >> n;

  segtree<P,op,e> tree(n);

  REP(i,n){
    int p;
    cin >> p;
    tree.set(i,{p,i});
  }

  auto dfs = [&](int v, int l, int r, auto dfs) -> ll{
    if(r-l == 1)return 0;

    ll ret = 0;
    
    if(l != v){
      P pp = tree.prod(l,v);

      chmax(ret, dfs(pp.second,l,v,dfs) + v - pp.second);
    }

    if(r-1 != v){
      P pp = tree.prod(v+1,r);

      chmax(ret, dfs(pp.second,v+1,r,dfs) + pp.second - v);
    }


    return ret;
  };
  //cout << tree.prod(0,n).second << endl;
  cout << dfs(tree.prod(0,n).second,0,n,dfs) << endl;

}

