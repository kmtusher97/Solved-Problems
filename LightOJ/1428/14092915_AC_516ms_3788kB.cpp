/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 50002

char a[MX_N], b[MX_N];
int PF[MX_N], OC[MX_N];

struct Suffix_Array {
        char T[MX_N];
        int lnth, c[MX_N];
        int RA[MX_N], tempRA[MX_N];
        int SA[MX_N], tempSA[MX_N];

        int Pre[MX_N], PLCP[MX_N], LCP[MX_N];

        void initialize( char* t ) {
          lnth = strlen(t);
          for(int i=0; i<lnth; i++) T[i] = t[i];
          T[lnth++] = '#', T[lnth] = '\0';
        }

        void countingSort( int k ) {
          memset(c, 0, sizeof c);
          for(int i=0; i<lnth; i++) c[i+k < lnth ? RA[i+k] : 0]++;
          for(int i=0, sum=0, t; i<max(300, lnth); i++)
            t = c[i], c[i] = sum, sum += t;
          for(int i=0; i<lnth; i++)
            tempSA[c[SA[i]+k < lnth ? RA[SA[i]+k] : 0]++] = SA[i];
          for(int i=0; i<lnth; i++) SA[i] = tempSA[i];
        }

        void constructSA() {
          for(int i=0; i<lnth; i++) SA[i] = i, RA[i] = T[i];
          for(int k=1, r; k<lnth; k<<=1) {
            countingSort( k );
            countingSort( 0 );
            tempRA[SA[0]] = r = 0;
            for(int i=1; i<lnth; i++)
              tempRA[SA[i]] = ( RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k] ) ? r : ++r;
            for(int i=0; i<lnth; i++) RA[i] = tempRA[i];
            if( RA[SA[lnth-1]]==lnth-1 ) break;
          }
        }

        void computeLCP() {
          Pre[SA[0]] = -1;
          for(int i=1; i<lnth; i++) Pre[SA[i]] = SA[i-1];
          for(int i=0, L=0; i<lnth; i++) {
            if( Pre[i]==-1 ) {
              PLCP[i] = 0; continue;
            }
            while( T[i+L]==T[Pre[i]+L] ) L++;
            PLCP[i] = L;
            L = max(L-1, 0);
          }
          for(int i=0; i<lnth; i++) LCP[i] = PLCP[SA[i]];
        }

        void print() {
          for(int i=0; i<lnth; i++) printf("%2d \t %2d \t %s\n", SA[i], LCP[i], T+SA[i]);
        }
} sa;


int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s%s", a, b);
    int lna = strlen(a), lnb = strlen(b);

    sa.initialize( a );
    sa.constructSA();
    sa.computeLCP();

    PF[0] = 0;
    for(int i=1, j; i<lnb; i++) {
      j = PF[i-1];
      while( j>0 && b[i]!=b[j] ) j = PF[j-1];
      if( b[i]==b[j] ) j++;
      PF[i] = j;
    }
    memset(OC, -1, sizeof OC);
    for(int i=0, j=0; i<lna; i++) {
      while( j>0 && a[i]!=b[j] ) j = PF[j-1];
      if( a[i]==b[j] ) j++;
      else j = 0;
      if( j==lnb ) OC[i-j+1] = i-j+1;
    }
    for(int i=lna-1, o=lna; i>=0; i--) {
      if( ~OC[i] ) o = OC[i];
      OC[i] = o;
    }

    int res = 0;
    for(int i=1; i<sa.lnth; i++) {
      int id = sa.SA[i], lcp = sa.LCP[i];
      int tmp = max(0, min(OC[id]+lnb-1, lna)-id-lcp);
      res += tmp;
    }
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
