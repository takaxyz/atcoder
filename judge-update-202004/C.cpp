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

int A,B,C;
int ans=0;

void dfs(int a, int b, int c, int n){
  if(n > A+B+C)return;
  if(!(a>=b && b>=c))return;
  if(a>A || b>B || c>C)return;
  if(n==A+B+C){
    ans++;
    return;
  }

  dfs(a+1, b, c, n+1);
  dfs(a, b+1, c, n+1);
  dfs(a, b, c+1, n+1);
}

int main(){
  cin >> A >> B >> C;
  dfs(1,0,0,1);
  cout << ans << endl;
}

