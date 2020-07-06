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


int main(){
  int n;
  cin >> n;
  VI a(n);
  REP(i,n)cin >> a[i];

  VI l(n),r(n);

  l[0] = a[0];
  FOR(i,1,n){
    l[i] = gcd(a[i],l[i-1]);
  }
  r[0] = a[n-1];
  FOR(i,1,n){
    r[i] = gcd(a[n-1-i],r[i-1]);
  }

  int ans=1;
  REP(i,n-2){
    chmax(ans, gcd(l[i],r[n-3-i]));
  }
  chmax(ans, l[n-2]);
  chmax(ans, r[n-2]);

  cout << ans << endl;
}

