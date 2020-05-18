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

vector<ll> b,p;

ll solve(int m, ll y){
  if(m==0)return 1;
  if(y==1)return 0;
  if(y<=1+b[m-1]+p[m-1])return solve(m-1,y-1);
  if(y==2+b[m-1]+p[m-1])return p[m-1]+1;
  if(y<=2+2*b[m-1]+2*p[m-1])return solve(m-1,y-2-p[m-1]-b[m-1]) + 1 + p[m-1];
  return 2*p[m-1]+1;
}

int main(){
  int n;
  ll x;
  cin >> n >> x;
  b.resize(n+1);
  p.resize(n+1);
  p[0]=1; b[0]=0;
  FOR(i,1,n+1){
    p[i] = p[i-1]*2+1;
    b[i] = b[i-1]*2+2;
  }

  cout << solve(n,x) << endl;
}

