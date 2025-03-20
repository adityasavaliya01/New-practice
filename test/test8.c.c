#include <stdio.h>
int main() 
{
    char str[100];
    printf("enter string: ");
    scanf("%s", str);
    
    char *ptr = str;
    int length = 0;
    
    while (*ptr != '\0')
    {
        length++;       
        ptr++;
    }
    
    printf("length: %d\n", length);
    return 0;
}






#include <stdio.h>
int cube() 
{
        
}

int main()
{
    int j,i,n,a;
    int *ptr;
    printf("enter array size: ");
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&arr[i][j]);
            ptr=&arr[i][j];
        }
    }
    printf("cube=");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ptr=&arr[i][j];
            a = (*ptr)*(*ptr)*(*ptr);
            printf("%d\n",a);
        }
    }
    cube();
    
}


