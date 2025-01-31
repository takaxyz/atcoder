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
  int n,q;
  cin >> n >> q;

  dsu uf(n+2);
  vi col(n+2);
  REP(i,n+2)col[i]=i;
  vi l(n+2),r(n+2),cnt(n+2,1);
  REP(i,n+2)l[i]=i;
  REP(i,n+2)r[i]=i;

  REP(_,q){
    int t;
    cin >> t;
    int x,c;
    if(t==1){
      cin >> x >> c; 
      x = uf.leader(x);
      int sz = uf.size(x);

      cnt[col[x]] -= sz;
      col[x] = c;
      cnt[col[x]] += sz;

      int li = uf.leader(l[x] - 1);
      if(col[li] == c){
        int nl = l[li], nr = r[x];
        uf.merge(li, x);
        x = uf.leader(x);
        l[x] = nl; r[x] = nr; col[x] = c;
      }

      int ri = uf.leader(r[x] + 1);
      if(col[ri] == c){
        int nl = l[x], nr = r[ri];
        uf.merge(ri, x);
        x = uf.leader(x);
        l[x] = nl; r[x] = nr; col[x] = c;
      }

    }else{
      cin >> c;
      cout << cnt[c] << endl; 
    }
  }

}

