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
  string s;
  cin >> s;

  int ans = (s.size()+1)/2;
  if(s.size()%2==0){
    int i = s.size()/2-1;
    int j = s.size()/2;
    while(i >= 0 && s[i]==s[j]){
      ans++;
      i--; j++;
    }

  }else{
    int i = s.size()/2;
    FOR(j,1,s.size()/2+1){
      if(s[i-j]==s[i] && s[i+j] == s[i]){
        ans++;
      }else{
        break;
      }
    }
  }

  cout << ans << endl;
}

