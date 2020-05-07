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
  int a,b;
  cin >> a >> b;
  int ans=0;
  FOR(i,a,b+1){
    string s = to_string(i);
    string t = to_string(i);

    reverse(ALL(t));

    if(s==t)ans++;
  }
  cout << ans << endl;
}

