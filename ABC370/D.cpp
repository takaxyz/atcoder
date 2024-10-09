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

  vector<set<int>> x(h), y(w);
  REP(i,h)REP(j,w)x[i].insert(j);
  REP(i,w)REP(j,h)y[i].insert(j);

  int ans = h * w;
  while(q--){
    int r,c;
    cin >> r >> c;
    r--; c--;
    vector<P> v;
    if(x[r].count(c)){
      v.pb({r,c});
    }else{
      REP(i,2){
        auto it = x[r].upper_bound(c);
        if(it != x[r].end()){
          if(i==0)v.pb({r, *it});
          else v.pb({*it,r});
        }
        if(it != x[r].begin()){
          it--;
          if(i==0)v.pb({r, *it});
          else v.pb({*it,r});
        }
        swap(x,y);
        swap(r,c);
      }
    }
    ans -= v.size();
    for(auto [ri,ci]: v){
      x[ri].erase(ci);
      y[ci].erase(ri);
    }

  }
  cout << ans << endl;

}

