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
const int MOD = 1e9 + 7;

int main(){
  int n, k;
  cin >> n >> k;

  vvi s(5001, vi(5001));
  REP(i,n){
    int a,b;
    cin >> a >> b;
    s[a][b]++;
  }

  REP(i,5001)REP(j,5000){
    s[i][j+1] += s[i][j];
  }
  REP(i,5001)REP(j,5000){
    s[j+1][i] += s[j][i];
  }

  int ans=0;
  FOR(i,1,5001-k)FOR(j,1,5001-k){
    chmax(ans, s[i+k][j+k] - s[i-1][j+k] - s[i+k][j-1] + s[i-1][j-1]);
  }

  cout << ans << endl;
}

