#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e19;
const int INF=(1<<30);


int main(){
  int N;
  cin >> N;

  vector<pair<int,int>> r(N), b(N);

  REP(i,N){
    int a, b;
    cin >> a >> b;
    r[i] = make_pair(a,b);
  }
  sort(ALL(r));

  REP(i,N){
    int c, d;
    cin >> c >> d;
    b[i] = make_pair(c,d);
  }
  sort(ALL(b));

  int ri = 0;
  int bi = 0;;

  vector<bool> visited(N,false);

  int ans=0;

  REP(bi, N){
    int max_i=-1;
    int max_y=-1;
    REP(ri, N){
      if(visited[ri])continue;

      if(r[ri].first >= b[bi].first)break;
      
      if(r[ri].second < b[bi].second){
        if(r[ri].second > max_y){
          max_y = r[ri].second;
          max_i = ri;
        }
      }

    }
    if(max_i != -1){
      visited[max_i]=true;
//      cout << bi << " " << max_i << endl;
      ans++;
    }
  }
  cout << ans << endl;

}

