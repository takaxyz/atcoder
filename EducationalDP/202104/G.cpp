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

int memo[100005];

int dp(int s, vvi &edge){
  if(memo[s]!=-1)return memo[s];

  int res=0;
  for(auto t : edge[s]){
    chmax(res, dp(t, edge)+1);
  }
  return memo[s] = res;
}

int main(){
  int n,m;
  cin >> n >> m;

  vvi edge(n, vi());

  REP(i,m){
    int x,y;
    cin >> x >> y;
    --x;--y;
    edge[x].push_back(y);
  }

  REP(i,n)memo[i]=-1;

  int ans=0;
  REP(i,n){
    chmax(ans, dp(i,edge));
  }
  cout << ans << endl;
}

