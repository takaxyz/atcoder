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
  double h;
  cin >> h;
  printf("%.8f\n", sqrt(h*(12800000+h)));
}