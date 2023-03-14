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
  int n,m;
  cin >> n >> m;
  vvi edge(n);
  REP(i,n){
    string s;
    cin >> s;
    REP(j,m){
      if(s[j]=='1'){
        edge[i].pb(i+j+1);
      }
    }
  }

  vi d1(n,INF), d2(n,INF);
  d1[0]=0;
  REP(i,n){
    for(auto v: edge[i]){
      chmin(d1[v], d1[i]+1);
    }
  }
  d2[n-1]=0;
  for(int i = n-2; i >=0; i--){
    for(auto v: edge[i]){
      chmin(d2[i], d2[v]+1);
    }
  }

  FOR(k,1,n-1){
    int ans=INF;
    for(int l = max(0, k - m + 1); l < k; l++){
      for(auto r: edge[l]){
        if(r-l > m || r <= k )continue;
        chmin(ans, d1[l]+d2[r]+1);
      }
    }

    cout << (ans==INF ? -1 : ans) << endl;
  }


}

