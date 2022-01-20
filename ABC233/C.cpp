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

int n;
ll x;
ll ans=0;
vector<vector<ll>> a;

void dfs(int d, ll p){
  if(p > x)return;

  if(d==n){
    if(p==x)ans++;
    return;
  }
  REP(i, a[d].size()){
    if(p  > x / a[d][i])continue;
    dfs(d+1, p*a[d][i]);
  }

}

int main(){
  cin >> n >> x;
  a.resize(n);
  
  REP(i,n){
    int l;
    cin >> l;
    REP(j,l){
      ll m;
      cin >> m;
      a[i].emplace_back(m);
    }
  }

  dfs(0, 1);

  cout << ans << endl;

}

