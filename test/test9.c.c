// #include <stdio.h>
// int main()
// {
//     FILE *evenfile, *oddfile;
//     int i;

//     evenfile = fopen("even.txt", "w");
//     oddfile = fopen("odd.txt", "w");
    
//     if (evenfile == NULL || oddfile == NULL)
//     {
//         printf("Error open file!\n");
//         return 1;
//     }

//     for (i = 50; i <= 70; i++)
//     {
//         if (i % 2 == 0)
//         {
//             fprintf(evenFile, "%d\n", i);
//         }
//         else
//         {
//             fprintf(oddFile, "%d\n", i);
//         }
//     }

//     fclose(evenFile);
//     fclose(oddFile);

//     printf("Numbers written to files successful.\n");
//     return 0;
// }







// #include <stdio.h>
// struct student
// {
// 	char name[50];
// 	int roll_no;
// 	int chemistry;
// 	int maths;
// 	int physics;
// };

// int main()
// {
// 	int n,total,percentage;
// 	struct student s[5];

// 	for (int i = 0; i <=4 ; i++)
// 	{
// 		printf("Enter details for student %d:\n", i+1);
		
// 		printf("name: ");
// 		scanf("%s",s[i].name);

// 		printf("roll no: ");
// 		scanf("%d",&s[i].roll_no);

// 		printf("chemistry: ");
// 		scanf("%d",&s[i].chemistry);

// 		printf("maths: ");
// 		scanf("%d",&s[i].maths);

// 		printf("physics: ");
// 		scanf("%d",&s[i].physics);
// 	}

// 	for (int i = 0; i <=4 ; i++)
// 	{
// 		if(s[i].chemistry<=100 && s[i].maths<=100 && s[i].physics<=100)
// 		{
// 			printf("\n\n%s (%d)",s[i].name,s[i].roll_no);
// 			printf("\nchemistry= %d",s[i].chemistry);
// 			printf("\nmaths= %d",s[i].maths);
// 			printf("\nphysics= %d",s[i].physics);
			
// 			total=s[i].chemistry+s[i].maths+s[i].physics;
// 			percentage=(total*100)/300;
			
// 			printf("\ntotal: %d/300",total);
// 			printf("\npercentage: %d",percentage);
// 		}
// 		else
// 		{
// 			printf("\ninvalid marks");
// 			break;
// 		}
// 	}
// 	return 0;
// }
