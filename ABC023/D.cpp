#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

ll h[100005];
ll s[100005];
int n;
double d[100005];

bool check(ll m){
  REP(i,n){
    d[i] = (double)(m - h[i]) / s[i];
    if(d[i] < 0)return false;
  }
  sort(d, d+n);
  bool ret = true;
  REP(i,n){
    if(d[i] < i)ret=false;
  }
  return ret;
}

int main(){
  cin >> n;
  ll mx = 0;
  REP(i,n){
    cin >> h[i] >> s[i];
    chmax(mx, h[i] + s[i]*(n-1));
  }

  ll l=0;
  ll r=mx;
  ll mid;
  while(l<r){
    mid = (l+r)/2;

    if(check(mid)){
      r = mid;
    }else{
      l = mid + 1;
    }
  }
  cout << l << endl;

}

