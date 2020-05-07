

//  checkの戻り値が FFFTTT で一番左のTを見つけたい場合
  while(l<r){
    ll m = (l+r)/2;
//    cout << l << " " << r << " " << m << endl;
    if(check(m,h,A,B)){
      r=m;
    }else{
      l=m+1;
    }
  }
