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
  int n;
  cin >> n;
  VI c(n+1);
  int all_min = (1<<30);
  int odd_min = (1<<30);
  REP(i,n){
    cin >> c[i+1];
    chmin(all_min,c[i+1]);
    if(i%2==0)chmin(odd_min, c[i+1]);
  }

  int q;
  cin >> q;
  int cnt_all=0;
  int cnt_odd=0;
  ll ans=0;
  REP(i,q){
    int t;
    int a;
    cin >> t;

    if(t==1){
      int x;
      cin >> x >> a;
      if(x%2==0){
        if(c[x] - cnt_all  >=a){
          c[x]-=a;
          chmin(all_min, c[x] - cnt_all);
          ans += a;
        }
      }else{
        if(c[x] - cnt_all - cnt_odd >=a){
          c[x]-=a;
          ans += a;
          chmin(all_min, c[x] - cnt_all - cnt_odd);
          chmin(odd_min, c[x] - cnt_all - cnt_odd);
        }
      }
    }else if(t==2){
      cin >> a;
      if(odd_min >= a){
        odd_min -= a;
        chmin(all_min, odd_min);
        cnt_odd += a;;
        ans += (ll)a * ((n+1)/2);
      }
    }else{
      cin >> a;
      if(all_min >= a){
        all_min -= a;
        odd_min -= a;
        cnt_all += a;
        ans += (ll)a * n;
      }
    }

  }
  cout << ans << endl;
}

