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
  int n, q;
  cin >> n >> q;
  vector<P> xy(n);
  REP(i,n)cin >> xy[i].first >> xy[i].second;

  auto d = [&](int i, int j){
    return abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second);
  };
  
  auto comp = [](tuple<int,int,int>& a, tuple<int,int,int>& b) { return get<0>(a) > get<0>(b);};

  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(comp)> pq(comp);

  REP(i,n)FOR(j,i+1,n){
    pq.emplace(d(i,j),i,j);
  }


  // while(!pq.empty()){
  //   auto [dist, i, j] = pq.top();
  //   pq.pop();
  //   printf("%d : %d %d\n",dist,i,j);
  // }

  dsu uf(n+q);

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int a,b;
      cin >> a >> b;
      int sz = xy.size();
      xy.emplace_back(a,b);
      REP(i,sz){
        pq.emplace(d(i, sz), i, sz);
      }
    }
    if(t==2){
      int ans = -1;
      while(!pq.empty()){
        auto [dist, i, j] = pq.top();
        pq.pop();
        if(uf.same(i,j))continue;

        ans = dist;
        uf.merge(i, j);

        while(!pq.empty()){
          auto [dist, i, j] = pq.top();
          if(ans != dist)break;
          pq.pop();
          uf.merge(i, j);
        }
        break;
      }
      cout << ans << endl;
    }
    if(t==3){
      int u,v;
      cin >> u >> v;
      u--;v--;
      cout << (uf.same(u,v) ? "Yes" : "No") << endl;
    }
  }
}

