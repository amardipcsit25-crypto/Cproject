// header file
#include<stdio.h>
#include<string.h>
// structure initialize
struct employee{
    int emp_id;
    char emp_name[50];
    char emp_gender[10];
    int emp_age;
    char emp_department[50];
     long int salary;
};
int main(){
struct employee emp[24];
int i,j,k;
int number; 
char password[50],c;
int checked=0;
FILE *ep;
//using the password here 
for(j=0;j<3;j++){  // how much time user can try the password
     printf("Enter the password to access employee data: ");
        scanf("%s", password);
            if(strcmp(password,"Project@123")==0){
                checked=1;
                  break;
                    }
                       else{
                                printf("NOT MATCH , TRY AGAIN !\n");
                                 }
                                     } 
         if(checked==0){   // if user enter wrong password 3 times then access will be denied
               printf("Permission denied!\n");
                  return 1;
                     }
    do{        
    ep=fopen("empdata.txt","r"); // opening file in read mode   
           if(ep==NULL){              //checking file is exist or not
               printf("File not found");
                      return 0;
                                }
//    using the switch   
 printf("1.For highest and lowest salary:\n");
 printf("2.For display employees from the IT department:\n");
 printf("3.For employees with salary above the average salary:\n");
 printf("4.For count employees in each department:\n");
 printf("Enter the number between (1 and 4) that you have to explain:");
 scanf("%d",&number);
  switch(number){
    case 1:
         for (i=0;i<24;i++){  
              fscanf(ep,"%d %s %s %d %ld %s",&emp[i].emp_id,emp[i].emp_name,emp[i].emp_gender,&emp[i].emp_age,&emp[i].salary,&emp[i].emp_department); 
               }
                 // FIND HIGHEST AND LOWEST SALARY //
int max = 0, min = 0;

for(i=1;i<24;i++){
    if(emp[i].salary > emp[max].salary){
        max = i;
    }
    if(emp[i].salary < emp[min].salary){
        min = i;
    }
}

printf("\nHIGHEST SALARY EMPLOYEE:\n");
printf("ID=%d\n",emp[max].emp_id);
printf("NAME=%s\n",emp[max].emp_name);
printf("GENDER=%s\n",emp[max].emp_gender);
printf("AGE=%d\n",emp[max].emp_age);
printf("DEPARTMENT=%s\n",emp[max].emp_department);
printf("SALARY=%ld\n",emp[max].salary);

printf("\nLOWEST SALARY EMPLOYEE:\n");
printf("ID=%d\n",emp[min].emp_id);
printf("NAME=%s\n",emp[min].emp_name);
printf("GENDER=%s\n",emp[min].emp_gender);
printf("AGE=%d\n",emp[min].emp_age);
printf("DEPARTMENT=%s\n",emp[min].emp_department);
printf("SALARY=%ld\n",emp[min].salary);
 printf("\n");    // to break the line for another input  of switch 
 
                 break;             // for avoiding unnecessary condition
    case 2 :
         printf("Details of employees from IT department:\n");             
          for (i=0;i<24;i++){     // using loop
             fscanf(ep,"%d %s %s %d %ld %s",&emp[i].emp_id,emp[i].emp_name,emp[i].emp_gender,&emp[i].emp_age,&emp[i].salary,&emp[i].emp_department);  
          }
                              printf("\n");    // to break the line for another input  of switch 
                                    break;
    case 3:
            for (i=0;i<24;i++){  
                fscanf(ep,"%d %s %s %d %ld %s",&emp[i].emp_id,emp[i].emp_name,emp[i].emp_gender,&emp[i].emp_age,&emp[i].salary,&emp[i].emp_department); 
                     }
                       printf("For employees with salary above the average salary:");
                            printf("\n");
                                  break;
    case 4:
             for (i=0;i<24;i++){  
              fscanf(ep,"%d %s %s %d %ld %s",&emp[i].emp_id,emp[i].emp_name,emp[i].emp_gender,&emp[i].emp_age,&emp[i].salary,&emp[i].emp_department); 
               }
                  printf("For count employees in each department:");
                    printf("\n");
                                 break;
    default: 
             printf("Invalid number you have enter");  
                 printf("\n");
                     }

                                               printf("Do you want to continue (y/n): ");
                                                    scanf(" %c", &c);  // space %c is used to avoid the buffer problem
                                                     }
                                                         while(c=='y'||c=='Y');
                                                        printf(" exit the file ");
fclose(ep);  //closing file   
return 0;
}