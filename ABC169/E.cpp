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
//const int INF=(1<<29);

int main(){
  int N;
  cin >> N;
  vector<ll> a(N),b(N);
  REP(i,N){
    cin >> a[i] >> b[i];
  }
  sort(ALL(a));
  sort(ALL(b));

  if(N%2==1){
    cout << b[N/2] - a[N/2] + 1 << endl;
  }else{
    cout << b[N/2] + b[N/2-1] - a[N/2] - a[N/2-1] + 1 << endl;
  }
}

