#include <stdio.h>
#include <string.h>
int search(char* str1, char* str2)
{
    int k = 0;
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    for (int i = 0; i < l1; i++) {
        for (int j = 0; (i < l1) && (j < l2 + 1); j++) {
            if (str2[j] != str1[i + j]) {
                break;
            } else if (l2 - 1 == j) {
                k++;
                break;
            }
        }
    }
    return k;
}

int main()
{
    char str1[] = "427161294888628818649126488712864";
    char str2[] = "88";
    printf("%d\n", search(str1, str2));
    return 0;
}