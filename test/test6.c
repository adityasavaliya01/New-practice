#include <stdio.h>
int main()
{
    char str[100];  
    int i,len =0,j = 1;

    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);

    
    for (i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            j= 0;
            break;
        }
    }

    if (j)
    {
        printf("The given string is a palindrome.\n");
    }
    else
    {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}



#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int fre[257] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  
    
    // Calculate frequency of each character
    for (int i = 0; str[i] != '\0'; i++)
    {
        fre[(int)str[i]]++; 
    }
   
    printf("frequency: ");
    
    for (int i = 0; i < 256; i++)
    {
        if (fre[i] > 0)
        {
            printf("'%c' = %d\n", i, fre[i]);
        }
    }

    return 0;
}