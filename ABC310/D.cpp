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
  int n,t,m;
  cin >> n >> t >> m;
  vvi bad(n,vi(n,0));
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    bad[a][b]=1;
    bad[b][a]=1;
  }

  vi teams;
  int ans=0;

  auto dfs = [&](int x, auto dfs)-> void{
    if(x == n){
      if(teams.size()==t)ans++;
      return;
    }

    REP(i,teams.size()){
      bool ok=true;
      REP(y,n){
        if(bad[x][y]==0)continue;
        if(teams[i] & (1<<y))ok=false;
      }
      if(ok){
        teams[i] ^= (1<<x);
        dfs(x+1, dfs);
        teams[i] ^= (1<<x);
      }
    }
    if(teams.size()<t){
      teams.emplace_back(1<<x);
      dfs(x+1,dfs);
      teams.pop_back();
    }


  };

  //teams.reserve(t);
  dfs(0, dfs);
  cout << ans << endl;
}

