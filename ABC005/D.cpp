#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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
  int n;
  cin >> n;

  vvi d(n, vi(n));
  REP(i,n)REP(j,n)cin >> d[i][j];

  vvi s(n+1, vi(n+1,0));
  REP(i,n)REP(j,n){
    s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + d[i][j];
  }

  // REP(i,n+1)REP(j,n+1){
  //   cout << s[i][j] << (j==n ? "\n" : " ");
  // }

  map<int,int> mp;
  FOR(xs,1,n+1)FOR(xg,xs,n+1)FOR(ys,1,n+1)FOR(yg,ys,n+1){
    int area = (xg-xs+1)*(yg-ys+1);
    int val = s[xg][yg] - s[xs-1][yg] - s[xg][ys-1] + s[xs-1][ys-1];
    chmax(mp[area],val);
  }

  FOR(i,1,n*n+1){
    chmax(mp[i],mp[i-1]);   
  }
  // for(auto v: mp){
  //   cout << v.first << " " << v.second << endl;
  // }

  int q;
  cin >> q;
  REP(i,q){
    int p;
    cin >> p;
    PRINT(mp[p]);
  }

}

