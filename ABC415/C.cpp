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

void solve(int n, string s){

  int succ = 0;
  vi visited(1<<n);
  auto dfs = [&](int x, auto dfs) -> void{
    //cout << x << endl;
    if(visited[x])return;
    visited[x]=1;
    if(succ)return;

    if(x > 0 && s[x-1]=='1')return;


    if(x == (1<<n)-1){
      cout << "Yes" << endl;
      succ = 1;
      return;
    }

    REP(i,n){
      if((x >> i) & 1)continue;

      dfs(x | (1<<i), dfs);
    }
  };

  dfs(0,dfs);

  if(succ == 0){
    cout << "No" << endl;
  }

}



int main(){
  int t;
  cin >> t;
  REP(_,t){
    int n;
    string s;
    cin >> n >> s;
    solve(n,s);
  }
}

