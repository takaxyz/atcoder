#include<iostream>
#include<vector>
#include<map>
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

  string S;
  cin >> S;
  transform(S.begin()+K-1, S.begin()+K, S.begin()+K-1, ::tolower);
  cout << S << endl;
}
