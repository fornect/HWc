#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "427161294888628818649126488712864";
    char str2[] = "88";
    int k;
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    for (int i = 0; i < l1; i++){
        for (int j = 0; (i < l1) & (j < l2 + 1); j++){
            if (str2[j] != str1[i + j]){
                break;
            }
            else if (strlen(str2) - 1 == j){
                k++;
                break;
            }
        }
    }
    printf("%d", k);
    return 0;
}