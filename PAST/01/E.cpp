#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N, Q;
  cin >> N >> Q;

  vector<set<int>> to(N+1);
  vector<set<int>> from(N+1);

  int q,a,b;

  REP(i,Q){
    cin >> q;
    switch(q){
      case 1:
        cin >> a >> b;
//        printf("%d -> %d\n",a,b);
        to[a].insert(b);
        from[b].insert(a);
      break;

      case 2:
        cin >> a;
        for(auto itr = from[a].begin(); itr != from[a].end(); itr++){
//          printf("%d -> %d\n",a,*itr);
          to[a].insert(*itr);
          from[*itr].insert(a);
        }
      break;

      case 3:
        cin >> a;
        vector<int> tmp;
        for(auto itr = to[a].begin(); itr != to[a].end(); itr++){
          int x = *itr;
          for(auto itr2 = to[x].begin(); itr2 != to[x].end(); itr2++){
            if(*itr2!=a)tmp.push_back(*itr2);
          }
        }

        for(auto itr = tmp.begin(); itr != tmp.end(); itr++){
//          printf("%d -> %d\n",a,*itr);
          to[a].insert(*itr);
          from[*itr].insert(a);
        }
      break;
    }
  }

  FOR(i,1,N+1){
    FOR(j,1,N+1){
      if(to[i].find(j) != to[i].end()){
        cout << "Y";
      }else{
        cout << "N";
      }
    }
    cout << endl;
  }
}

