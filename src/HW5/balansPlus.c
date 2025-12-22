#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
    char bracket;
    char strq[1000];
    charStack* list = newSortedList();
    scanf("%s", &strq);
    for(int i = 0; i < strlen(strq); i++){

        if (strq[i] == ')'){
            if (pop(list)!='('){
                    printf("%s\n", "баланс не соблюден");
                    return 0;
            }
        }
        else if (strq[i] == '}'){
            if (pop(list)!='{'){
                    printf("%s\n", "баланс не соблюден");
                    return 0;
            }
        }
        else if (strq[i] == ']'){
            if (pop(list)!='['){
                    printf("%s\n", "баланс не соблюден");
                    return 0;
            }
        }
        else if (strq[i] == '('){
            push(list, '(');
        }
        else if (strq[i] == '{'){
            push(list, '{');
        }
        else if (strq[i] == '['){
            push(list, '[');
        }
    }
    if (pop(list) == 'N'){
        printf("%s\n", "баланс соблюден");
        return 0;
    }
    printf("%s\n", "баланс не соблюден");
}