int isqrt(int x) {
    int r = (int)sqrt((double)x + 0.5); // 誤差補正
    while ((long long)(r + 1) * (r + 1) <= x) r++;
    while ((long long)r * r > x) r--;
    return r;
}
