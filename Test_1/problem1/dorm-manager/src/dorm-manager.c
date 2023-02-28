//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Test 1
// Problem 1
//
// dorm-manager.c
// dorm-manager
// 
// Function: Manage a list of students in the dormitory.
// 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_STUDENT_NUM 10
// Change input file's path here.
#define INPUT_FILEPATH "../test-case/inputs.txt"
/*-----------------------------------------------------------------------------*/

typedef struct {
  char firstName[MAX_NAME_SIZE];
  char lastName[MAX_NAME_SIZE];
  char dormName[MAX_NAME_SIZE];
  int roomNum;
} Student;
/*-----------------------------------------------------------------------------*/

int readStudentArray(Student students[MAX_STUDENT_NUM]);
int getNumStudentsInDorm(Student students[MAX_STUDENT_NUM], int numStudents, char *dormName); 
int getNumStudentsInRoom(Student students[MAX_STUDENT_NUM], int numStudents, int roomNum);
void displayStudents(Student students[MAX_STUDENT_NUM], int numStudents);
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");

  // Step 1 (a): Read data for 10 students from the input file.
  Student students[MAX_STUDENT_NUM];
  int numStudents; // The total number of students.
  numStudents = readStudentArray(students);
  // Display students' data.
  printf("Step 1: read data.\n");
  printf("----------------------------------------------------------\n");
  for (int i = 0; i < numStudents; i++) {
    printf("%s %s %s %d\n", students[i].firstName, students[i].lastName, students[i].dormName, students[i].roomNum);
  }
  printf("----------------------------------------------------------\n");
  printf("\n");

  // Step 2 (b): Count the number of students in a give dorm.
  int numStudentsInDorm;
  printf("Step 2: count student numbers in a dorm.\n");
  printf("----------------------------------------------------------\n");
  numStudentsInDorm = getNumStudentsInDorm(students, numStudents, "NorthHouse");
  printf("The number of students in %s is: %d\n", "NorthHouse", numStudentsInDorm);
  numStudentsInDorm = getNumStudentsInDorm(students, numStudents, "SouthHouse");
  printf("The number of students in %s is: %d\n", "SouthHouse", numStudentsInDorm);
  numStudentsInDorm = getNumStudentsInDorm(students, numStudents, "EastHouse");
  printf("The number of students in %s is: %d\n", "EastHouse", numStudentsInDorm);
  printf("----------------------------------------------------------\n");
  printf("\n");

  // Step 3 (c): Count the number of students in a give room in all dorms.
  int numStudentsInRoom;
  printf("Step 3: count student numbers in a room in all dorms.\n");
  printf("----------------------------------------------------------\n");
  numStudentsInRoom = getNumStudentsInRoom(students, numStudents, 1010);
  printf("The number of students in the room %d is: %d\n", 1010, numStudentsInRoom);
  numStudentsInRoom = getNumStudentsInRoom(students, numStudents, 1110);
  printf("The number of students in the room %d is: %d\n", 1110, numStudentsInRoom);
  numStudentsInRoom = getNumStudentsInRoom(students, numStudents, 1050);
  printf("The number of students in the room %d is: %d\n", 1050, numStudentsInRoom);
  numStudentsInRoom = getNumStudentsInRoom(students, numStudents, 1120);
  printf("The number of students in the room %d is: %d\n", 1120, numStudentsInRoom);
  printf("----------------------------------------------------------\n");
  printf("\n");

  // Step 4 (d): Display students' data in all dorms.
  printf("Step 4: display students' data in all dorms.\n");
  printf("----------------------------------------------------------\n");
  displayStudents(students, numStudents);
  printf("----------------------------------------------------------\n");

  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// readStudentArray() reads data from the input file to an array of Student structures.
// @Param:   students  -- the array to store all students' data.
// @Return:  The number of students in the array.
// @Require: none
// @Note:    none
int readStudentArray(Student students[MAX_STUDENT_NUM])
{
  if (students == NULL) return -1;

  // Basic variables.
  int numStudents;
  int studenti;   // The student iterator;
  char firstName[MAX_NAME_SIZE], lastName[MAX_NAME_SIZE], dormName[MAX_NAME_SIZE];
  int roomNum;

  // Open the input file stream.
  FILE *inputFile = fopen(INPUT_FILEPATH, "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error opening the input file.\n");
    exit(EXIT_FAILURE);
  }

  // Read the number of students.
  fscanf(inputFile, "%d", &numStudents);
  // Read students' data.
  for (studenti = 0; studenti < numStudents; studenti++) {
    fscanf(inputFile, "%s", firstName);
    fscanf(inputFile, "%s", lastName);
    fscanf(inputFile, "%s", dormName);
    fscanf(inputFile, "%d", &roomNum);
    strcpy(students[studenti].firstName, firstName);
    strcpy(students[studenti].lastName, lastName);
    strcpy(students[studenti].dormName, dormName);
    students[studenti].roomNum = roomNum;
  }

  // close the input file stream.
  fclose(inputFile);

  return numStudents;
}
/*-----------------------------------------------------------------------------*/

// getNumStudentsInDorm() counts the number of students in a given dorm.
// @Param:   students    -- array of all students to search.
// @Param:   numStudents -- the number of all students in the array.
// @Param:   dormName    -- the name of the dorm.
// @Return:  The number of students in the dorm.
// @Require: none
// @Note:    none
int getNumStudentsInDorm(Student students[MAX_STUDENT_NUM], int numStudents, char *dormName)
{
  if (students == NULL) return -1;

  // Basic variables.
  int numStudentInDorm = 0;
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].dormName, dormName) == 0) 
      numStudentInDorm++;
  }

  return numStudentInDorm;
}
/*-----------------------------------------------------------------------------*/

// getNumStudentsInDorm() counts the number of students in a given room in all dorms.
// @Param:   students    -- array of all students to search.
// @Param:   numStudents -- the number of all students in the array.
// @Param:   roomNum     -- room's number.
// @Return:  The number of students in the room in all dorms.
// @Require: none
// @Note:    none
int getNumStudentsInRoom(Student students[MAX_STUDENT_NUM], int numStudents, int roomNum)
{
  if (students == NULL) return -1;

  // Basic variables.
  int numStudentInDorm = 0;
  for (int i = 0; i < numStudents; i++) {
    if (students[i].roomNum == roomNum) 
      numStudentInDorm++;
  }

  return numStudentInDorm;
}
/*-----------------------------------------------------------------------------*/

// Display all the students' data.
// @Param:   students    -- the array of all the students.
// @Param:   numStudents -- the number of students in the array.
// @Return:  none
// @Require: none
// @Note:    none
void displayStudents(Student students[MAX_STUDENT_NUM], int numStudents)
{
  if (students == NULL) return;
  for (int i = 0; i < numStudents; i++) {
    printf("%s %s %s %d\n", students[i].firstName, students[i].lastName, students[i].dormName, students[i].roomNum);
  }
}
/*-----------------------------------------------------------------------------*/