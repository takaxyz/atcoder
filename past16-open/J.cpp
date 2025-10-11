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

int gcd(int a, int b)
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

int lcm(int a, int b)
{
   return a / gcd(a, b) * b;
}

int main(){
  int n,k;
  cin >> n >> k;
  vi a(k);
  REP(i,k)cin >> a[i];

  int g = a[1]-a[0];
  REP(i,k-2){
    g = gcd(g,a[i+2]-a[i+1]);
  }
  //cout << g << endl;

  vi vs;
  for(int i = 1; i * i <= g; i++){
    if(g % i !=0)continue;
    if((a[k-1]-a[0])/i + 1 <= n)vs.pb(i);
    if(g / i != i && (a[k-1]-a[0])/(g/i) + 1 <= n)vs.pb(g/i);
  }
  sort(ALL(vs));
  cout << vs.size() << endl;
  for(auto x: vs)cout << x << endl;

}

