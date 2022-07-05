#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

ll solve(ll a){
  string x = to_string(a);
  int xx = x.size() + 1;
  vector<vector<vector<ll>>> dp(xx, vector<vector<ll>>(2, vector<ll>(2)));
  dp[0][0][0] = 1;

  for(int i = 0; i < x.size(); i++){
    int v = x[i] - '0';
    for(int smaller = 0; smaller < 2; smaller++){
      for(int j = 0; j < 2; j++){
        for(int k = 0; k <= (smaller ? 9 : v); k++){
          dp[i+1][smaller || k < v][j || k == 4 || k == 9] += dp[i][smaller][j];
        }
      }
    }
  }

  return dp[xx-1][0][1] + dp[xx-1][1][1];

}


int main(){
  ll a, b;
  cin >> a >> b;
  
  cout << (solve(b) - solve(a-1)) << endl;

}

