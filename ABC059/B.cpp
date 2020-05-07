#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  string a,b;
  cin >> a >> b;

  if(a.size() > b.size()){
    cout << "GREATER" << endl;
  }else if(a.size() < b.size()){
    cout << "LESS" << endl;
  }else{
    REP(i,a.size()){
      if(a[i] > b[i]){
        cout << "GREATER" << endl;
        exit(0);
      }else if(a[i] < b[i]){
        cout << "LESS" << endl;
        exit(0);
      }
    }
    cout << "EQUAL" << endl;
  }


}

