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

int main(){
  double dp[101][101][101];

  int a,b,c;
  cin >> a >> b >> c;
  dp[a][b][c]=0;


  FOR(i,a,100)FOR(j,b,100)FOR(k,c,100){
    dp[i+1][j][k] += (dp[i][j][k]+1) * (i / (double)(i+j+k));
    dp[i][j+1][k] += (dp[i][j][k]+1) * (j / (double)(i+j+k));
    dp[i][j][k+1] += (dp[i][j][k]+1) * (k / (double)(i+j+k));
  }

  double p = 0;
  FOR(i,b,100)FOR(j,c,100)p += dp[100][i][j];
  FOR(i,a,100)FOR(j,c,100)p += dp[i][100][j];
  FOR(i,a,100)FOR(j,b,100)p += dp[i][j][100];

  printf("%0.9f\n", 1/p);

}

