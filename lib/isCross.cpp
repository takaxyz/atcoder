// 線分AB, CDの交差判定
bool isCross(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy){
  ll ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  ll tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  ll tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  ll td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
  return tc * td < 0 && ta * tb < 0;
}
