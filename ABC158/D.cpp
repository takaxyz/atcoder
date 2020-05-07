#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  string s;
  cin >> s;

  int Q;
  cin >> Q;

  int cnt_1=0;
  vector<char> c1, c2;
  REP(i,Q){
    int t,f;
    char c;

    cin >> t;
    if(t==1){
      cnt_1++;
    }else{
      cin >> f >> c;
      if(f==1){
        if(cnt_1 % 2 == 0){
          c1.push_back(c);
        }else{
          c2.push_back(c);
        }
      }else{
        if(cnt_1 % 2 != 0){
          c1.push_back(c);
        }else{
          c2.push_back(c);
        }
      }
    }
  }

  if(cnt_1%2==0){
    reverse(ALL(c1));
    REP(i,c1.size()){
      cout << c1[i];
    }
    cout << s;
    REP(i,c2.size()){
      cout << c2[i];
    }
    cout << endl;
  }else{
    reverse(ALL(c2));
    REP(i,c2.size()){
      cout << c2[i];
    }
    reverse(ALL(s));
    cout << s;
    REP(i,c1.size()){
      cout << c1[i];
    }
    cout << endl;

  }


}

