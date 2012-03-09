#include <stdio.h>
#include <stdlib.h>

#define STUDENT_NAME_LENGTH 20

typedef struct {
	char *name;
	int number;
	int score;
} student;

void enterStudentsData(int numberOfStudents, student students[]);

void echoStudentData(char *message, student *pStudent);

void echoStudentsData(int numberOfStudents, student students[]);

student getStudentWithHighestNumber(int numberOfStudents, student students[]);

student getStudentWithSmallestScore(int numberOfStudents, student students[]);

student * getAllStudentsWithScoreGreaterThan(int numberOfStudents,
		student students[], int score);

int getNumberOfStudentsWithScoreGreaterThan(int numberOfStudents,
		student students[], int score);

int *getIndexesOfStudentsWithHigherScore(int numberOfStudents,
		student students[], int score);

int main(void) {
	int numberOfStudents;
	scanf("%d", &numberOfStudents);
	student students[numberOfStudents];
	// Init students
	enterStudentsData(numberOfStudents, students);
	// Echo students
	echoStudentsData(numberOfStudents, students);
	// Get student with highest number
	student studentWithHighestNumber = getStudentWithHighestNumber(
			numberOfStudents, students);
	echoStudentData("Student with highest number", &studentWithHighestNumber);
	// Get student with smallest score
	student studentWithSmallestScore = getStudentWithSmallestScore(
			numberOfStudents, students);
	echoStudentData("Student with smallest score", &studentWithSmallestScore);
	// Get all students with score greater than 8
	int score = 8;
	student *studentsWithScoreGreaterThan = getAllStudentsWithScoreGreaterThan(
			numberOfStudents, students, score);
	if (studentsWithScoreGreaterThan != NULL) {
		int numberOfStudentsWithScoreGreaterThan =
				getNumberOfStudentsWithScoreGreaterThan(numberOfStudents,
						students, score);
		echoStudentsData(numberOfStudentsWithScoreGreaterThan,
				studentsWithScoreGreaterThan);
	} else
		printf("No students found with score greater than %d\n", score);

	return EXIT_SUCCESS;
}

student getStudentWithHighestNumber(int numberOfStudents, student students[]) {
	int i, highestStudentNumber, highestStudentNumberIndex = EOF;
	for (i = 0; i < numberOfStudents; i++) {
		if (i == 0) {
			highestStudentNumber = students[i].number;
			highestStudentNumberIndex = i;
		}
		int studentNumber = students[i].number;
		if (studentNumber > highestStudentNumber) {
			highestStudentNumber = studentNumber;
			highestStudentNumberIndex = i;
		}
	}
	if (highestStudentNumberIndex == EOF) {
		printf("No students found for processing!");
		exit(EXIT_FAILURE);
	} else
		return students[highestStudentNumberIndex];
}

student getStudentWithSmallestScore(int numberOfStudents, student students[]) {
	student studentWithSmallestScore = students[0];
	int smallestScore = studentWithSmallestScore.score;
	int i;
	for (i = 1; i < numberOfStudents; i++) {
		student st = students[i];
		int stScore = st.score;
		if (smallestScore > stScore) {
			studentWithSmallestScore = st;
			smallestScore = stScore;
		}
	}

	return studentWithSmallestScore;
}

student * getAllStudentsWithScoreGreaterThan(int numberOfStudents,
		student students[], int score) {
	int numberOfStudentsWithScoreGreaterThan =
			getNumberOfStudentsWithScoreGreaterThan(numberOfStudents, students,
					score);
	printf("Number of students with higher score\t%d\n",
			numberOfStudentsWithScoreGreaterThan);
	if (numberOfStudentsWithScoreGreaterThan != 0) {
		student *studentsWithScoreGreaterThan = (student *) malloc(
				numberOfStudentsWithScoreGreaterThan * sizeof(student));
		int *indexesOfStudentsWithScoreGreaterThan =
				getIndexesOfStudentsWithHigherScore(numberOfStudents, students,
						score);
		int i;
		for (i = 0; i < numberOfStudentsWithScoreGreaterThan; i++) {
			int indexOfStudentWithHigherScore =
					indexesOfStudentsWithScoreGreaterThan[i];
			student studentWithHigherScore =
					students[indexOfStudentWithHigherScore];
			studentsWithScoreGreaterThan[i] = studentWithHigherScore;
		}

		return studentsWithScoreGreaterThan;
	} else
		return NULL;
}

int getNumberOfStudentsWithScoreGreaterThan(int numberOfStudents,
		student students[], int score) {
	int i, numberOfStudentsWithHigherScore = 0;
	for (i = 0; i < numberOfStudents; i++) {
		int studentScore = students[i].score;
		if (studentScore > score) {
			numberOfStudentsWithHigherScore++;
		}
	}
	return numberOfStudentsWithHigherScore;
}

int *getIndexesOfStudentsWithHigherScore(int numberOfStudents,
		student students[], int score) {
	int *indexesOfStudentsWithHigherScore = (int *) malloc(
			getNumberOfStudentsWithScoreGreaterThan(numberOfStudents, students,
					score) * sizeof(int));
	int i, j = 0;
	for (i = 0; i < numberOfStudents; i++) {
		int studentScore = students[i].score;
		if (studentScore > score) {
			indexesOfStudentsWithHigherScore[j] = i;
			j++;
		}
	}

	return indexesOfStudentsWithHigherScore;
}

void enterStudentsData(int numberOfStudents, student students[]) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		char *studentName = (char *) malloc(STUDENT_NAME_LENGTH * sizeof(char));
		scanf("%s", studentName);
		students[i].name = studentName;

		int studentNumber;
		scanf("%d", &studentNumber);
		students[i].number = studentNumber;

		int studentScore;
		scanf("%d", &studentScore);
		students[i].score = studentScore;
	}

	// fflush(stdin);
}

void echoStudentsData(int numberOfStudents, student students[]) {
	int i;
	for (i = 0; i < numberOfStudents; i++) {
		printf("Student name\t%s\n", students[i].name);
		printf("Student number\t%d\n", students[i].number);
		printf("Student score\t%d\n", students[i].score);
	}
}

void echoStudentData(char *message, student *pStudent) {
	printf("%s\n", message);
	printf("Student name\t%s\n", pStudent->name);
	printf("Student number\t%d\n", pStudent->number);
	printf("Student score\t%d\n", pStudent->score);
}
