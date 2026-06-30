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
  int h,w,k;
  cin >> h >> w >> k;
  
  vvi s(h,vi(w));
  REP(i,h)REP(j,w){
    char c;
    cin >> c;
    s[i][j] = c - '0';
  }

  vector sum(h,vector<int>(w+1));
  REP(i,h)REP(j,w){
    sum[i][j+1] += sum[i][j] + s[i][j]; 
  }

  ll ans=0;
  REP(i,w)FOR(j,i,w){
    vector<int> vs(h+1);
    REP(kk,h){
      vs[kk+1] += vs[kk] + sum[kk][j+1] - sum[kk][i];
    }

    if(k == 0){
      int prev = -1;
      int cnt=1;
      for(auto x: vs){
        if(x == prev)cnt++;
        else{
          ans += cnt * (cnt - 1) / 2; 
          prev = x;
          cnt = 1;
        }
      }
      ans += cnt * (cnt - 1) / 2; 

    }else{
      REP(kk,h+1){
        //vs[kk] + k
        ans += upper_bound(ALL(vs), vs[kk] + k) - lower_bound(ALL(vs), vs[kk]+k);
      }
    }



  }
  cout << ans << endl;

}

