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
  vi a(6);
  REP(i,6)cin >> a[i];

  vector memo(3,map<vi,double>());


  auto dfs = [&](int rem, vi keep, auto dfs) -> double {
    if(rem == 0){
      if(keep.size()!=5)return 0;

      int res = 0;
      REP(i,6){
        int cnt = 0;
        for(auto x: keep)if(x == a[i])cnt++;
        chmax(res, a[i]*cnt);
      }
      return res;
    }

    rem--;
    if(memo[rem].count(keep))return memo[rem][keep];

    auto roll = [&](int num, vi dice, auto roll) -> double {
      if(num == 0){
        int sz = dice.size();
        double res = 0;
        REP(i,1<<sz){
          vi kp = keep;
          REP(j,sz){
            if((i>>j) & 1)kp.push_back(dice[j]);
          }
          chmax(res, dfs(rem,kp,dfs));
        }
        return res;
      }
      double res = 0;
      REP(i,6){
        dice.push_back(a[i]);
        res += roll(num-1, dice, roll);
        dice.pop_back();
      }
      return res / 6;
    };

    double res = roll(5 - keep.size(), {}, roll);
    return memo[rem][keep] = res;

  };

  double ans = dfs(3,{},dfs);
  printf("%.10f\n", ans);
  return 0;
}

