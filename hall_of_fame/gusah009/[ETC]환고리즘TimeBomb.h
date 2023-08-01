#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, b, Limit, called = 0;
int *Box;
FILE *in;
FILE *out;

void box_ready()
{
  in = fopen("test.inp", "r");
  fscanf(in, "%d", &N);
  Limit = N + (int)ceil(log(N) / log(2)) + 3;
  Box = (int *)malloc(sizeof(int) * (N + 1));
  for (int i = 1; i <= N; i++)
  {
    fscanf(in, "%d", &b);
    Box[i] = b;
  }
  fclose(in);
}

int box_size() { return N; }

int box_comp(int i, int j)
{
  called = called + 1;
  if (called > Limit)
  {
    out = fopen("test.out", "w");
    fprintf(out, "Function call limit over");
    free(Box);
    exit(-1);
  }

  if (i <= 0 || i > N || j <= 0 || j > N)
  {
    printf("index out of range : box_comp(%d, %d)\n", i, j);
    return 0;
  }
  printf("check box %d %d\n", Box[i], Box[j]);
  if (Box[i] < Box[j])
    return -1;
  else if (Box[i] > Box[j])
    return 1;
  return 0;
}

void box_report(int w)
{
  out = fopen("test.out", "w");
  fprintf(out, "%d", w);
  free(Box);
  exit(0);
}