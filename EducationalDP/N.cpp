#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N;
ll memo[401][401];
vector<ll> a(400);
ll csum[401];

ll dp(int l, int r){
  if(memo[l][r] != -1) return memo[l][r];

  if(l==r){
    return memo[l][r] = 0;
  }

  ll ret = INF;
  ll sum;
  if (l == 0){
    sum = csum[r];
  }else{
    sum = csum[r] - csum[l-1];
  }
  REP(i,r-l){
    MINS(ret, dp(l,l+i) + dp(l+i+1, r) + sum);
  }
  return memo[l][r] = ret;
}

int main(){
  cin >> N;

  REP(i,N)cin >> a[i];
  REP(i,N)REP(j,N) memo[i][j] = -1;

  csum[0] = a[0];
  FOR(i,1,N)csum[i] = csum[i-1] + a[i];

  cout << dp(0,N-1) << endl;
}