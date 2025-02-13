// #include <stdio.h>
// int main()
// {
//     char a1='a';
//     // initialising a1 as char to print alphabets
    
//     do
//     {
//         printf("%c ",a1);
//         a1+=4;
//         // skipping alphabets by 3 letters
        
//     }
//     while(a1<='z');
//     //loop will run upto z
    
// }


--------------------------------------------------------------

// #include <stdio.h>

// int main() {
//     int number, count = 1;
    
//     printf("Enter a number: ");
//     scanf("%d", &number);
    
//     while (number >= 10)
//     {
//         number /= 10;
//         count++;
//         // increementing count untill value of number becomes 0
//     }
    
    
//     printf("Total number of digits: %d\n", count);
    
//     return 0;
// }


--------------------------------------------------------------

#include <stdio.h>

int main() 
{
	
        int num , sum , firstdigit , lastdigit;
        printf("Enter number :");
        scanf("%d",&num);
        lastdigit = num %10 ;
        while (num>=10)
        {
            num = num / 10 ;
        }
        firstdigit=num;
        
        sum = firstdigit+lastdigit; 
        
        printf("%d",sum);
    return 0;
}