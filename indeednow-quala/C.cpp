#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

int main(){
  int N;
  cin >> N;
  
  VI s;
  REP(i,N){
    int a;
    cin >> a;
    if(a>0)s.emplace_back(a);
  }
  fprintf(stderr, "a\n");
  sort(s.rbegin(), s.rend());
  fprintf(stderr, "a\n");

  int Q;
  cin >> Q;
  REP(i,Q){
    int k;
    cin >> k;

    if(k < s.size()){
      cout << s[k]+1 << endl;
    }else{
      cout << 0 << endl;
    }
  }
}

