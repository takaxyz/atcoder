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
  int N, M;
  cin >> N >> M;

  set<int> s1;
  set<int> s2;

  REP(i,M){
    int a,b;
    cin >> a >> b;

    if(a==1)s1.insert(b);
    if(a==N)s2.insert(b);
    if(b==1)s1.insert(a);
    if(b==N)s2.insert(a);
  }

  for(auto itr = s1.begin(); itr != s1.end(); itr++){
    if(s2.find(*itr) != s2.end()){
      cout << "POSSIBLE" << endl;
      exit(0);
    }
  }
  cout << "IMPOSSIBLE" << endl;

}

