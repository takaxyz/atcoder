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

void print_LCS(vvi &dp, string &s, string& t, int i, int j){
//  fprintf(stderr, "%d %d\n",i,j);
  if(i==0 || j==0)return;
  if(dp[i][j] - 1 == dp[i-1][j] && dp[i][j] - 1 == dp[i][j-1]){
    print_LCS(dp, s, t, i-1, j-1);
    cout << s[i-1];
  }else if(dp[i][j] == dp[i-1][j]){
    print_LCS(dp, s, t, i-1, j);
  }else{
    print_LCS(dp, s, t, i, j-1);
  }
}


int main(){
  string s,t;
  cin >> s >> t;

  vvi dp(s.size()+1, vi(t.size()+1, 0));

  REP(i,s.size())REP(j,t.size()){
    if(s[i]==t[j]){
      dp[i+1][j+1] = dp[i][j]+1;
    }else{
      chmax(dp[i+1][j+1], dp[i+1][j]);
      chmax(dp[i+1][j+1], dp[i][j+1]);
    }
  }

  print_LCS(dp, s, t, s.size(), t.size());
  cout << endl;
}

