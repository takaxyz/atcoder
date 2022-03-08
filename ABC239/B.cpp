#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  ll x;
  cin >> x;
  if(x<0 && x%10!=0){
    cout << x / 10 - 1<< endl;
  }else{
    cout << x / 10 << endl;
  }
}