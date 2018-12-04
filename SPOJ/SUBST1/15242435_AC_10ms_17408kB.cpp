/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;

#define MX_N 50001
char s[MX_N];

struct Suffix_Array {
        char T[MX_N];
        int n, c[MX_N];
        int RA[MX_N], tempRA[MX_N];
        int SA[MX_N], tempSA[MX_N];

        int Pre[MX_N], PLCP[MX_N], LCP[MX_N];

        void initialize( char* t ) {
          n = strlen(t);
          for(int i=0; i<n; i++) T[i] = t[i];
          T[n++] = '#';
        }

        void countingSort( int k ) {
          memset(c, 0, sizeof c);
          for(int i=0; i<n; i++) c[i+k < n ? RA[i+k] : 0]++;
          for(int i=0, sum=0, t; i<max(n, 250); i++)
            t = c[i], c[i] = sum, sum += t;
          for(int i=0; i<n; i++)
            tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
          for(int i=0; i<n; i++) SA[i] = tempSA[i];
        }

        void constructSA() {
          for(int i=0; i<n; i++) SA[i] = i, RA[i] = T[i];
          for(int k=1, r; k<n; k<<=1) {
            countingSort( k );
            countingSort( 0 );
            tempRA[SA[0]] = r = 0;
            for(int i=1; i<n; i++)
              tempRA[SA[i]] = ( RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k] ) ? r : ++r;
            for(int i=0; i<n; i++) RA[i] = tempRA[i];
            if( RA[SA[n-1]]==n-1 ) break;
          }
        }

        void computeLCP() {
          Pre[SA[0]] = -1;
          for(int i=1; i<n; i++) Pre[SA[i]] = SA[i-1];
          for(int i=0, L=0; i<n; i++) {
            if( Pre[i]==-1 ) {
              PLCP[i] = 0; continue;
            }
            while( T[i+L]==T[Pre[i]+L] ) L++;
            PLCP[i] = L;
            L = max(0, L-1);
          }
          for(int i=0; i<n; i++) LCP[i] = PLCP[SA[i]];
        }

        intl solution() {
          intl res = 0;
          for(int i=1; i<n; i++) {
            res += (n-SA[i]-1);
            res -= LCP[i];
          }
          return res;
        }
} SA;

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", s);
    SA.initialize( s );
    SA.constructSA();
    SA.computeLCP();
    printf("%lld\n", SA.solution());
  }
  return 0;
}
