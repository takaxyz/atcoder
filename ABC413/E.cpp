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

void solve(){
  int n;
  cin >> n;

  int nn = 1;
  REP(_,n)nn *= 2;


  vi p(nn);

  REP(i,nn)cin >> p[i];

  auto dfs = [&](vi pp, auto dfs) -> vi {
    int sz = pp.size();

    if(sz==1){
      return pp;
    }

    vi p1(pp.begin(), pp.begin() + sz / 2);
    vi p2(pp.begin() + sz / 2, pp.end());

    vi l = dfs(p1, dfs);
    vi r = dfs(p2, dfs);

    vi res(pp.size());

    if(l[0] > r[0])swap(l,r);

    copy(l.begin(),l.end(), res.begin());
    copy(r.begin(),r.end(), res.begin()+sz/2);

    return res;
  };

  vi ans = dfs(p,dfs);

  REP(i,ans.size()){
    cout << ans[i] << (i == (int)ans.size()-1 ? "\n" : " ");
  }
}


int main(){
  int t;
  cin >> t;
  REP(_,t)solve();

}

