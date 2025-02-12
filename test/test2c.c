#include<stdio.h>
int main()
{
	int k=0;
	printf("enter number:");
	scanf("%d",&k);
	char grade;
	grade=(k>=91)
	    ?'A'
	    :k>=81?'B'
	    :k>=71?'C'
	    :k>=61?'D'
	    :k>=51?'E'
	    :'F';
	    printf("grade is %c.",grade);
	    
    
    // grade=k;
	switch(grade)
	{
	    case 'A':
    		printf(" Excellent work");
    		break;
    	case 'B':
    	    printf(" well done");
    	    break;
    	case 'C':
    	    printf(" good job");
    	    break;
        case 'D':
            printf(" you passed");
            break;
        case 'E':
            printf(" you can do better");
            break;
	    case 'F':
	        printf(" you failed");
	        break;
	    default:
	        printf(" invalid input");
	}
	if (grade== 'A' ||grade== 'B' ||grade== 'C'||grade== 'D'||grade== 'E')
    {
        printf(" Congratulations! You are eligible for next level");
    }
    else if (grade== 'F')
    {
        printf("Please try again next time");
    }
    else 
    {
        printf("invalid Input...");
    }
	
    return 0;
}