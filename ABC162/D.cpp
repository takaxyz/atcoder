#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;

  ll ans=0;
  ll cnt_r=0;
  ll cnt_g=0;
  ll cnt_b=0;
  REP(i,n){
    if(s[i]=='R'){
      cnt_r++;
    }else if(s[i]=='G'){
      cnt_g++;
    }else{
      cnt_b++;
    }
  }

  ans = cnt_r * cnt_g * cnt_b;

  REP(i,n){
    char c=s[i];
    if(c=='R'){
      FOR(j,1, min(n-i-1,i)+1){
        if(s[i-j] == 'G' && s[i+j] == 'B' || s[i-j] == 'B' && s[i+j] == 'G'){
          ans-=1;
        }
      }
    }else if(c=='G'){
      FOR(j,1, min(n-i-1,i)+1){
        if(s[i-j] == 'R' && s[i+j] == 'B' || s[i-j] == 'B' && s[i+j] == 'R'){
          ans-=1;
        }
      }

    }else{
      FOR(j,1, min(n-i-1,i)+1){
        if(s[i-j] == 'G' && s[i+j] == 'R' || s[i-j] == 'R' && s[i+j] == 'G'){
          ans-=1;
        }
      }
    }
  }

  cout << ans << endl;
}



