/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 112345;
intl n, d, a[MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%lld %lld", &n, &d);
    for(int i=0; i<n; i++) scanf("%lld", a+i);
    intl res = 0;
    multiset<intl> st;
    for(int i=0; i<d; i++)
    {
      st.insert(a[i]);
    }
    multiset<intl> :: iterator b, e;
    b = st.begin(), e = st.end(), e--;
    res = max(res, (*e)-(*b));

    for(int i=d; i<n; i++)
    {
      st.insert(a[i]);
      st.erase(st.find(a[i-d]));
      b = st.begin(), e = st.end(), e--;
      res = max(res, (*e)-(*b));
    }
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
