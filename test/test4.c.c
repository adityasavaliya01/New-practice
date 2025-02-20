#include <stdio.h>

int main()
{
    int i,j;
    for (i=1;i<=5;i++)
    {
        for (j=1;j<=5;j++)
        {
            if(j<=i)
            {
                // j=c;
                printf("%d ",j+40);
                // j++;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}



// ------------------------------------------------------------------


#include <stdio.h>

int main()
{
    int i,j,c=10;
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
        {
            if(j<=i)
            {
                c=c+1;
                printf("%d ",c);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
    
    
    
   // ------------------------------------------------------------------ 
    
    
    
#include <stdio.h>

int main()
{
    int i,j,c=10;
    for (i=1;i<=5;i++)
    {
        for (j=1;j<=5;j++)
        {
            if(j>=6-i)
            {
                printf("%d",j);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}



// ------------------------------------------------------------------


#include <stdio.h>

int main()
{
    int i,j;
    for (i=1;i<=5;i++)
    {
        for (j=1;j<=5;j++)
        {
            if(j>=i)
            {
                if((i+j)%2==0)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}




// ------------------------------------------------------------------






#include <stdio.h>

int main()
{
    int i,j,c;
    for (i=1;i<=5;i++)
    {
        c=6-i;
        for (j=1;j<=9;j++)
        {
            if(j>=6-i && j<=4+i)
            {
                printf("%d",c);
                j<5?c++:c--;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}



// ------------------------------------------------------------------



#include <stdio.h>

int main()
{
    int i,j;
    for (i=1;i<=5;i++)
    {
        int k=1;
        for (j=1;j<=9;j++)
        {
            if(j<=i || j>=10-i)
            {
                printf("%d",k);
                j<5?k++:k--;
            }
            else
            {
                printf(" ");
                if (j == 5) k--;
            }
        }
        printf("\n");
    }
}



// ------------------------------------------------------------------




#include <stdio.h>
int main()
{
    int i,j;
    for (i=1;i<=5;i++)
    {
        for (j=1;j<=5;j++)
        {
          if ( i==1 || i==3 || j==1 || (j==5 && i<=3)) 
          {
            //   if((i==3 && j==2 || i==3 && j==3 || i==3 && j==4))
            //   {
                printf("*");
           
            //   else
            //   {
            //       printf(" ");
            //   }
             
          }
          else
          {
              printf(" ");
          }
        }
        printf("\n");
    } 
}




