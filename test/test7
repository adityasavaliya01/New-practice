#include<stdio.h>
int calculator()
{
    int a,b,n;
    int i;
    while(i>=0)
    {
        printf("\n\nenter your choice: ");
        scanf("%d",&n);
        
        if(n!=0)
        {
            printf("enter first number:");
            scanf("%d",&a);
            printf("enter second number:");
            scanf("%d",&b);
        
            switch(n)
            {
                case 1:
                    printf("addition of %d and %d: %d",a,b,a+b);
                    break;
                
                case 2:
                    printf("substraction of %d and %d: %d",a,b,a-b);
                    break;
                    
                case 3:
                    printf("multiplication of %d and %d: %d",a,b,a*b);
                    break;
                
                case 4:
                    printf("division of %d and %d: %d",a,b,a/b);
                    break;
                
                case 5:
                    printf("module of %d and %d: %d",a,b,a%b);
                    break;
                    
                default:
                    break;
            }
        }    
        
        else
        {
            printf("program breaked");
            break;
        }
        
        i++;
    }
}

int main()
{
    printf("press 1 for +");
    printf("\npress 2 for -");
    printf("\npress 3 for *");
    printf("\npress 4 for /");
    printf("\npress 5 for %");
    printf("\npress 0 for exit");
    
    calculator();
    return 0;
}
