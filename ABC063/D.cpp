#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

bool check(ll m, vector<ll> &h, ll a, ll b){

  ll cnt=0;
  REP(i,h.size()){
    if(h[i]>b*m){
      cnt += (h[i] - b*m + a - b - 1)/(a-b);
    }
  }
  return cnt <= m;
}

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> h(N);

  REP(i,N)cin >> h[i];

  ll l=0; 
  ll r=(ll)1e9;

  while(l<r){
    ll m = (l+r)/2;
//    cout << l << " " << r << " " << m << endl;
    if(check(m,h,A,B)){
      r=m;
    }else{
      l=m+1;
    }
  }

  cout << l << endl;
}

