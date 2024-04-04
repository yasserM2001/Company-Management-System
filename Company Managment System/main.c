#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int day,month,year;
}Birth_Date;
typedef struct{
    int id;
    char lname[15],fname[15];
    float salary;
    Birth_Date d;
    char address[50];
    char phone_no[12];
    char email[50];
}Employee;
void create_file(char *file_name)
{
    FILE *f=fopen(file_name,"a");
    if(f==NULL){printf("ERROR,file not found");exit(1);}
    fclose(f);
}
int load(char *file_name,char*mode,Employee *x)
{
    char str[201];
    int i,cnt=0;
    char *tok;
    FILE *f=fopen(file_name,mode);
    if(f==NULL){
        printf("ERROR!!!File not found\n");exit(1);}
    while(!feof(f)){
        i=0;
        fgets(str,200,f);
        tok=strtok(str,", \t-\n");
        while(tok!=NULL){
            switch(i){
                case 0:(x+cnt)->id=atoi(tok);break;
                case 1:strcpy((x+cnt)->lname,tok);break;
                case 2:strcpy((x+cnt)->fname,tok);break;
                case 3:(x+cnt)->salary=atof(tok);break;
                case 4:(x+cnt)->d.day=atoi(tok);break;
                case 5:(x+cnt)->d.month=atoi(tok);break;
                case 6:(x+cnt)->d.year=atoi(tok);break;
                case 7:strcpy((x+cnt)->address,tok);break;
                case 8:strcpy((x+cnt)->phone_no,tok);break;
                case 9:strcpy((x+cnt)->email,tok);break;}
                i++;
            if(i==7)
                tok=strtok(NULL,",\t-\n");
            else tok=strtok(NULL,", \t-\n");}
        cnt++;}
    fclose(f);
    return cnt;
}
int is_valid_int(char*num)
{
    int i=0;
    while(num[i]!='\0'){
        if(!(num[i]>='0' && num[i]<='9')){
            printf("Please,enter numbers\n");
            return 0;}
            i++;}
    return 1;
}
int is_valid_name(char *name)
{
    int i;
    while(name[i]!='\0'){
        if(!(name[i]>='a' && name[i]<='z') && !(name[i]>='A' && name[i]<='Z')){
            printf("Please,enter letters\n");
            return 0;}
            i++;}
    return 1;
}
int is_valid_email(char *email)
{
    char *p1=strstr(email,"@");
    char*p2;
    if(p1)
        p2=strstr(p1,".");
    if(p2)return 1;
    else {printf("Please,enter a correct email contains(@ and .)\n");return 0;}
}
int is_valid_date(int day,int month,int year)
{
    if(day<=31 && day>0 && month<=12 && month>0 && year<2018)
        return 1;
    printf("Please,enter a correct date\n");
    return 0;
}
int is_valid_float(char* num)
{
     int i=0;
    while(num[i]!='\0'){
        if(!(num[i]>='0' && num[i]<='9') && num[i]!='.'){
            printf("Please,enter numbers\n");
            return 0;}
            i++;}
    return 1;
}
Employee add_new()
{
    Employee x;
    char ID[10],salary[15];
    do{
        printf("Enter employee id: ");
        scanf("%s",ID);}while(!is_valid_int(ID));
    x.id=atoi(ID);
    getchar();
    do{
        printf("Enter employee last name: ");
        gets(x.lname);}while(!is_valid_name(x.lname));

    do{
        printf("Enter employee first name: ");
        gets(x.fname);}while(!is_valid_name(x.fname));
    do{
        printf("Enter employee salary: ");
        scanf("%s",salary);}while(!is_valid_float(salary));
    x.salary=atof(salary);
    getchar();
    do{
        printf("Enter employee date of birth: \n");
        printf("day: ");
        scanf("%d",&x.d.day);
        printf("month: ");
        scanf("%d",&x.d.month);
        printf("year: ");
        scanf("%d",&x.d.year);}while(!is_valid_date(x.d.day,x.d.month,x.d.year));
    getchar();
    printf("enter employee address: ");
    gets(x.address);
    do{
        printf("enter employee phone number: ");
        gets(x.phone_no);}while(!(is_valid_int(x.phone_no)) || !(strlen(x.phone_no)==11));
    do{
        printf("enter employee email: ");
        gets(x.email);}while(!is_valid_email(x.email));
    return x;
}
void save_to_file(char *file_name,Employee *x,char*mode,int n)
{
    char str[200];
    int i;
    FILE *f=fopen(file_name,mode);
    if(f==NULL){printf("ERROR,file not found");exit(1);}
    for(i=0;i<n;i++){
    sprintf(str,"%5d,%15s,%15s,%12.3f,\t%2d-%2d-%4d,\t%32s,%25s,%25s\n",x[i].id,x[i].lname,x[i].fname,x[i].salary,x[i].d.day,x[i].d.month,x[i].d.year,x[i].address,x[i].phone_no,x[i].email);
    fprintf(f,str);}
    fclose(f);
}
void print_employee(Employee x)
{
     printf("ID: %d, Last name: %s, First name: %s, Salary: %.3f, Birth Date: %d/%d/%d, Address: %s, Phone number: %s, Email: %s\n",x.id,x.lname,x.fname,x.salary,x.d.day,x.d.month,x.d.year,x.address,x.phone_no,x.email);
}
void query(Employee *x,char *last_name,int n)
{
    int i,found=0;
    char s;
    for(i=0;i<n;i++){
        if(strcasecmp(last_name,x[i].lname)==0){
           print_employee(x[i]);found++;}}
    if(!found) printf("No employee with this last name\n");
}
void delete_employee(Employee *x,char *last_name,char *first_name,int *n,int*a)
{
    int i,j,found=0;
    char s;
    for(i=0;i<*n;i++){
        if((strcasecmp(last_name,x[i].lname)==0) && (strcasecmp(first_name,x[i].fname)==0)){
           j=i;
           for(j;j<*n-1;j++)
                x[j]=x[j+1];
           found++;}}
    if(!found) printf("No employee with this name\n");
    else {printf("All %s %s employees' details are deleted\n\n",first_name,last_name);
    *n=*n-1;
    *a=*a+1;}
}
void modify_employee(Employee *x,int id,int n,int *p)
{
    int i,y,found=0;
    char salary[10];
    for(i=0;i<n;i++)
        if(id==x[i].id){
        found=1;break;}
        if(found){
            while(1){
                printf("In order to modify Enter 1-Last name 2-First name 3-Salary 4-Birth date 5-Address 6-Phone number 7-Email 0-DONE: ");
                scanf("%d",&y);
                if(y==0)
                    break;
                else if(y==1){
                    getchar();
                    do{
                        printf("New last name: ");
                        gets(x[i].lname);
                    }while(!is_valid_name(x[i].lname));
                    (*p)++;}
                else if(y==2){
                    getchar();
                    do{
                        printf("New first name: ");
                        gets(x[i].fname);
                    }while(!is_valid_name(x[i].fname));
                    (*p)++;}
                else if(y==3){
                    do{
                        printf("New salary: ");
                        scanf("%s",salary);
                    }while(!is_valid_int(salary));
                    x[i].salary=atof(salary);
                    (*p)++;}
                else if(y==4){
                    do{
                        printf("New day: ");
                        scanf("%d",&x[i].d.day);
                        printf("New month: ");
                        scanf("%d",&x[i].d.month);
                        printf("New year: ");
                        scanf("%d",&x[i].d.year);
                    }while(!is_valid_date(x[i].d.day,x[i].d.month,x[i].d.year));
                    (*p)++;}
                else if(y==5){
                    getchar();
                    printf("New address: ");
                    gets(x[i].address);(*p)++;}
                else if(y==6){
                    getchar();
                    do{
                        printf("New phone number: ");
                        gets(x[i].phone_no);
                    }while(!is_valid_int(x[i].phone_no) || !(strlen(x[i].phone_no)==11));
                    (*p)++;}
                else if(y==7){
                    getchar();
                    do{
                        printf("New email: ");
                        gets(x[i].email);
                    }while(!is_valid_email(x[i].email));
                    (*p)++;}
                else printf("INVALID,Please enter valid option\n");}}
            else
                printf("No employee has this ID\n");
}
void sorted_lname(Employee *x,int n)
{
    int i,j;
    Employee temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++)
            if(strcasecmp(x[j].lname,x[j+1].lname)>0){
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;}
    }
}
void sorted_salary(Employee *x,int n)
{
    int i,j;
    Employee temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++)
            if(x[j].salary>x[j+1].salary){
        temp=x[j];
        x[j]=x[j+1];
        x[j+1]=temp;}
}
}
void sorted_date(Employee *x,int n)
{
    int i,j;
    Employee temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++)
        {
            if(x[j].d.year<x[j+1].d.year){
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;}
            else if(x[j].d.year==x[j+1].d.year && x[j].d.month<x[j+1].d.month){
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;}
            else if(x[j].d.year==x[j+1].d.year && x[j].d.month==x[j+1].d.month && x[j].d.day<x[j+1].d.day){
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;}
            }
        }
}
void print_all(Employee *x,int n)
{
    int i;
    for(i=0;i<n;i++)
        print_employee(x[i]);
}
int main()
{
    Employee emp[100];
    char file_name[]="Company.txt";
    create_file(file_name);
    int n=0;
    n=load(file_name,"r",emp);
    n=n-1;
    int opt,i=0,j=0,id,opt2;
    char c,last_name[15],first_name[15];
    while(1){
        printf("ENTER 1-Add new employee 2-Save to file 3-Query(search for employee) 4-Delete an employee 5-Modify 6-Print all sorted 0-EXIT: ");
        scanf("%d",&opt);
        if(opt==0){
            if(j!=0){
                printf("WARNING!!!!\a\nyou are about to exit without saving to the file,are you sure you want to exit?\n");
                printf("Enter y-to exit or n-to continue: ");
                scanf(" %c",&c);
                if(c=='y')break;
                else if(c=='n')continue;}
            else if (i==0)break;}
        else if(opt==1){emp[n]=add_new();n++;j++;}
        else if(opt==2){
            if(j==0)printf("No changes to be saved!!!\n");
            else {save_to_file(file_name,emp,"w",n);printf("Data saved successfully\n");j=0;}
            i=0;}
        else if(opt==3){
            printf("Enter the last name of employee you search for: ");
            getchar();
            gets(last_name);
            query(emp,last_name,n);
        }
        else if(opt==4){
            printf("Enter the last name of employee you delete for: ");
            getchar();
            gets(last_name);
            printf("Enter the first name of employee you delete for: ");
            gets(first_name);
            delete_employee(emp,last_name,first_name,&n,&j);
            }
        else if(opt==5){
            printf("Enter the id of employee to be modified: ");
            scanf("%d",&id);
            modify_employee(emp,id,n,&j);
        }
        else if(opt==6){
            printf("Enter 1-Sort(last name) 2-Sort(salary) 3-Sort(birth date): ");
            scanf("%d",&opt2);
            if(opt2==1){
                sorted_lname(emp,n);
                j++;}
            else if(opt2==2){sorted_salary(emp,n);j++;}
            else if(opt2==3){sorted_date(emp,n);j++;}
            else {printf("INVALID\n");continue;}
            print_all(emp,n);
            printf("\n");}
        else printf("INVALID,Please enter valid option\n");
    }
    return 0;
}

