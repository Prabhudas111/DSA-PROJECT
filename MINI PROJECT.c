//Write an efficient code to find nth Fibonacci number

#include <stdio.h>
#define Max 5000

void add(char x[], char y[], char p[])
{
  int k = 0;
  for (int i = Max - 1; i >= 0; i--)
  {
    int digit = (x[i] - '0') + (y[i] - '0') + k;
    p[i] = (digit % 10) + '0';
    k = digit / 10;
  }
}


void copy(char x[], char y[])
{
  int i;
  for (i = Max - 1; i >= 0; i--)
    x[i] = y[i];
}

char fibo1[Max];
char fibo2[Max];
char p[Max];


int main()
{

  for (int i = 0; i < Max; i++)
  {
    fibo1[i] = fibo2[i] = p[i] = '0';
  }
  fibo2[Max - 1] = '1';

  int n;
  scanf("%d", &n);

  if (n == 0 || n == 1)
  {
    printf("%c", n + '0');
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      add(fibo1, fibo2, p);
      copy(fibo1, fibo2);
      copy(fibo2, p);
    }

    int t = 0;
    for (int i = 0; i < Max; i++)
    {
      if (t == 0 && p[i] == '0')
        continue;

      if (t == 0 && p[i] != '0')
        t = 1;
      printf("%c", p[i]);
    }
    printf("\n");
  }
  return 0;
}
