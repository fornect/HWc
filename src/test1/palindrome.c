#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "a bc c ba";
    int lens1 = strlen(str1);
    char str2[lens1];
    int k = 0;
    for (int i = 0; i <= lens1; i++){
        if (str1[i] != ' '){
            strncat(str2, &str1[i], 1);
        }
        
    }

    int lens2 = strlen(str2);
    for (int i = 0; i<=lens2; i++){
        if (str1[i] != str2[lens2-i]){
            break;
        }
        k++;
    }
    if (k == lens2){
        printf("Yes");
        return 0;
    }
    printf("No");
    return 0;
}