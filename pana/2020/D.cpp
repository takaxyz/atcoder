#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int N;

void dfs(string s, char mx){
  if(s.size()==N){
    cout << s << endl;
  }else{
    for(char c = 'a'; c < mx; c++){
      dfs(s + c, mx);
    }
    dfs(s+mx, mx+1);
  }
}

int main(){
  cin >> N;
  dfs("", 'a');
}

