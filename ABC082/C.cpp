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
  int N;
  cin >> N;
  map<int,int> mp;
  REP(i,N){
    int a;
    cin >> a;
    mp[a]++;
  }
  int ans=0;
  for(auto &v: mp){
    if(v.second-v.first>0){
      ans += v.second-v.first;
    }else if(v.second-v.first<0){
      ans += v.second;
    }
  }
  cout << ans << endl;
}

