#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int main(){
  string s;
  cin >> s;
  int p=0;
  int q=s.size()/2-1;
  for(int i = s.size()/2-1; i >0; i--){
    if(s.substr(p, i) == s.substr(q, i)){
      cout << i*2 << endl;
      exit(0);
    }
    q--;
  }

}