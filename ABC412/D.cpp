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
  int n,m;
  cin >> n >> m;
  vvi edge(n,vi(n));
  REP(_,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a][b]=1;
    edge[b][a]=1;
  }

  auto solve = [&](vi vs) -> int{
    int m2 = 0;
    REP(i,vs.size())FOR(j,i+1,vs.size()){
      if(edge[vs[i]][vs[j]])m2++;
    }
    //cout << m2 << endl;
    int ret = INF;
    do{
      vi vs2 = vs;
      vs2.pb(vs[0]);;
      int cnt=0;
      REP(i,vs2.size()-1){
        if(edge[vs2[i]][vs2[i+1]] == 0)cnt++;
      }
      cnt += (m2 + cnt) - vs.size();
      chmin(ret,cnt);
    }while(next_permutation(ALL(vs)));
    return ret;
  };

  vi vs(n);
  iota(ALL(vs),0);

  int ans = solve(vs);

//  cout << ans << endl;

  if(n >= 6){
    REP(i,1<<n){
      int b = __builtin_popcount(i);
      if(b < 3 || n - b < 3)continue;

      vi vs1, vs2;
      REP(j,n){
        if((i >> j) & 1){
          vs1.pb(j);
        }else{
          vs2.pb(j);
        }
      }
      // REP(i,vs1.size())cout << vs1[i] << (i==vs1.size()-1 ? "\n" : " ");
      // REP(i,vs2.size())cout << vs2[i] << (i==vs2.size()-1 ? "\n" : " ");


      int s = 0;
      for(auto x: vs1)for(auto y: vs2)if(edge[x][y])s++;
      //printf("  %d\n",s);
      s += solve(vs1);
      //printf("  %d\n",s);
      s += solve(vs2);
      //printf("  %d\n",s);
      chmin(ans,s);
      //cout << ans << endl;
    }

  }
  cout << ans << endl;

}

