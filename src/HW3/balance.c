#include <stdio.h>
#include <string.h>

int main()
{
    int k = 0;
    char strq[1000];
    scanf("%s", &strq);
    for(int i = 0; i < strlen(strq); i++){
        if (strq[i] == ')'){
            k--;
        }
        else if (strq[i] == '('){
            k++;
        }
        if (k < 0){
            printf("%s\n", "баланс не соблюден");
            return 0;
        }
    }
    if (k == 0){
        printf("%s\n", "баланс соблюден");
        return 0;
    }
    printf("%s\n", "баланс не соблюден");
    return 0;
}