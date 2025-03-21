// #include <stdio.h>
// int main()
// {
//     int n,i,fact=1;
//     printf("enter number: ");
//     scanf("%d",&n);
//     for (i=1;i<=n;i++)
//     {
//         fact*=i;
//     }   
//     printf("factorial= %d",fact);
// }








// #include <stdio.h>
// int vowel(char vow[50])
// {
//     int count=0;
//     for (int i=0;i<=50;i++)
//     {
//         if(vow[i]=='a' || vow[i]=='e' || vow[i]=='i' || vow[i]=='o' || vow[i]=='u')
//         {
//             // printf("vowels: %c",vow[i]);
//             count++;
//         }
//     }
//     printf("no of vowels: %d",count);
// }

// int main()
// {
//     char vow[50];
//     printf("enter sentence: ");
//     fgets(vow,sizeof(vow),stdin);
//     vowel(vow);
// }








// #include <stdio.h>
// int main()
// {
//     for(int i=1;i<=5;i++)
//     {
//         for(int j=1;j<=5;j++)
//         {
//             if(j>=6-i)
//             {
//                 printf("*");
//             }
//             else
//             {
//                 printf("-");
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }








// #include <stdio.h>
// int leap_year(int year)
// {
//     if(year%4==0)
//     {
//         printf("%d is leap year",year);
//     }
//     else
//     {
//         printf("%d is not leap year",year);
//     }
// }

// int main()
// {
//     int year;
//     printf("enter year: ");
//     scanf("%d",&year);
//     leap_year(year);
// }











// #include<stdio.h>
// int swap(int a, int b)
// {
//     int c;
//     c=b;
//     b=a;
//     a=c;
//     printf("\nafter swap:\na=%d\nb=%d",a,b);
// }

// int main()
// {
//     int a,b;
//     printf("enter no 1: ");
//     scanf("%d",&a);
//     printf("enter no 2: ");
//     scanf("%d",&b);
//     printf("before swap: \na=%d \nb=%d",a,b);
//     swap(a,b);
// }








// #include <stdio.h>
// struct movies
// {
//     char title[50];
//     char genre[50];
//     char language[50];
// };

// int main()
// {
//     int n;
//     printf("Enter the number of movies: ");
//     scanf("%d", &n);
//     getchar();
//     struct movies movie[n];
    
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nEnter details for movie %d:\n", i + 1);
//         printf("Title: ");
//         fgets(movie[i].title, sizeof(movie[i].title), stdin);
        
//         printf("Genre: ");
//         fgets(movie[i].genre, sizeof(movie[i].genre), stdin);
        
//         printf("Language: ");
//         fgets(movie[i].language, sizeof(movie[i].language), stdin);

//     }
    
//     printf("\nMovie list:\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("movie %d:\n", i + 1);
//         printf("\tTitle: %s", movie[i].title);
//         printf("\tGenre: %s", movie[i].genre);
//         printf("\tLanguage: %s\n", movie[i].language);
       
//     }
    
//     return 0;
// }









#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");
    
    while ((ch = fgetc(inputFile)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            int chr = ch - 'a';
            ch = 'A' + chr;  
        }

        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Successfully converted\n");

    return 0;
}
