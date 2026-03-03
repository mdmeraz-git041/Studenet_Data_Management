#include<stdio.h>
#include<string.h>
                                    /*
                                    =====================================================================================
                                                        PROJECT :  STUDENTS DATA MANAGEMENT SYSTEM
                                    =====================================================================================
                                                                MINI PROJECT DESCRIPTION

                                        This project is a result of our continuous hard work, patience,and dedication 
                                        towards learning programming and improving our logical thinking skills.

                                        While developing this project, We faced many challenges, errors,and moments 
                                        of confusion. However, instead of giving  up, We stayed consistent and kept 
                                        practicing until We found the correct solutions.

                                        This project represents not only Our technical knowledge but also our 
                                        passion, discipline, and  enthusiasm  for  coding. It  helped  us understand 
                                        important  concepts  such  as  problem  solving,  logic building, and writing
                                        structured programs.

                                        We believe this is just the beginning of our programming journey, and we are 
                                        committed to continuously learning, improving, and building more efficient and 
                                        meaningful projects in the future.

                                        Developed by: Team Members ["Meraz","Ehtesham","Muttalib","Sarah","Lubna"]
                                        Language: C Programming
                                        Purpose: Learning and Skill Development
                                        Starting date : 27-Feb-2026
                                    ======================================================================================
                                    */

    int main() {    
        // varialble for common use
        int ch,ch1,i,j,n,flag,totalStudent=0;
        int rollno;    
        
        //variable for authentication process                                                                                                                                                             
        int userInputPass,attemps=0,maxAttemps=3;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        const char userName[]="nextcoder_041";     const int password = 250062;    
        
        //variable for storing student details
        int roll[10],year[10];
        char studentName[20][20],fatherName[20][20], course[20][20],enroll[20][10];

        //variable for storing result details
        int examYear,totalSub=0,fullMarks;
        int subjectMarks[20][10],totalMarks[20];
        float avgMarks[20];
        char examName[20],sem[10],month[10],subjectName[20][20];
    
        //Authentication for further process
        printf("\n\n\t     Welcome to nextcoder world");
        printf("\n\n  ======== Student Data Management System ========");
        printf("\n\t\tLogin Your Page");
        printf("\n\t   My Username : %s\n",userName);
        do {
        flag=0;
        printf("\tEnter Password : ");
        scanf("%d",&userInputPass);
        if (password==userInputPass) {
            flag=1;
        }     
        if(flag==1) printf("\n\t\tLogin Successfully");          
        
        else if(flag==0 && attemps<maxAttemps) {
            if (attemps<maxAttemps-1) {
                printf("\n\t\t Login Failed\n\tIncorrect password! Please enter again.\n");
                if (attemps==maxAttemps-2) printf("\t  Make sure this is your last attemp.\n");        
            }
            else printf("\n\t\t Login Failed\n\t\tIncorrect password!\n");
            attemps++;
        }
        } while (flag!=1 && attemps<maxAttemps);
        //Here code eneded for 'Authentication process'


        //Student Data Management System start here
        if(attemps<maxAttemps) {
        do {
            printf("\n\n  ======= Student Data Management System =======");
            printf("\n\t  1. Add New Student (1-10)");
            printf("\n\t  2. Delete Student");
            printf("\n\t  3. Search Student");
            printf("\n\t  4. Desplay All Students");
            printf("\n\t  5. Result Upload");
            printf("\n\t  6. Exit");
            printf("\n\t  Enter your choice : ");
            scanf("%d", &ch);

            //Code for 'Add New Student'
            if(ch==1) {
                printf("\nEnter number of student to add : ");
                scanf("%d", &n);
                totalStudent += n; 
                for(i=0; i<n; i++) {                
                    printf("\nEnter %d student's details",i+1);
                    printf("\nStudent Name(in one word): ");
                    scanf("%s", &studentName[i]);
                    printf("Father's Name(in one word): ");
                    scanf("%s", &fatherName[i]);
                    do{ 
                    flag = 0;
                    printf("Roll no: ");
                    scanf("%d",&roll[i]);
                            for ( j=0; j<i; j++){
                                if (roll[i]==roll[j]){
                                    flag=1;
                                    printf("\tThe roll number is already existed! Enter diffrent roll number\n");
                                    break;
                                }
                            }
                            } while (flag==1);
                    do{
                    flag = 0;
                    printf("Enrollment no: ");
                    scanf("%s", &enroll[i]);
                    for ( j=0; j<i; j++){
                        if (strcmp(enroll[i],enroll[j])==0){
                            flag=1;
                            printf("\tThe enroll number is already existed! Enter diffrent enroll number\n");
                            break;
                        }
                    }
                    } while (flag==1);
                    printf("Course : ");
                    scanf("%s", &course[i]);
                    printf("Year of Addmission: ");
                    scanf("%d", &year[i]);
                    printf("Student(%d) '%s' with roll no '%d' added Successfully.",i+1,studentName[i],roll[i]);
                    printf("\n");
                }
                printf("\n\tTotal ");
                if(n==1) printf("one");
                else if(n==2) printf("two");
                else if(n==3) printf("three");
                else if(n==4) printf("four");
                else if(n==5) printf("five");
                else if(n==6) printf("six");
                else if(n==7) printf("seven");
                else if(n==8) printf("Eeight");
                else if(n==9) printf("nine");
                else if(n==10) printf("ten");
                if(n==1) printf(" student");
                else if(n>1) printf(" students");
                printf(" added successffully.");                
            } //Here code ended for 'add new student'

            //Code for 'delete student'
            else if(ch==2) {
                if(totalStudent !=0 ) {
                do {
                flag=0;
                printf("\n\tEnter(0) to back");
                printf("\n\tEnter roll number to delete: ");
                scanf("%d",&rollno);
                for(i=0; i<=n; i++) {
                    if(roll[i] == rollno || rollno==0) {
                        flag = 1;
                        break;
                    }
                } 
                if(flag==1 && rollno!=0) {
                    for(i=0; i<n; i++) {
                        if(rollno==roll[i]) {
                            for(j=i+1; j<n; j++) {
                                roll[j-1]=roll[j];
                                year[j-1]=year[j];
                                strcpy(enroll[j-1],enroll[j]);
                                strcpy(studentName[j-1],studentName[j]);
                                strcpy(fatherName[j-1],fatherName[j]);
                                strcpy(course[j-1],course[j]);
                            }
                            
                        }
                    }

                    //Deleting last copied student
                    roll[n-1]=0;
                    year[n-1]=0;
                    enroll[n-1][0]='\0';
                    studentName[n-1][0]='\0';
                    fatherName[n-1][0]='\0';
                    course[n-1][0]='\0';
                    totalStudent--;
                    printf("\n\tStudent of roll number '%d' has been deleted successfully",rollno);
                } 
                else if(flag==0) printf("\tRoll number not found! Try again.\n");                     
                
                } while (flag!=1);
                }    
                else printf("\nThere is no student added! Add student first,then move to delete.");
                    
            } //Here code ended for 'delete student'.

            //Code for 'search student'.
            else if (ch==3) {
                if(totalStudent !=0 ) {
                do {
                flag=0;
                printf("\n\tEnter(0) to back");
                printf("\n\tEnter roll number to search: ");
                scanf("%d",&rollno);
                for(i=0; i<=n; i++) {
                    if(rollno == roll[i] || rollno==0) {
                        flag = 1;
                        break;
                    }
                }  
                //Desplaying 'Student Details'
                if(flag==1 && rollno!=0) {
                    printf("\n****************************************************");
                    printf("\n\t Maulana Azad National Urdu University");
                    printf("\n\t\tDeparment of CS&IT");
                    printf("\n****************************************************");
                    printf("\n\t   ===== Student Details =====\n");
                    printf("\n Student Name: %s\t\t  Roll no: %d",studentName[i],roll[i]);
                    printf("\n Father's Name: %s\t\t  Enroll no: %s",fatherName[i],enroll[i]);
                    printf("\n Course: %s\t\t\t  Year : %d",course[i],year[i]);
                    printf("\n****************************************************");
                }
                else if(flag==0)  printf("\tRoll number not found! Try again.\n");                   
                
                } while(flag!=1);
                }
                else printf("\nThere is no student added! Add student first,then move to search.");                    
                
            } //Here code ended for 'search student'.

            //Code for 'desplay all students'.
            else if(ch==4) {
                if(totalStudent !=0 ) {
                    printf("\n*******************************************************************************");
                    printf("\n\t\t    Maulana Azad National Urdu University");
                    printf("\n\t\t\t   Deparment of CS&IT");
                    printf("\n*******************************************************************************");
                    printf("\n\t\t     =====All Student's Details =====");
                    printf("\n\nTotal no of student : %d\n",totalStudent);
                    printf("\nRoll no\t  Enrollment no\t  Student's Name\tFather's Name\tCourse\t  Year");
                    for(i=0; i<n; i++) {
                        printf("\n  %d\t  %s\t  %s\t\t\t%s\t\t%s\t  %d",roll[i],enroll[i],studentName[i],fatherName[i],course[i],year[i]);
                    }
                printf("\n*******************************************************************************");
                }

                else printf("\nThere is no student added! Add student first,then move to display.");
                    
            } //Here code ended for 'desplay all student'.

            //Code for 'Result Details'
            else if(ch==5) {
                if(totalStudent !=0 ) {
                    do {
                        printf("\n   ===== Result Details =====");
                        printf("\n\t  1.Fill Exam Details");
                        printf("\n\t  2.Upload Marksheet");
                        printf("\n\t  3.Download Marksheet");
                        printf("\n\t  4.Back to Home");
                        printf("\n\t  Enter your Choise : ");
                        scanf("%d",&ch1);
                        //Code for 'Filling Exam Details'
                        if(ch1==1) {
                            printf("\nFill Exam Details");
                            printf("\nName of Exam(in one word) : ");
                            scanf("%s",&examName);
                            do{
                            flag=0;
                            printf("Semester of Exam(First to Eighth) : ");
                            scanf("%s",&sem);
                                // Check Cardinal number for Semester (as string) 
                                if (strcmp(sem,"1")==0  || strcmp(sem,"2")==0  ||
                                    strcmp(sem,"3")==0  || strcmp(sem,"4")==0  ||
                                    strcmp(sem,"5")==0  || strcmp(sem,"6")==0  ||
                                    strcmp(sem,"7")==0  || strcmp(sem,"8")==0 ) {                                                      
                                    flag = 1;
                                }
                                // Check Ordinal number for Semester with first letter capital
                                else if(strcmp(sem,"First")==0  || strcmp(sem,"Second")==0  ||
                                        strcmp(sem,"Third")==0  || strcmp(sem,"Fourth")==0  ||
                                        strcmp(sem,"Fifth")==0  || strcmp(sem,"Sixth")==0  ||
                                        strcmp(sem,"Seventh")==0  || strcmp(sem,"Eighth")==0 ) {                                                      
                                        flag = 1;
                                }
                                // Check Ordinal number for Semester with first letter small
                                else if(strcmp(sem,"first")==0  || strcmp(sem,"second")==0  ||
                                        strcmp(sem,"third")==0  || strcmp(sem,"fourth")==0  ||
                                        strcmp(sem,"fifth")==0  || strcmp(sem,"sixth")==0  ||
                                        strcmp(sem,"seventh")==0  || strcmp(sem,"eighth")==0 ) {                                                      
                                        flag = 1;
                                }
                                // Check Ordinal number for Semester with each letter capital
                                else if(strcmp(sem,"FIRST")==0  || strcmp(sem,"SECOND")==0  ||
                                        strcmp(sem,"THIRD")==0  || strcmp(sem,"FOURTH")==0  ||
                                        strcmp(sem,"FIFTH")==0  || strcmp(sem,"SIXTH")==0  ||
                                        strcmp(sem,"SEVENTH")==0  || strcmp(sem,"EIGHTH")==0 ) {                                                      
                                        flag = 1;
                                }
                                else printf("\t Invalid semester ! Enter valid semester\n");                                    
                                
                            } while (flag == 0) ; 
                                                    
                            do {
                            flag = 0;
                            printf("Month of Exam (January to December): ");
                            scanf("%s", month);                                   
                                //Check Number for name of Month (as string) 
                                if (strcmp(month,"1")==0  || strcmp(month,"2")==0  ||
                                    strcmp(month,"3")==0  || strcmp(month,"4")==0  ||
                                    strcmp(month,"5")==0  || strcmp(month,"6")==0  ||
                                    strcmp(month,"7")==0  || strcmp(month,"8")==0  ||
                                    strcmp(month,"9")==0  || strcmp(month,"10")==0 ||
                                    strcmp(month,"11")==0 || strcmp(month,"12")==0) {
                                    flag = 1;
                                } 
                                // Check for Full name of Month with first letter capital
                                else if (strcmp(month,"January")==0 || strcmp(month,"February")==0 ||
                                        strcmp(month,"March")==0 || strcmp(month,"April")==0 ||
                                        strcmp(month,"May")==0 || strcmp(month,"June")==0 ||
                                        strcmp(month,"July")==0 || strcmp(month,"August")==0 ||
                                        strcmp(month,"September")==0 || strcmp(month,"October")==0 ||
                                        strcmp(month,"November")==0 || strcmp(month,"December")==0) {
                                        flag = 1;
                                }
                                // Check for Full name of Month with first letter small
                                else if (strcmp(month,"january")==0 || strcmp(month,"february")==0 ||
                                        strcmp(month,"march")==0 || strcmp(month,"april")==0 ||
                                        strcmp(month,"may")==0 || strcmp(month,"june")==0 ||
                                        strcmp(month,"july")==0 || strcmp(month,"august")==0 ||
                                        strcmp(month,"september")==0 || strcmp(month,"october")==0 ||
                                        strcmp(month,"november")==0 || strcmp(month,"december")==0) {
                                            flag = 1;
                                }
                                // Check for Short name of Month with first letter capital
                                else if (strcmp(month,"Jan")==0 || strcmp(month,"Feb")==0 ||
                                        strcmp(month,"Mar")==0 || strcmp(month,"Apr")==0 ||
                                        strcmp(month,"May")==0 || strcmp(month,"Jun")==0 ||
                                        strcmp(month,"Jul")==0 || strcmp(month,"Aug")==0 ||
                                        strcmp(month,"Sep")==0 || strcmp(month,"Oct")==0 ||
                                        strcmp(month,"Nov")==0 || strcmp(month,"Dec")==0) {
                                            flag = 1;
                                }
                                // Check for Short name of Month with first letter small
                                else if (strcmp(month,"jan")==0 || strcmp(month,"feb")==0 ||
                                        strcmp(month,"mar")==0 || strcmp(month,"apr")==0 ||
                                        strcmp(month,"may")==0 || strcmp(month,"jun")==0 ||
                                        strcmp(month,"jul")==0 || strcmp(month,"aug")==0 ||
                                        strcmp(month,"sep")==0 || strcmp(month,"oct")==0 ||
                                        strcmp(month,"nov")==0 || strcmp(month,"dec")==0) {
                                        flag = 1;
                                }                                 
                                else printf("\tInvalid Month number or name! 1-12, Jan-Dec or January-December allowed only\n");
                                    
                            } while(flag==0);
                
                            printf("Year of Exam: ");
                            scanf("%d",&examYear);
                            printf("Total Subject in Exam: ");
                            scanf("%d",&totalSub);
                            printf("\nEnter Name of Each Subject\n");
                            for(i=0; i<totalSub; i++) {
                                printf("Subject %d : ",i+1);
                                scanf("%s",&subjectName[i]);
                            }
                            fullMarks=totalSub*100;
                        } //Here code ended for 'fill exam details'

                        //Code for 'Upload Marksheet'
                        else if(ch1==2) {
                            if(totalSub !=0 ) {
                            do {
                                flag=0;
                                printf("\n\tEnter(0) to back");
                                printf("\n\tEnter roll number to upload marks: ");
                                scanf("%d",&rollno);                                    
                                for(i=0; i<=n; i++) {
                                    if(rollno == roll[i] || rollno==0) {
                                        flag = 1;
                                        break;
                                    }
                                } 
                                if(flag==1 && rollno!=0) {
                                    printf("\n\tStudent information to upload marks");
                                    printf("\n\tStudent's Name: %s",studentName[i]);
                                    printf("\n\tRoll no: %d",roll[i]);
                                    printf("\n\tEnter marks of each subject\n");
                                    for(i=0; i<n; i++) {
                                        if(rollno == roll[i]) {
                                            for(j=0; j<totalSub; j++) {
                                                printf("\tMarks of '%s': ",subjectName[j]);
                                                scanf("%d",&subjectMarks[i][j]);
                                            }


                                        }
                                    }
                                    //Calculate 'total marks' and 'average marks'
                                    for(i=0; i<n; i++) {
                                        if(rollno == roll[i]) {
                                            totalMarks[i]=0;
                                            for(j=0; j<totalSub; j++) {
                                                totalMarks[i]=totalMarks[i]+subjectMarks[i][j];
                                            }
                                            avgMarks[i]=totalMarks[i]/totalSub;
                                        }
                                    }
                                    printf("\n\tMarks has been successfully uploaded.\n");
                                } 
                                else if(flag==0) printf("\tRoll number not found! Try again.\n");                                   
                                
                            } while(flag!=1);
                            }
                            else printf("\nThere is no exam details found! Fill exam details first,then move to upload marks.\n");                                
                            
                        } //Here code ended for 'Upload Marksheet'
                        
                        //Code for 'download Marksheet'
                        else if(ch1==3) {
                            if(totalSub!=0) {
                            do {
                                flag=0;
                                printf("\n\tEnter(0) to back");
                                printf("\n\tEnter roll number to download Marksheet: ");
                                scanf("%d",&rollno);                            
                                for(i=0; i<=n; i++) {
                                    if(rollno == roll[i] || rollno==0) {
                                        flag = 1;
                                        break;
                                    }
                                }  
                                //Desplaying 'Student Marksheet'
                                if(flag==1 && rollno!=0) {
                                    printf("\n\n\tMaulana Azad National Urdu University");
                                    printf("\n\t\t Deparment of CS&IT");
                                    printf("\n\t   %s Examination %s-%d",examName,month,examYear);
                                    printf("\n\n Student Name: %s\t\t  Roll no: %d",studentName[i],roll[i]);
                                    printf("\n Father's Name: %s\t\t  Enroll no: %s",fatherName[i],enroll[i]);
                                    printf("\n Course: %s\t\t\t  FM : %d",course[i],fullMarks);
                                    printf("\n******************************************************");
                                    printf("\n   ===== Student Marsheet of %s Semester =====\n",sem);
                                    printf("\n  SL No  \tSUBJECT(S)/PAPER(S)\tMM\t OM");
                                    for(i=0; i<n; i++) {
                                        if(rollno==roll[i]) {
                                            for(j=0; j<totalSub; j++) {    
                                                printf("\n  %d.\t\t%s\t\t\t100\t %d",j+1,subjectName[j],subjectMarks[i][j]); 
                                            }
                                            printf("\n\nTotal Marks Obtained: %d\t   Percentage : %.2f%%",totalMarks[i],avgMarks[i]);
                                            printf("\nGrade: ");
                                            flag=0;
                                            for(j=0; j<totalSub; j++) {
                                                if(subjectMarks[i][j]<40) {
                                                    flag=1;
                                                    break;
                                                }
                                            }
                                            if(flag==1) printf("Fail");   

                                            else {
                                                if(avgMarks[i]>=40 && avgMarks[i]<60) printf("Second Class");
                                                else if (avgMarks[i]>=60 && avgMarks[i]<70) printf("First Class");
                                                else if(avgMarks[i]>=70) printf("Distinction");
                                            }

                                            printf("\t\t   Result : ");
                                            flag=0;
                                            for(j=0; j<totalSub; j++) {
                                                if(subjectMarks[i][j]<40) {
                                                    flag=1;
                                                    break;
                                                }
                                            }
                                            if(flag==1) printf("Fail");                                          
                                            
                                            else printf("Pass");                                              
                                            
                                        }
                                    }
                                    printf("\n******************************************************\n");
                                }
                                else if(flag==0) printf("\tRoll number not found! Try again.\n");                                   
                                
                            } while(flag!=1);
                            }
                            else  printf("\n\tMarksheet has not been uploaded. Please wait!");                               
                            
                        } //Here code end for 'download Marksheet'
                        
                        else if(ch1==4) printf(" ");                           
    
                        else printf("\t  Enter valid choice!\n");                           
                                             
                } while(ch1!=4);
                } 
                else printf("\nThere is no student added! Add student first,then move to Result.");                     
            } 
            else if(ch==6) printf(" ");
                
            else printf("\t  Enter valid choice\n");               
            
        } while(ch != 6); 
        }
        else  printf("\n\t====SORRY YOU HAVE ATTEMPED MORE TIMES====\n\t     Your account temporarily blocked.");          
        
        //Come out from the code 
        printf("\n\n\t\t  Bye Bye Bye\n\t    Thank you nextcoder_041.\n\n");
        return 0;
    }