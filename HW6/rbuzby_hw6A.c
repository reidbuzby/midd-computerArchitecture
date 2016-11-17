long decode(long x, long y, long z) {
  y = y - z;
  x = y * x;
  y<<63;
  y<<63;
  return x^y;
}
