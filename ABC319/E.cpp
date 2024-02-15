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

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a / gcd(a, b) * b;
}

int main(){
  int n;
  ll x,y;
  cin >> n >> x >> y;
  n--;
  vi p(n);
  vector<ll> t(n);
  REP(i,n)cin >> p[i] >> t[i];

  int l = 1;
  REP(i,n)l = lcm(l,p[i]);

  vector<ll> d(l);
  REP(i, l){
    ll now=i;
    now += x;
    REP(j, n){
      now = ((now + p[j] - 1) / p[j]) * p[j] + t[j];
    }
    now += y;
    d[i] = now - i;
  }

  int q;
  cin >> q;
  REP(_,q){
    int qq;
    cin >> qq;

    cout << qq + d[qq%l] << endl;


  }
}

