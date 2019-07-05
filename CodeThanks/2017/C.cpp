#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int N,K;
  cin >> N >> K;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >  q;
  
  REP(i,N){
    ll a,b;

    cin >> a >> b;
    q.push(make_pair(a,b));
  }

  ll ans=0;
  REP(i,K){
    ll a = q.top().first;
    ll b = q.top().second;
    ans += a;
    q.pop();
    q.push(make_pair(a+b, b));
  }
  cout << ans << endl;
}
