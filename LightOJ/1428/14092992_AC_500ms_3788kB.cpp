/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

const int MX = 50002;
char a[MX], b[MX];

struct KMP {
        static const int MX_K = 50010;
        int n, m, LPS[MX_K], APND[MX_K];

        void initialize( char* P ) {
          LPS[0] = -1, n = strlen(P);
          for(int i=0, j=-1; i<n; ) {
            while( j>=0 && P[i]!=P[j] ) j = LPS[j];
            LPS[++i] = ++j;
          }
        }

        void CustomSearch( char* T, char* P ) {
          m = strlen( T );
          memset(APND, -1, sizeof APND);
          for(int i=0, j=0; i<m; ) {
            while( j>=0 && P[j]!=T[i] ) j = LPS[j];
            i++, j++;
            if( j==n ) APND[i-j] = i-j;
          }
          for(int i=m-1, oc=m; i>=0; i--) {
            if( ~APND[i] ) oc = APND[i];
            APND[i] = oc;
          }
        }
} kmp;

struct Suffix_Array {
        static const int MX_S = 50010;
        char T[MX_S];
        int n, RA[MX_S], SA[MX_S];
        int tempRA[MX_S], tempSA[MX_S], c[MX_S];

        int Phi[MX_S], PLCP[MX_S], LCP[MX_S];

        void initialize( char* t ) {
          n = strlen(t);
          for(int i=0; i<n; i++) T[i] = t[i];
          T[n++] = '#', T[n] = '\0';
        }

        void countingSort( int k ) {
          memset(c, 0, sizeof c);
          for(int i=0; i<n; i++) c[i+k < n ? RA[i+k] : 0]++;
          for(int i=0, sum=0, t; i<max(300, n); i++)
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
          Phi[SA[0]] = -1;
          for(int i=1; i<n; i++) Phi[SA[i]] = SA[i-1];
          for(int i=0, L=0; i<n; i++) {
            if( Phi[i]==-1 ) {
              PLCP[i] = 0; continue;
            }
            while( T[i+L]==T[Phi[i]+L] ) L++;
            PLCP[i] = L;
            L = max(0, L-1);
          }
          for(int i=0; i<n; i++) LCP[i] = PLCP[SA[i]];
        }

        void print() {
          for(int i=0; i<n; i++) printf("%2d \t %2d  %2d \t %s\n", SA[i], LCP[i], kmp.APND[SA[i]], T+SA[i]);
        }
} SA;


int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s %s", a, b);
    kmp.initialize( b );
    kmp.CustomSearch( a, b );

    SA.initialize( a );
    SA.constructSA();
    SA.computeLCP();

    int res = 0;
    for(int i=1, lna=kmp.m, lnb=kmp.n; i<=lna; i++) {
      int sa = SA.SA[i], lcp = SA.LCP[i];
      int tmp = min( lna, kmp.APND[sa]+lnb-1 )-sa-lcp;
      tmp = max(0, tmp);
      res += tmp;
    }
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
