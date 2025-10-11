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

int main(){
  int n;
  cin >> n;
  vi a(3*n);
  REP(i,3*n)cin >> a[i];
  sort(ALL(a));

  int ans=0;

  auto dfs = [&](int s, vvi vs, auto dfs) -> void{
    //cout << "s: " << s << endl;
    if((int)vs.size()==n){
      //cout << "s: " << s << endl;
      bool ok=true;
      for(auto vs2: vs){
        if(a[vs2[0]] + a[vs2[1]] <= a[vs2[2]])ok=false;
      }
      if(ok)ans++;
      return;
    }

    int i = 0;
    while((1<<i) & s)i++;

    FOR(j,i+1,3*n)FOR(k,j+1,3*n){
      if((1<<j) & s || (1<<k) & s)continue;
      vs.pb({i,j,k});
      //printf("%d %d %d\n",i,j,k);
      dfs(s | (1<<i)| (1<<j) | (1<<k), vs, dfs);
      vs.pop_back();
    }

  };

  vvi vs;

  dfs(0,vs,dfs);
  cout << ans << endl;


}

