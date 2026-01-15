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
  vector vs(10,vector<string>());

  REP(i,n){
    string a;
    cin >> a;
    vs[a.size()].pb(a);
  }

  for(auto &x: vs)sort(RALL(x));

  vector<string> ans;
  int j=0;
  for(int i = 9; i > 0; i--){
    if(vs[i].size() >= 2){
      cout << vs[i][0] + vs[i][1] << endl;
      return 0;
    }
    if(vs[i].size() == 1){
      ans.pb(vs[i][0]);
      j = i;
      break;
    }
  }

  for(int i = j-1; i > 0; i--){
    if(vs[i].size() > 0){
      ans.pb(vs[i][0]);
      break;
    }
  }

  cout << max(ans[0]+ans[1], ans[1]+ans[0]) << endl;

}

