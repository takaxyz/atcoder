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
  int n,a,b;
  cin >> n >> a >> b;

  if(n % 2 == 1 || (a+b)%2==0){
    cout << "No" << endl;
    return;
  }

  cout << "Yes" << endl;

  string s;
  REP(_,(a-1)/2){
    REP(_,n-1)s += 'R';
    s += 'D';
    REP(_,n-1)s += 'L';
    s += 'D';
  }

  REP(_,(b-1)/2){
    s += "DRUR";
  }

  if(a % 2 == 0)s += "RD";
  else s += "DR";

  string t;
  REP(_,(n-a)/2){
    REP(_,n-1)t += 'R';
    t += 'D';
    REP(_,n-1)t += 'L';
    t += 'D';
  }

  REP(_,(n-b)/2){
    t += "DRUR";
  }
  reverse(ALL(t));

  cout << s << t << endl;

}

int main(){
  int t;
  cin >> t;

  REP(_,t)solve();
}

