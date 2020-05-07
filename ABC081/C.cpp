#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int N,K;
  cin >> N >> K;

  map<int,int> mp;
  REP(i,N){
    int a;
    cin >> a;
    mp[a]++;
  }

  vector<int> list;

  for(auto &v: mp){
    list.push_back(v.second);
  }
  sort(ALL(list));
  reverse(ALL(list));

  int ans = 0;
  FOR(i,K,list.size()){
    ans += list[i];
  }


  cout << ans << endl;
}

