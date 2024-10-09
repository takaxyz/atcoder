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
  dsu uf(n);
  vvi vs(n, vi());
  REP(i,n)vs[i].pb(i);

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int u,v;
      cin >> u >> v;
      u--;v--;
      int ul = uf.leader(u);
      int vl = uf.leader(v);
      if(ul != vl){
        int nl = uf.merge(u,v);
        vi nv;
        merge(ALL(vs[ul]), ALL(vs[vl]), back_inserter(nv));

        sort(ALL(nv));
        reverse(ALL(nv));
        while(nv.size()>10)nv.pop_back();
        
        vs[nl] = nv;
      }
    }else{
      int u,k;
      cin >> u >> k;
      u--;
      int ul = uf.leader(u);
      if(vs[ul].size()>=k){
        cout << vs[ul][k-1] + 1 << endl;
      }else{
        cout << -1 << endl;
      }
    }

  }
}

