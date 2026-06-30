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
  int n;
  cin >> n;

  vector<P> tk(n);
  REP(i,n){
    int h,l;
    cin >> h >> l;
    tk[i] = {l,h};
  }
  sort(ALL(tk));

  vector<P> vs;
  for(int i = n-1; i >=0; i--){
    if(vs.size() && vs.back().first == tk[i].first)continue;

    if(vs.size()){
      vs.pb({tk[i].first, max(tk[i].second, vs.back().second)});
    }else{
      vs.pb(tk[i]);
    }

  }
  reverse(ALL(vs));
  //for(auto [x,y]: vs)cout << x << " " << y << endl;

  int q;
  cin >> q;
  REP(i,q){
    int t;
    cin >> t;
    auto it = upper_bound(ALL(vs), make_pair(t, INF));
    cout << it->second << endl;
  }
}

