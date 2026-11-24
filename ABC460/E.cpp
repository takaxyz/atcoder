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

//using ll = long long int;
using ll = unsigned long long int;
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

//using mint = modint1000000007;
using mint = modint998244353;

void solve(){
  ll n;
  int m;
  cin >> n >> m;


  // n以下の正整数でx桁の数がいくつあるか
  auto f = [&](int x) -> ll{
    int len = to_string(n).size();
    if(x > len)return 0;
    else if(x == len){
      ll ret=1;
      REP(_,x-1)ret *= 10;
      return n - ret + 1;
    }else{
      ll ret=9;
      REP(_,x-1)ret *= 10;
      return ret;
    }
  };

  mint ans = 0;
  FOR(i,1,20){
    ll x = 1;
    REP(_,i){
      x *= 10;
    }

    //cout << f(i) << endl;
    ans += mint(n / (m / gcd(x-1, m))) * f(i);
  }
  cout << ans.val() << endl;

}


int main(){
  int t;
  cin >> t;

  REP(_,t)solve();

}

