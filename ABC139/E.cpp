#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  int n;
  cin >> n;
  vvi a(n, vi(n-1));
  REP(i,n)REP(j,n-1){
    cin >> a[i][j];
    a[i][j]--;
  }

  map<pair<int,int>, int> mp;

  int N = n*(n-1)/2;
  vvi edge(N,vi());

  int cnt=0;
  REP(i,n){
    int par = -1;
    REP(j,n-1){
      int v1 = i;
      int v2 = a[i][j];

      if(v1>v2)swap(v1,v2);

      if(mp.count(std::make_pair(v1,v2))==0){
        mp[std::make_pair(v1,v2)] = cnt++;
      }
      int cur = mp[std::make_pair(v1,v2)];

      if(par!=-1){
        edge[par].emplace_back(cur);
      }
      par = cur;
    }
  }

  // for(auto [k,v]: mp){
  //   printf("%d %d ::: %d\n", k.first, k.second, v);
  // }

  // REP(i,N)REP(j,edge[i].size()){
  //   printf("%d %d: %d\n", i,j,edge[i][j]);
  // }


  vi ins(N);
  REP(i,N)REP(j,edge[i].size()){
    ins[edge[i][j]]++;
  }

  // REP(i,ins.size()){
  //   cout << i << " " << ins[i] << endl;
  // }
  stack<int> st;
  REP(i,N)if(ins[i]==0)st.push(i);

  vi ans;
  while(st.size()){
    int v = st.top(); st.pop();
    ans.push_back(v);
    for(auto vv: edge[v]){
      ins[vv]--;
      if(ins[vv]==0)st.push(vv);
    }
  }

  if(ans.size()!=N){
    cout << -1 << endl;
    return 0;
  }
  // for(auto v: ans){
  //   cout << v << endl;
  // }


  vi dp(N);
  for(auto v: ans){
    for(auto vv: edge[v]){
      chmax(dp[vv], dp[v] + 1);
    }
  }

  int mx = -1;
  for(auto v: dp){
    chmax(mx, v);
  }
  cout << mx + 1 << endl;

}

