// #include <stdio.h>
// int main()
// {
//     int r,i,j;
//     printf("enter array size:");
//     scanf("%d",&r);
//     int a[r];
    
//     printf("enter arary elements:");
//     for (i=0;i<r;i++)
//     {
//         printf("a[%d]= ",i);
//         scanf("%d",&a[i]);
//     }
//     printf("\n");
    
//     printf("negative elements = ");
//     for (i=0;i<r;i++)
//     {
//         if(a[i]<0)
//         {
//             printf("%d",a[i]);
//         }
//         else
//         {
//             printf(" ");
//         }
//     }
// }





#include <stdio.h>
int main() {
    
    int r,c,i,j;
    printf("enter row size:");
    scanf("%d",&r);
    printf("enter column size:");
    scanf("%d",&c);
    int a[r][c];
    int x,y,z=0;

    printf("enter arary elements:");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
        
    }
    for(int i = 0 ; i < c ; i++)
    {
        for(int j = 0 ; j < r ; j++)
        {
          if (a[i][j]>z)
          {
              z=a[i][j];
          }
          
        }   
    }
    printf("largest elements is: %d",z);
}







// #include <stdio.h>
// int main() {
//     int r,c,i,j;
//     printf("enter row size:");
//     scanf("%d",&r);
//     printf("enter column size:");
//     scanf("%d",&c);
//     int a[r][c];
    
    
//     printf("enter arary A elements:");
//     for (i=0;i<r;i++)
//     {
//         for (j=0;j<c;j++)
//         {
//             printf("a[%d][%d]=",i,j);
//             scanf("%d",&a[i][j]);
//         }
//         printf("\n");
//     }
//     for (i=0;i<r;i++)
//     {
//         for (j=0;j<c;j++)
//         {
//             printf("%d ",a[i][j]);
//         }
//         printf("\n");
//     } 
//     printf("\n");
//     for (i=0;i<r;i++)
//     {
//         for (j=0;j<c;j++)
//         {
//             printf("%d ",a[j][i]);
        
//         }
//         printf("\n");
//     }
// }









// #include <stdio.h>
// int main()
// {
//     int r,c,i,j;
//     printf("enter row size:");
//     scanf("%d",&r);
//     printf("enter column size:");
//     scanf("%d",&c);
//     int a[r][c];
//     int sum=0;
    
    
//     printf("enter arary elements:");
//     for (i=0;i<r;i++)
//     {
//         for (j=0;j<c;j++)
//         {
//             printf("a[%d][%d]=",i,j);
//             scanf("%d",&a[i][j]);
//         }
//         printf("\n");
//     }
    
//     printf("enter row no:");
//     scanf("%d",&r);
//     printf("elements= ");
//     for (j=0;j<c;j++)
//     {
//         printf("%d ",a[r][j]);
//         sum+=a[r][j];
//     }
//     printf("\nsum =%d",sum);
//     printf("\n");
    
//     printf("enter column no:");
//     scanf("%d",&c);
//     printf("elements= ");
//     for (i=0;i<r;i++)
//     {
//         printf("%d ",a[i][c]);
//         sum+=a[i][c];
//     }
//     printf("\nsum =%d",sum);
// }