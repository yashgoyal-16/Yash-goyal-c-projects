#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct books{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}b;


struct student{
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
}s;

FILE *fp;
void addbook() {
    struct books b;
    char mydate[15];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(mydate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    strcpy(b.date, mydate);
    fp = fopen("new.txt", "ab");

    printf("Enter book id: \n");
    scanf("%d", &b.id);
    printf("Enter book name:\n");
    scanf(" %49[^\n]", b.bookName);
    printf("Enter author name:");
    scanf(" %49[^\n]", b.authorName);
    printf("Book added successfully\n");
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}

void viewbookList(){
struct books b;
system("cls");
printf("<== Avaliable Books list ==>\n\n" );
printf("%-10s %-30s %-20s %s\n\n" ,"book id" , "book Name","author", "Date");
fp = fopen("new.txt","rb");
while(fread(&b,sizeof(b),1,fp) == 1){
    printf("%-10d %-30s %-20s %s\n", b.id, b.bookName, b.authorName, b.date);

}
fclose(fp);
}
void removebook(){
int id,f=0;
system("cls");
printf("<== Book Remove ==>\n\n");
printf("Enter the Book to be Removed : ");
scanf("%d",&id);
FILE *ft;

fp = fopen("new.txt","rb");
ft = fopen("temp.txt","wb");
while(fread(&b,sizeof(b),1,fp)==1){
    if(id==b.id){
 f = 1;
}
else{
    fwrite(&b,sizeof(b),1,ft);
}
}
if(f==1){
    printf("Book Deleted Successfuly");

}
else{
    printf("not any book avaliable of this id");
}
fclose(fp);
fclose(ft);
remove("new.txt");
rename("temp.txt","new.txt");
}
void issuebook(){
char mydate[15];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(mydate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    strcpy(s.date, mydate);
    int f =0;
    system("cls");
    printf("<-- ISSUE BOOK -->\n\n");
    printf("Enter the book id to issue :");
    scanf("%d",&s.id);
    fp = fopen("new.txt","rb");
    while(fread(&b,sizeof(b),1,fp) == 1){
            if(b.id == s.id){
                strcpy(s.bookName,b.bookName);
                f = 1 ;
                break;
            }

    }
    if(f==0){
        printf("No book found with this id  :-) \n");
        printf("plz try again\n");
        return;
    }
    fp = fopen("issue.txt","ab");
    printf("Enter the Student Name :");
    scanf("%s",&s.sName);
    printf("Enter the Student Class :");
    scanf("%s",&s.sClass);
    printf("Enter the roll no.");
    scanf("%d",&s.sRoll);
    printf("Book added succesfuly");
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);

}
void issueBook(){

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    int f=0;

    system("cls");
    printf("<== Issue Books ==>\n\n");

    printf("Enter Book id to issue: ");
    scanf("%d", &s.id);

    //Check if we have book of given id
    fp = fopen("books.txt", "rb");

    while(fread(&b, sizeof(b), 1, fp) == 1){
        if(b.id == s.id){
            strcpy(s.bookName, b.bookName);
            f=1;
            break;
        }
    }

    if(f==0){
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }

    fp = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.sName);

    printf("Enter Student Class: ");
    fflush(stdin);
    gets(s.sClass);

    printf("Enter Student Roll: ");
    scanf("%d", &s.sRoll);

    printf("Book Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void issuelist(){
    system("cls");
    printf("<== Book Issue List ==>\n\n");

    printf("%-10s %-30s %-20s %-10s %-30s %-20s %s\n\n", "S.id", "Name", "Class", "Roll", "Book name","Date");

    fp = fopen("issue.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("%-10d %-30s %-20s %-10d %-30s %-20s %s\n", s.id, s.sName, s.sClass, s.sRoll, s.bookName, s.date);
    }

    fclose(fp);
}

int main(){
 int ch;

    while(1){
        system("cls");
        printf("<== Library Management System ==>\n");
        printf("1.Add Book\n");
        printf("2.Books List\n");
        printf("3.Remove Book\n");
        printf("4.Issue Book\n");
        printf("5.Issued Book List\n");
        printf("0.Exit\n\n");
        printf("Enter your choices :\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0 : exit(0); break;
            case 1: addbook();break;
            case 2: viewbookList();break;
            case 3: removebook();break;
            case 4: issuebook();break;
            case 5: issuelist();break;
            default: printf("error due to wrong input");

}
printf("\n\n press any key to continue ");
getch();
}
        return 0;
        }
