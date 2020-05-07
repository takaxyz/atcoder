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
  int n,k,c;
  cin >> n >> k >> c;

  vector<int> l(k+1), r(k+1);

  char s[n];
  REP(i,n)cin >> s[i];

  int cnt=0;
  int i = 0;
  while(i<n){
    if(s[i] == 'o'){
      l[++cnt] = i+1;
      i += c+1;
    }else{
      i++;
    }
    if(cnt==k)break;
  }
  i = n-1;
  cnt=k;
  while(i>=0){
    if(s[i] == 'o'){
      r[cnt--] = i+1;
      i -= c+1;
    }else{
      i--;
    }
    if(cnt==0)break;
  }

  FOR(i,1,k+1){
    if(l[i]==r[i])cout << l[i]  << endl;
  }
}

