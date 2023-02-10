                                         //Library Management System ......
#include<stdio.h>
#include<string.h>
void issue_book();
void Addstudent();
void Books();
void search_student();

struct student_info{
    char student_ID[11];
    char name[30];
    char department[11];
};
typedef struct student_info sinfo;
struct issue_book{
    char ID_STU[11];//student ID
    int bookc;//book code

};
FILE *studentinfo, *bookinfo,*issuebook;
void main()
{
    char userid[]="011221xxx";
     char id[11];
     char pass[]="student";
     char p[10];
     int match;
     puts("\t\t\tHello please Enter your details");
     printf("\tEnter your ID(011221xxx):");
     gets(id);
     printf("\tEnter your password(student):");
     gets(p);
      match=strcmp(p,pass);
      switch (match){
          case 0:  printf("\n\t\t\t successfully Logged  in\n\n");
                menu();
                break;
         default :  printf("wrong");

    }

}
void menu()
{
    char ch;
    puts("\t\t\tWelcome To Home page");
     printf("\n\t a. Add student\n");
    printf("\t b. Search Student\n ");
    printf("\t c. Book\n ");
    printf("\t d. issue book; \n ");
    printf("\t e. Exit\n ");
    printf("\t\tEnter Your Choice: ");
    fflush(stdin);
    scanf("%c",&ch);

    switch(ch){
    case'a':
         Addstudent();
          break;
    case 'b':
         search_student();
        break;
    case 'c':
        Books();
        break;
    case 'd':
       issue_book();
        break;
    case 'e':

        break;
    default:
        printf("\n\t\tWrong Entry.\n\t\tPlease Enter Right Character.\n");
        main();
    }


}

 void Addstudent()
 {
     sinfo student;
     studentinfo=fopen("studentinfo.txt","a");

     puts("Enter your Student ID:");
     fflush(stdin);
     fgets(student.student_ID,11,stdin);
     puts("Your name:");
     fgets(student.name,30,stdin);
     puts("Your Department:");
     fgets(student.department,11,stdin);

     fprintf(studentinfo,"Student ID:%s \n Name:%s \nDepartment:%s",student.student_ID,student.name,student.department);

     puts("Thanks For the Information we have enlisted Your name....");
     fclose(studentinfo);
     menu();

 }
 void search_student(struct student_info x)
 {
     sinfo n;
     char ch[50];
     studentinfo=fopen("studentinfo.txt","r+");

            while(!feof(studentinfo)){

        fscanf(studentinfo,"%s",ch);
        printf("%s\n");
            }
            fclose(studentinfo);


 }
void Books(){
struct library
{
    char book_name[30];
    char Book_AuthorName[30];
    int Book_code;
    float price;
};
struct library books[100];
    char aname[30],bname[30];
    int i,j, keepcount;
    i=j=keepcount = 0;

while(j!=6)
{
    puts("\t\t\tWelcome To Book Site");
    printf("\n\n\t\t1. Add book information\n\t\t2. Display book information.\n");
    printf("\t\t3. List all books of given Book AuthorName.\n");
    printf("\t\t4. List the title of specified book\n");
    printf("\t\t5. List the count of books in the library\n");
    printf("\t\t6. Exit and main menu...");
    printf ("\n\n\t\t\tEnter one of the above : ");
    scanf("%d",&j);

     switch (j)
{
/* Add book */
           case 1:

              printf ("Enter book name = ");
              scanf ("%s",books[i].book_name);

               printf ("Enter Book_AuthorName name = ");
               scanf ("%s",books[i].Book_AuthorName);

               printf ("Enter Book_code = ");
               scanf ("%d",&books[i].Book_code);

               printf ("Enter price = ");
              scanf ("%f",&books[i].price);
               keepcount++;
               break;
        case 2:
           printf("you have entered the following information\n");
          for(i=0; i<keepcount; i++){
            printf ("book name = %s",books[i].book_name);

            printf ("\t Book_AuthorName name = %s",books[i].Book_AuthorName);

            printf ("\t  Book_code = %d",books[i].Book_code);

            printf ("\t  price = %f",books[i].price);
         }
           break;
       case 3:
          printf ("Enter Book_AuthorName name : ");
          scanf ("%s",aname);
          for (i=0; i<keepcount; i++){
                  if (strcmp(aname, books[i].Book_AuthorName) == 0)

                              printf ("%s %s %d %f",books[i].book_name,books[i].Book_AuthorName,books[i].Book_code,books[i].price);
                }
                           break;
        case 4:
               printf ("Enter book name : ");
               scanf ("%s",bname);
              for (i=0; i<keepcount; i++){
                           if (strcmp(bname, books[i].book_name) == 0)
                                   printf ("%s \t %s \t %d \t %f",books[i].book_name,books[i].Book_AuthorName,books[i].Book_code,books[i].price);
                        }
                            break;

        case 5:
             printf("\n No of books in library : %d", keepcount);
                break;
       case 6:
            return menu();


     }
   }
}
void issue_book()
 {
     struct issue_book list;
     issuebook=fopen("issueBook.txt","w");
     printf("Enter Student ID:");
     fflush(stdin);
     fgets(list.ID_STU,11,stdin);
     printf("Enter code Of book:");
     scanf("%d",&list.bookc);

     fprintf(issuebook,"Student ID:%s\nBook Code:%d",list.ID_STU,list.bookc);
     fclose(issuebook);
     printf("Your name Enlisted In File........");

 }
