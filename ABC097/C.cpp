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
  string s;
  cin >> s;

  int K;
  cin >> K;
  map<string,bool> mp;
  vector<string> list;
  REP(i,s.size()){
    FOR(j,1,K+1){
      string tmp = s.substr(i,j);
      if(!mp[tmp]){
        list.emplace_back(tmp);
        mp[tmp]=true;
      }
    }
  }
  sort(ALL(list));
  
  cout << list[K-1] << endl;
}

