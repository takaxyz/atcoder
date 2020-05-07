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
  vector<ll> cnt(5,0);

  int N;
  cin >> N;
  ll ans=0;
  REP(i,N){
    string s;
    cin >> s;
    switch(s[0]){
      case 'M':
        cnt[0]++;
        break;

      case 'A':
        cnt[1]++;
        break;

      case 'R':
        cnt[2]++;
        break;

      case 'C':
        cnt[3]++;
        break;

      case 'H':
        cnt[4]++;
        break;
    }
  }
  REP(i,5)FOR(j,i+1,5)FOR(k,j+1,5){
    ans += cnt[i]*cnt[j]*cnt[k];
//    cout << ans << endl;
  }
  cout << ans << endl;

}

