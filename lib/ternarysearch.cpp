
  double lb = 0;
  double ub = p;

  // ループの回数は探索範囲次第
  REP(i,200){
    double t1 = (2.0 * lb + ub) / 3.0;
    double t2 = (lb + 2 * ub) / 3.0;
    // 下に凸の場合
    if(f(p,t1) > f(p,t2))lb=t1;
    else ub=t2;
    // 上に凸の場合
    if(f(p,t1) < f(p,t2))lb=t1;
    else ub=t2;
  }

  //解はlb, ub

