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

vector< int > z_algorithm(const vector<string> &vs) {
  vector< int > prefix(vs.size());
  for(int i = 1, j = 0; i < vs.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < vs.size() && vs[k] == vs[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) vs.size();
  return prefix;
}

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> vs(w * 3 + 1);
  REP(i,h)REP(j,w){
    char c;
    cin >> c;
    vs[j].pb(c);
  }
  REP(i,h)REP(j,w){
    char c;
    cin >> c;
    vs[w + 1 + j].pb(c);
    vs[w * 2 + 1 + j].pb(c);
  }

  vi l = z_algorithm(vs);
  FOR(i,w+1,w+1+w){
    if(l[i] == w){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;


}

