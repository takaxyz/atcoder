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
  ll N;
  cin >> N;

  for(ll h=1; h<=3500; h++){
    for(ll n=1; n<=3500; n++){
      ll x=N*h*n;
      ll y=4*h*n-N*n-N*h;

      if(y!=0 && x%y==0 && x/y>0){
        cout << h << " " << n << " " << x/y << endl;
        return 0;
      }

    }
  }
}

