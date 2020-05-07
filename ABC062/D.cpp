#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;

  vector<int> a(3*N);
  
  REP(i,3*N)cin >> a[i];

  ll sum1=0;
  ll sum2=0;

  vector<ll> v1, v2;

  std::priority_queue< int, std::vector<int>, std::greater<int> > pq1;

  REP(i,N){
    sum1+=a[i];
    pq1.push(a[i]);
  }

  v1.push_back(sum1);
  FOR(i,N,2*N){
    sum1 += a[i];
    pq1.push(a[i]);
    sum1 -= pq1.top();
    pq1.pop();
    v1.push_back(sum1);
  }

  std::priority_queue< int, std::vector<int>, std::less<int> > pq2;

  FOR(i,2*N,3*N){
    sum2+=a[i];
    pq2.push(a[i]);
  }

  v2.push_back(sum2);
  for(int i=2*N-1; N <= i; i--){
    sum2+=a[i];
    pq2.push(a[i]);
    sum2 -= pq2.top();
    pq2.pop();
    v2.push_back(sum2);
  }

  reverse(v2.begin(), v2.end());

  ll ans=-INF;

  REP(i,v1.size()){
    ans=max(ans,v1[i]-v2[i]);
  }
  cout << ans << endl;
}
