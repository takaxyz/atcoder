#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

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
  ll X;
  cin >> n >> X;
  vector<ll> x(n);
  REP(i,n){
    cin >> x[i];
  }
  if(n==1){
    cout << abs(X-x[0]) << endl;
  }else{
    ll tmp = gcd(abs(X-x[0]), abs(X-x[1]));
    FOR(i,2,n){
      tmp = gcd(tmp, abs(X-x[i]));
    }
    cout << tmp << endl;
  }

}

