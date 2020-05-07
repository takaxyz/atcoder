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
  string S;
  cin >> S;

  vector<string> list;

  int p = 0;
  int q = 0;
  int cnt = 0;
  while(q < S.size()){
    if(isupper(S[q])){
      cnt++;
      if(cnt==2){
        string ss = S.substr(p,q-p+1);
        transform(ALL(ss), ss.begin(), ::tolower);
        list.push_back(ss);
        p=q+1;
        cnt=0;
      }
    }
    q++;
  }
  sort(ALL(list));

  REP(i,list.size()){
    string ss = list[i];
    ss[0] = toupper(ss[0]);
    ss[ss.size()-1] = toupper(ss[ss.size()-1]);
    cout << ss;
  }
  cout << endl;

}

