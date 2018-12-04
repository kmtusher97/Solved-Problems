/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 112345;
char s[MX], mark[MX];

struct Suffix_Array {
        static const int MX_N = 112345;
        char T[MX_N];
        int N, c[MX_N];
        int RA[MX_N], tempRA[MX_N];
        int SA[MX_N], tempSA[MX_N];

        int Phi[MX_N], PLCP[MX_N], LCP[MX_N]; // for computing LCP

        void initialize( char* t ) {
          N = strlen(t);
          for(int i=0; i<N; i++) T[i] = t[i];
          T[N++] = '$';
        }

        void countingSort( int k ) {
          memset(c, 0, sizeof c);
          for(int i=0; i<N; i++) c[i+k<N ? RA[i+k] : 0]++;
          for(int i=0, sum=0; i<max(300, N); i++) {
            int t = c[i]; c[i] = sum, sum += t;
          }
          for(int i=0; i<N; i++) {
            tempSA[c[SA[i]+k<N ? RA[SA[i]+k] : 0]++] = SA[i];
          }
          for(int i=0; i<N; i++) SA[i] = tempSA[i];
        }

        void constructSA() {
          for(int i=0; i<N; i++) RA[i] = T[i];
          for(int i=0; i<N; i++) SA[i] = i;
          for(int k=1, r; k<N; k<<=1) {
            countingSort( k );
            countingSort( 0 );
            tempRA[SA[0]] = r = 0;
            for(int i=1; i<N; i++) {
              tempRA[SA[i]] = ( RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k] ) ? r : ++r;
            }
            for(int i=0; i<N; i++) RA[i] = tempRA[i];
            if( RA[SA[N-1]]==N-1 ) break;
          }
        }

        void computeLCP() {
          Phi[SA[0]] = -1;
          for(int i=1; i<N; i++) Phi[SA[i]] = SA[i-1];
          for(int i=0, L=0; i<N; i++) {
            if( Phi[i]==-1 ) {
              PLCP[i] = 0; continue;
            }
            while( T[i+L]==T[Phi[i]+L] ) L++;
            PLCP[i] = L;
            L = max(L-1, 0);
          }
          for(int i=0; i<N; i++) LCP[i] = PLCP[SA[i]];
        }

        void print() {
          for(int i=0; i<N; i++) printf("%2d\t%s\n", SA[i], T + SA[i]);
          for(int i=0; i<N; i++) printf("%2d\t%d\n", SA[i], LCP[i]);
        }
} sa;

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", s);
    int L, R;
    scanf("%d %d", &L, &R);
    sa.initialize( s );
    sa.constructSA();
    sa.computeLCP();
    intl res = 0;
    for(int i=1; i<sa.N; i++) {
      int ln = sa.N-sa.SA[i]-1;
      int lcp = sa.LCP[i];
      if( lcp>=R || ln<L ) continue;
      res += ln;
      if( lcp>=L ) res -= lcp;
      else res -= (L-1);
      if( ln>R ) res -= (ln-R);
      res = max(res, 0LL);
    }
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
