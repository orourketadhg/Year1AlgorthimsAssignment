/* Question4:
 * Algorithms Design & Problem Solving - Assignment: Implementing Question 1, 2 & 3 in C
 *
 * Question 1:
 *  1. Combine 4 lists of student records (Surnames) into one list
 *  2. Sort list by surname
 *
 *  Question 2:
 *  1. Search through the list of students and print the info of any Full-Time Students
 *
 *  Question 3:
 *  1. Enter a surname to be Searched
 *  2. Search the Students and print any info that meets the requirements
 *
 *  Author: Tadhg O'Rourke
 *  Date: 09/04/2018
 *  IDE: Clion 2017.3.3
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 42

//Structures
struct  Student_Rec {
    char First_Name[21];
    char surname[21];
    char course[10];

};

int BinarySearch(struct Student_Rec[], int);

int main() {

    //Variables
    int j;
    bool Found;
    char Search_Input[21];

    //Defined Structures
    //Student data
    struct Student_Rec DT265A[12] = {
            {"Tom",    "Turner",   "DT265A"},
            {"Alex",   "Man",      "DT265A"},
            {"Rob",    "Chalk",    "DT265A"},
            {"Randy",  "Chalk",    "DT265A"},
            {"Emma",   "Roberts",  "DT265A"},
            {"Emily",  "Williams", "DT265A"},
            {"Terry",  "Crews",    "DT265A"},
            {"Anna",   "Orourke",  "DT265A"},
            {"Sarah",  "Dean",     "DT265A"},
            {"Robert", "Smith",    "DT265A"},
            {"Sean",   "Smith",    "DT265A"},
            {"Connor", "Rogers",   "DT265A"},

    };//end main struct DT265A

    struct Student_Rec DT265B[10] = {
            {"Vlad",    "Impaler", "DT265B"},
            {"ERROR",   "Temp",    "DT265B"},
            {"Dick",    "Chaney",  "DT265B"},
            {"Dick",    "Tom",     "DT265B"},
            {"Clara",   "Davin",   "DT265B"},
            {"Alice",   "Rabbit",  "DT265B"},
            {"Megan",   "Smith",   "DT265B"},
            {"Shannon", "Blake",   "DT265B"},
            {"Maria",   "Brown",   "DT265B"},
            {"Tadhg",   "Orourke", "DT265B"}
    };//end main struct DT265B

    struct Student_Rec DT265C[14] = {
            {"Harry",    "Dick",     "DT265C"},
            {"Aaron",    "Edwards",  "DT265C"},
            {"Mike",     "Law",      "DT265C"},
            {"Micheal",  "Jackson",  "DT265C"},
            {"Lewis",    "Blind",    "DT265C"},
            {"Louis",    "Dick",     "DT265C"},
            {"Albert",   "Einstein", "DT265C"},
            {"Leonardo", "Davine",   "DT265C"},
            {"Leonardo", "Dario",    "DT265C"},
            {"Monte",    "Doa",      "DT265C"},
            {"Bart",     "Simpson",  "DT265C"},
            {"Lisa",     "Simpson",  "DT265C"},
            {"Alvin",    "Monk",     "DT265C"},
            {"Dia",      "Orourke",  "DT265C"}
    };//end main struct DT265C

    struct Student_Rec DT8900[6] = {
            {"Claire",   "Orourke", "DT8900"},
            {"John",     "Doe",     "DT8900"},
            {"Buffy",    "Slayer",  "DT8900"},
            {"Chandler", "Bing",    "DT8900"},
            {"John",     "Cent",    "DT8900"},
            {"Martin",   "Sheen",   "DT8900"}
    };//end main struct DT8900


    struct Student_Rec Students[42];
    struct Student_Rec Temp;

    //Question 1
    //Combine 4 lists to one list

    for (int i = 0; i < 12; ++i) {
        strcpy(Students[i].First_Name, DT265A[i].First_Name);
        strcpy(Students[i].surname, DT265A[i].surname);
        strcpy(Students[i].course, DT265A[i].course);
    }//end main for Combine DT265A

    //Reset overwrite int
    //reset student in structure to be added
    j = 0;

    for (int i = 12; i < 22; ++i) {
        strcpy(Students[i].First_Name, DT265B[j].First_Name);
        strcpy(Students[i].surname, DT265B[j].surname);
        strcpy(Students[i].course, DT265B[j++].course);
    }//end main for Combine DT265B

    //Reset overwrite int
    //reset student in structure to be added
    j = 0;

    for (int i = 22; i < 36; ++i) {
        strcpy(Students[i].First_Name, DT265C[j].First_Name);
        strcpy(Students[i].surname, DT265C[j].surname);
        strcpy(Students[i].course, DT265C[j++].course);
    }//end main for Combine DT265B

    //reset student in structure to be added
    j = 0;

    //end for add DT8900 to Combined Student array
    for (int i = 36; i < SIZE; ++i) {
        strcpy(Students[i].First_Name, DT8900[j].First_Name);
        strcpy(Students[i].surname, DT8900[j].surname);
        strcpy(Students[i].course, DT8900[j++].course);
    }//end main for Combine DT8900

    //Print sorted Students
    printf("Printing unsorted Student information: \n");
    for (int k = 0; k < SIZE; ++k) {
        printf("%s\n", Students[k].surname);
    }//end for print sorted structure array

    //Sort Students by surname
    //Binary insertion Sort
    for (int i = 0; i < SIZE; ++i) {

        //find the location for where the new element(i) should go in structure Array
        int k = BinarySearch(Students, i);
        Temp = Students[i];
        j = i;

        while (strcmp(Temp.surname, Students[j - 1].surname) < 0 && j > k) {
            Students[j] = Students[j - 1];
            j--;
        }//end while move i to correct position

        Students[j] = Temp;
    }//end for insertion sort add new element to be sorted

    printf("\nPrinting sorted Student information: \n");
    //Print sorted Students
    for (int k = 0; k < SIZE; ++k) {
        printf("%s\n", Students[k].surname);
    }//end for print sorted structure array




    //Question 2
    //Highlight all Full time students
    printf("\n\n");

    printf("\nAll Full-Time Students\n");

    for (int i = 0; i < SIZE; ++i) {
        if((strcmp(Students[i].course, "DT265B") == 0) || (strcmp(Students[i].course, "DT8900") == 0)){

            printf("%s, %s, %s \n", Students[i].First_Name, Students[i].surname, Students[i].course);

        }//end if found print info of full time student

    }//end for flag all Full-Time students

    printf("\n\n");



    //Question 3
    //Search for Student by Surname
    printf("Enter a surname to search for: ");

    scanf("%s", Search_Input);

    printf("\n");

    for (int i = 0; i < SIZE; ++i) {
        if(strcmp(Students[i].surname, Search_Input) == 0) {
            //print the info of found student
            printf("%s, %s, %s \n", Students[i].First_Name, Students[i].surname, Students[i].course);
            Found = 1;

        }//end if name found
        else if(i == SIZE && Found == 0) {
            printf("\n%s could not be found", Search_Input);

        }//end else not found

    }//end for loop to find Searched name


    getchar();
    getchar();

    return 0;


}//end main


//Implement BinarySeach(Student_Rec structure, key index), Loops through a combined structure, finds the location where the key location will fit in
//A[middle] > A[low] && A[middle] < A[high]
int BinarySearch(struct Student_Rec A[], int Key) {
    int low = 0;
    int high ;
    int middle;

    high = Key;

    while(low <= high) {
        middle = (low + high) / 2;
        if(strcmp(A[Key].surname, A[middle].surname) == 0) {
            return middle;

        }//end BinarySearch if order location found
        if(strcmp(A[Key].surname, A[middle].surname) < 0) {
            high = middle - 1;

        }//end BinarySearch if key location is to high
        if(strcmp(A[Key].surname, A[middle].surname) > 0) {
            low = middle + 1;

        }//end BinarySearch if key location is to low

    }//end BinarySearch while

}//end BinarySearch
