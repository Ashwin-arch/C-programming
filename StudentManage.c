#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;
    do {
        printf("\n*** Student Record Management System ***\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    getchar(); // consume newline left by scanf
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove trailing newline
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll No: %d\n", s.rollNo);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n", s.marks);
        printf("-----------------------\n");
    }

    fclose(fp);
}

void searchStudent() {
    int rollNo;
    struct Student s;
    int found = 0;
    FILE *fp = fopen("students.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollNo == rollNo) {
            printf("Student found!\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", rollNo);
    }

    fclose(fp);
}

void updateStudent() {
    int rollNo;
    struct Student s;
    int found = 0;
    FILE *fp = fopen("students.dat", "rb+");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No to update: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollNo == rollNo) {
            printf("Enter new name: ");
            getchar(); // consume newline
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", rollNo);
    }

    fclose(fp);
}

void deleteStudent() {
    int rollNo;
    struct Student s;
    FILE *fp, *temp;

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error creating temp file!\n");
        fclose(fp);
        return;
    }

    printf("Enter Roll No to delete: ");
    scanf("%d", &rollNo);

    int found = 0;

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.rollNo != rollNo) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Student with Roll No %d not found.\n", rollNo);
    }
}
