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

int x[3] = {3,5,7};

bool check(int n){
  int c3=0;
  int c5=0;
  int c7=0;

  while(n>0){
    if(n%10==3)c3++;
    else if(n%10==5)c5++;
    else if(n%10==7)c7++;

    n/=10;
  }
  return c3!=0 && c5!=0 && c7!=0;
}

int main(){
  int N;
  cin >> N;
  bool ok=true;
  VI s,t;
  s.emplace_back(0);

  int ans=0;
  while(ok && s.size()>0){
    for(auto v: s){
      REP(i,3){
        int n = v * 10 + x[i];

        t.emplace_back(n);
        if(!check(n))continue;

        if(n <= N){
          ans++;
        }else{
          ok=false;
        }
      }
    }
    s.clear();
    s.resize(t.size());
    copy(ALL(t),s.begin());
    t.clear();
  }
  cout << ans << endl;
}

