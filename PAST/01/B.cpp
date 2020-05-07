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
  ll a;
  cin >> a;
  REP(i,N-1){
    ll aa;
    cin >> aa;
    if(a == aa){
      cout << "stay" << endl;
    }else if(a < aa){
      cout << "up " << aa - a << endl; 
    }else{
      cout << "down " << a - aa << endl; 
    }
    a = aa;
  }
}

