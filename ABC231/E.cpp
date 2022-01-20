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

vector<ll> a;
int n;
ll x;

map<ll, ll> memo;

ll dfs(int i, ll res){
  if(memo.find(res) != memo.end())return memo[res];

  if(res==0)return 0;
  
  if(i == n-1)return res/a[i];

  ll x = res % a[i+1] / a[i];
  x += dfs(i+1, res/a[i+1]*a[i+1]);

  ll y = ((res/a[i+1] + 1) * a[i+1] - res) / a[i];
  y += dfs(i+1, (res/a[i+1] + 1) * a[i+1]);

  memo[res] = min(x, y);
  return memo[res];
}

int main(){
  cin >> n >> x;
  a.resize(n);
  REP(i,n)cin >> a[i];

  cout << dfs(0, x) << endl;
}

