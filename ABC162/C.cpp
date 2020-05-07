#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

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

int lcm(int a, int b)
{
   return a / gcd(a, b) * b;
}

int main(){
  int K;
  cin >> K;
  int ans=0;
  FOR(i,1,K+1)FOR(j,1,K+1)FOR(k,1,K+1){
    ans += gcd(i,gcd(j,k));
  }
  cout << ans << endl;

}

