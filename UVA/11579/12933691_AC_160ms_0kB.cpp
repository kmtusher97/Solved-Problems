/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 11234567;
int n;

double triangle_area_sq( double a, double b, double c )
{
  double s = (a+b+c)/2.0;
  return s*(s-a)*(s-b)*(s-c);
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    cin>>n;
    vector<double> v;
    for(int i=0; i<n; i++)
    {
      double a;
      cin>>a, v.push_back(a);
    }

    sort(v.begin(), v.end());

    double area = 0;
    for(int i=2; i<v.size(); i++)
    {
      if( v[i-2]+v[i-1]<v[i] ) continue;
      area = max(area, triangle_area_sq( v[i-2], v[i-1], v[i] ));
    }
    cout<<fixed<<setprecision(2)<<sqrt(area)<<endl;
  }
  return 0;
}

