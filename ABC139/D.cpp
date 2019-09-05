#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int N;

  cin >> N;

  queue<pair<int, int> > qs[N+1];

  FOR(i,1,N+1){
    REP(j,N-1){
      int a;
      cin >> a;
      if(i < a){
          qs[i].push(make_pair(i,a));
      }else{
          qs[i].push(make_pair(a,i));
      }
    }
  }

  // FOR(i,1,N+1){
  //    cout << i << endl;
  //    while (!qs[i].empty()) {
  //     cout << qs[i].front().first << " " << qs[i].front().second << endl;
  //      qs[i].pop(); 
  //    }
  // }

  ll ans = 0;
  ll kkk = 0;

  while(true){
    kkk++;
    if(kkk > 1000000){
      cout << -1 << endl;
      exit(0);
    }else{
    }
    map<pair<int, int>, int> mp;
    int count = 0;

    int flag = 0;
    FOR(i,1,N+1){
      if(qs[i].size() != 0)flag++;
    }
    if(flag==0)break;

    FOR(i,1,N+1){
      if(qs[i].size() == 0)continue;


      if(mp.find(qs[i].front()) != mp.end()){
//        cout << "found" << endl;
//        cout << qs[i].front().first << "-" << qs[i].front().second << endl;
        int j = mp.find(qs[i].front())->second;
        qs[i].pop();
        qs[j].pop();
//        cout << i << " " << j << endl;
        count++;
      }else{
//        cout << "no found" << endl;
//        cout << qs[i].front().first << "-" << qs[i].front().second << endl;
        mp.insert(make_pair(qs[i].front(), i));
      }
    }

    if(count > 0){
      ans++;
      //cout << "ans " << ans << endl;
    }else{
      cout << -1 << endl;
      exit(0);
    }
  }

  cout << ans << endl;

}