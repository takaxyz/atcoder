#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<set<int> > ss(26);

  REP(i,s.size()){
    int t =  s[i] - 'a';
    ss[t].insert(i);
  }


  int q;
  cin >> q;
  REP(i,q){
    int type;
    cin >> type;
    if(type==1){
      int t;
      char c;
      cin >> t >> c;
      t--;
      ss[s[t] - 'a'].erase(t);
      s[t] = c;
      ss[s[t] - 'a'].insert(t);
    }else{
      int l,r;
      cin >> l >> r;
      l--;r--;
      int ans=0;
      REP(j,26){
        auto itr = ss[j].lower_bound(l);
        if(itr == ss[j].end())continue;
        if(*itr <= r){
          ans++;
//          cout << j << ":" << endl;
        }else{
        }
      }
      cout << ans << endl;
    }
  }

}

