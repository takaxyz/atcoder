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
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<P> vs;

  int si = -1;
  int c = 0;
  REP(i,n){
    if(s[i]=='o'){
      if(si < 0)si=i;
      c++;
    }else{
      if(c>0){
        vs.pb({si,c});
        si=-1;
        c=0;
      }
    }
  }

  if(c>0){
    vs.pb({si,c});
  }

  double ans = 0;
  int now = 0;
  int r = 0;
  REP(l, vs.size()){
    while(r < vs.size() && now < k){
      now += vs[r].second;
      r++;
    }
    if(now >= k){
      //cout << l << " " << r << endl;
      //cout << vs[r-1].first << " " << vs[r-1].second << " " << vs[l].first << endl; 
      chmax(ans, (double)now/(vs[r-1].first+vs[r-1].second-vs[l].first));
      //cout << ans << endl;
    }
    now -= vs[l].second;
  }
  printf("%.9f\n",ans);

}

