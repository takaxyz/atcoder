#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  ll a,b,c;

  cin >> a >> b >> c;

  if(c-b-a<0){
    cout << "No" << endl;
  }else if( 4 * a * b < (c-b-a)*(c-b-a)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}

