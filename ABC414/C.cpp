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
  int a;
  ll n;
  cin >> a >> n;


  ll ans = 0;

  auto ck = [&](ll x){
    if(x > n)return;

    vi vs;
    ll x2=x;
    while(x2 > 0){
      vs.pb(x2 % a);
      x2 /= a;
    }

    bool ok=true;
    REP(i,vs.size()/2){
      if(vs[i] != vs[vs.size()-1-i])ok=false;
    }
    if(ok)ans+=x;
  };


  FOR(i,1,1000000){
    string s = to_string(i);
    string s2 = s;
    reverse(ALL(s2));

    s += s2;
    ll x = stoll(s);

    ck(x);
    
    s = to_string(i);
    s2 = s;
    s2.pop_back();
    reverse(ALL(s2));

    s += s2;
    x = stoll(s);

    ck(x);


  }

  cout << ans << endl;
}

