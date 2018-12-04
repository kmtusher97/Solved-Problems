/*401 - Palindromes*/
#include <stdio.h>
#include <string.h>

int main()
{
    char word[20], word1[20];
    while(scanf("%s", word) == 1) {
        int L = strlen(word);
        int i, j = 0, count = 0, c = 0;
        for(i=L-1; i>=0; i--)
            word1[j++] = word[i];
        for(i=0; i<L; i++)
            if(word1[i] == word[i]) count++;
        int l = i;
        for(i=0; i<L; i++) {
            if((word[i] == 'A' && word1[i] == 'A') || (word[i] == 'E' && word1[i] == '3') || (word[i] == 'H' && word1[i] == 'H') ||
               (word[i] == 'I' && word1[i] == 'I') || (word[i] == 'J' && word1[i] == 'L') || (word[i] == 'L' && word1[i] == 'J') ||
               (word[i] == 'M' && word1[i] == 'M') || (word[i] == 'O' && word1[i] == 'O') || (word[i] == 'S' && word1[i] == '2') ||
               (word[i] == 'T' && word1[i] == 'T') || (word[i] == 'U' && word1[i] == 'U') || (word[i] == 'V' && word1[i] == 'V') ||
               (word[i] == 'W' && word1[i] == 'W') || (word[i] == 'X' && word1[i] == 'X') || (word[i] == 'Y' && word1[i] == 'Y') ||
               (word[i] == 'Z' && word1[i] == '5') || (word[i] == '1' && word1[i] == '1') || (word[i] == '2' && word1[i] == 'S') ||
               (word[i] == '3' && word1[i] == 'E') || (word[i] == '5' && word1[i] == 'Z') || (word[i] == '8' && word1[i] == '8'))
                c++;
        }

        if(count == l && c == l)
            printf("%s -- is a mirrored palindrome.\n", word);
        else if(count == l && c != l)
            printf("%s -- is a regular palindrome.\n", word);
        else if(count != l && c == l)
            printf("%s -- is a mirrored string.\n", word);
        else if(count != l && c != l)
            printf("%s -- is not a palindrome.\n", word);
        printf("\n");
    }

    return 0;
}
