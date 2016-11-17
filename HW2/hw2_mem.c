/*
Reid Buzby. 202 Assignment 2. 2/27/2016
to compile: gcc -o hw2_mem.c -o hw2_mem
to run: ./hw2_mem
*/

#include <stdio.h>
#include <string.h>

/*
chars a, b, and c are all located directly next to each other in memory at (when I ran it) ..c55, ..c56, ..c57. They each take up
one space of memory. * chars s, t, and u are also located next to eachother, but a different amount of space is allocated for each
one. When I ran it, one *char was 8 spaces of memory away from one, and 10 spaces away from another. EX ..c48, ..c40, ..c38. This makes
it seem like they are different sizes.
*/

int main(int argc, char* argv[]) {
  char a, b, c, *s, *t, *u;
  printf("a location: %p\nb location: %p\nc location: %p\ns location: %p\nt location: %p\nu location: %p\n", &a, &b, &c, &s, &t, &u);
  a = 'A';
  b = 'B';
  c = 'C';
  s = &a;
  t = &b;
  u = &c;
  printf("a: %c, ", *s);
  s--;
  printf("b: %c, ", *s);
  s--;
  printf("c: %c, ", *s);
  s+=2;
  printf("s*: %p, ", &*s);
  s--;
  printf("t*: %p, ", &*s);
  s--;
  printf("u*: %p\n", &*s);
  return 0;
}
