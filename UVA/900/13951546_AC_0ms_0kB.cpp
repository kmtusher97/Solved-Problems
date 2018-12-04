#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

int main()
{
  intl ff[56];
  ff[0] = ff[1] = 1LL;
  for(int i=2; i<52; i++)
  {
    ff[i] = ff[i-1] + ff[i-2];
  }
  int n;
  while( scanf("%d", &n) && n )
  {
    printf("%lld\n", ff[n]);
  }
  return 0;
}
