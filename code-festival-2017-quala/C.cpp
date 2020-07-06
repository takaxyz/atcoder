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
  int h,w;
  cin >> h >> w;
  map<char, int> mp;
  REP(i,h*w){
    char a;
    cin >> a;
    mp[a]++;
  }

  int c1,c2,c4;
  if(h%2==1 && w%2 == 1){
    c1 = 1;
    c2 = (h/2)+(w/2);
    c4 = (h/2)*(w/2);
  }else if(h%2==0 && w%2==0){
    c1 = 0;
    c2 = 0;
    c4 = h*w/4;
  }else if(h%2==0){
    c1 = 0;
    c2 = h/2;
    c4 = (h/2)*(w/2);
  }else{
    c1 = 0;
    c2 = w/2;
    c4 = (h/2)*(w/2);
  }
//  cout << c1 << c2 << c4 << endl;
  REP(i,c1){
    for(auto &v: mp){
      if(v.second % 4 == 1 || v.second % 4 == 3){
        v.second--;
        break;
      }
    }
  }

  REP(i,c2){
    bool ok=false;
    for(auto &v: mp){
      if(v.second % 4 == 2){
        v.second-=2;
        ok=true;
        break;
      }
    }
    
    if(ok)continue;

    for(auto &v: mp){
      if(v.second > 0 && v.second % 4 == 0){
        v.second-=2;
        ok=true;
        break;
      }
    }
  }

  REP(i,c4){
    for(auto &v: mp){
      if(v.second > 0 && v.second % 4 == 0){
        v.second-=4;
        break;
      }
    }
  }


  bool ok=true;
  for(auto &v: mp){
    if(v.second != 0){
      ok=false;
      break;
    }
  }

  cout << (ok ? "Yes" : "No" ) << endl;


}