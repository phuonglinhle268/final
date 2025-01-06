#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define FILENAME "students.txt"

//Logic ham
void printMenu(){
	printf("\t***Student Management System using C***\n");
	printf("CHOOSE YOUR ROLE\n");
	printf("========================\n");
	printf("[1] Admin.\n");
	printf("[2] Student.\n");
	printf("[3] Teacher.\n");
	printf("[0] Exit the program.\n");
	printf("========================\n");
	printf("ENTER THE CHOICE\n");
}

void printMenustudent(){
	printf("\n\t***Student Management System using C***\n");
	printf("STUDENT MENU\n");
	printf("========================\n");
	printf("[1] Add a new student.\n");
	printf("[2] Show all students.\n");
	printf("[3] Edit a student.\n");
	printf("[4] Search a student.\n");
	printf("[5] Delete a student.\n");
	printf("[6] Sort student list.\n"); 
	printf("[0] Exit the program.\n");
	printf("========================\n");
	printf("ENTER THE CHOICE\n");
}


struct Student students[50];


void showAll(struct Student students[50], int n){
	   	printf("|====|============|====================|====================|==============|\n");
	    printf("| ID |  No.Course |       Name         |      Email         |    Phone     |\n");
	    printf("|====|============|====================|====================|==============|\n");
	int i;
    for (i = 0; i < n; i++) {
        printf("| %-2s | %-10s | %-18s | %-18s | %-12d |\n",
            students[i].ID, students[i].numberOfCourse, students[i].Name,
		    students[i].Email, students[i].Phone);
    }
    	printf("|====|============|====================|====================|==============|\n");
    	saveFile(); 
}
void addStudent(struct Student students[], int *n) {
	printf("\n\t\t****Add a student****\n");
	printf("\n\t\tNhap thong tin sinh vien\n");
	if (*n >= 100) {
        printf("Danh sach da day.\n");
        return;
    }
    struct Student new_student;
    while (1) {
        int id = 0;
        printf("\n\tNhap ID: ");
        fflush(stdin);
        fgets(new_student.ID, sizeof(new_student.ID), stdin);
        new_student.ID[strcspn(new_student.ID, "\n")] = '\0';
        if (strlen(new_student.ID) == 0) {
            printf("\nError: ID cannot be empty.\n");
        } else if (strlen(new_student.ID) > 9) {
            printf("\nID khong hop le.\n");
        } else {
        	int i;
            for (i = 0; i < *n; i++) {
                if (strcmp(new_student.ID, students[i].ID) == 0) {
                    id = 1;
                    printSlowly("\n\tID bi trung.\n", 70);
                    printSlowly("\tHay nhap lai ID",70);
                    break;
                }
            }
            if (!id) {
                break;
            }
        }
    }
    while (1) {
        printf("\tNhap ma lop hoc: ");
        fflush(stdin);
        fgets(new_student.numberOfCourse, sizeof(new_student.numberOfCourse), stdin);
        new_student.numberOfCourse[strcspn(new_student.numberOfCourse, "\n")] = '\0';
        if (strlen(new_student.numberOfCourse) == 0) {
            printf("Khong duoc de trong.\n");
        } else if (strlen(new_student.numberOfCourse) > 10) {
            printf("Ma lop khong duoc qua 10 ki tu.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tNhap ten: ");
        fgets(new_student.Name, sizeof(new_student.Name), stdin);
        new_student.Name[strcspn(new_student.Name, "\n")] = '\0';
        if (strlen(new_student.Name) == 0) {
            printf("Khong duoc de trong ten.\n");
        } else if (strlen(new_student.Name) > 50) {
            printf("Khong duoc qua 50 ki tu.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tNhap email (khong nho): ");
        getchar();
        fgets(new_student.Email, sizeof(new_student.Email), stdin);
        new_student.Email[strcspn(new_student.Email, "\n")] = '\0';
        if (strlen(new_student.Email) == 0) {
            printf("Khong duoc de trong.\n");
        } else if (strlen(new_student.Email) > 14) { 
            printf("Khong duoc qua 14 ki tu.\n");
        } else {
            strcat(new_student.Email, "@gmail.com");
            break;
        }
    }
    while (1) {
        printf("\tNhap so dien thoai: ");
        fgets(new_student.Phone, sizeof(new_student.Phone), stdin);
        new_student.Phone[strcspn(new_student.Phone, "\n")] = '\0';
        if (strlen(new_student.Phone) == 0) {
            printf("Khong duoc de trong.\n");
        } else if (strlen(new_student.Phone) > 19) {
            printf("So dien thoai khong duoc qua 19 so.\n");
        } else if (strspn(new_student.Phone, "0123456789") != strlen(new_student.Phone)) {
            printf("Khong duoc chua ki tu dac biet.\n");
        } else {
            break;
        }
    }
    students[*n] = new_student;
    (*n)++;
    saveFile();
    printf("\n\tThem sinh vien thanh cong.\n");

} 
void editInformation() {
	printf("\n\t\t****Edit a student****\n");
    printf("\n\t\tNhap thong tin sinh vien\n");
    char ID[100];
    int i; 
    printf("\nNhap ID muon sua: ");
    scanf("%s", ID);

    int found = -1;
    int n = 3; 
    for (i = 0; i < n; i++) {
        if (strcmp(students[i].ID, ID) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Sinh vien voi ID %s khong tim thay.\n", ID);
        return;
    }

    struct Student *student = &students[found];
    printf("\nSua thong tin sinh vien %s\n", student-> Name);
    printf("Ma lop hoc: ", student->numberOfCourse);
    scanf("%d", &student->numberOfCourse);
    getchar();

    printf("Ten: ", student->Name);
    getchar(); 
    fgets(student->Name, sizeof(student->Name), stdin);
    student->Name[strcspn(student->Name, "\n")] = '\0';


    printf("Email: ", student->Email);
    scanf("%s", student->Email);

    printf("So dien thoai: ", student->Phone);
    scanf("%s", student->Phone);
    printf("Cap nhat thanh cong.\n");
    saveFile(); 
}
void sortStudent(struct Student students[100],int n){
	struct Student temp;
	printf("\n\t\t****Sort list of student****\n");
	int check = 0;
	char choice;
	do{
		printf("Chon cach muon sap xep : \n");
		printf("\n\t\t[1]. Tang dan\n");
		printf("\n\t\t[2]. Giam dan\n");
		printf("\n\tLua chon cua ban : ");
	    fflush(stdin);
		scanf("%c", &choice);
	}
	while(choice != '1' && choice != '2');
	check = (choice == '1'? 1 : 0);
	int a, b; 
	for(a = 0;a < n - 1; a++){
		for(b = a + 1; b < n; b++){
			if(check ? strcmp(students[a].Name, students[b].Name)>0:
			           strcmp(students[a].Name,students[b].Name)<0){
					   temp = students[a];
					   students[a] = students[b];
					   students[b] = temp;
			}
		}
	}
	printf("\nDanh sach sau khi sap xep: \n");
	printf("|====|============|====================|====================|==============|\n");
	printf("| ID |  No.Course |       Name         |      Email         |    Phone     |\n");
	printf("|====|============|====================|====================|==============|\n");
	int i;
    for(i = 0; i < n; i++){
       printf("| %-2s | %-10s | %-18s | %-18s | %-12d |\n",
            students[i].ID, students[i].numberOfCourse, students[i].Name,
		    students[i].Email, students[i].Phone);
    }
    printf("|====|============|====================|====================|==============|\n");
    saveFile(); 
    back_or_exit();
}
void deleteStudent(struct Student students[], int *n) {
	printf("\n\t\t****Delete a student****\n");
    printf("\n\t\tNhap thong tin sinh vien\n");
    printf("Nhap ID sinh vien muon xoa: ");
    char ID[20]; 
    fflush(stdin);  
    scanf("%s", ID); 
    int index = -1;
    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(students[i].ID, ID) == 0) {
            index = i; 
            break;
        }
    }
    if (index == -1) {
        printf("Sinh vien voi ID %s khong tim thay.\n", ID);
    } else {
        printf("|====|============|====================|====================|==============|\n");
        printf("| ID |  No.Course |       Name         |      Email         |    Phone     |\n");
        printf("|====|============|====================|====================|==============|\n");
        printf("| %-2s | %-10s | %-18s | %-18s | %-12d |\n",
            students[i].ID, students[i].numberOfCourse, students[i].Name,
            students[i].Email, students[i].Phone);
        printf("|====|============|====================|====================|==============|\n");
        char confirm[4];
        printf("Ban co muon xoa khong? (YES/NO): ");
        scanf("%s", &confirm);  

        if (strcmp(confirm, "YES") == 0) {
            for (i = index; i < *n - 1; i++) {
                students[i] = students[i + 1];
            }
            (*n)--; 
            printf("Xoa sinh vien thanh cong.\n");
        } else if (strcmp(confirm, "NO") == 0) {
            printf("Tu choi xoa.\n");
        } else {
            printf("Khong hop le. Khong the xoa.\n");
        }
    }
}
void searchStudent(struct Student students[], int n) {
	printf("\n\t\t****Search a student****\n");
    printf("\n\tNhap thong tin sinh vien\n");
    if (n <= 0) {
        printf("\n\tKhong tim thay.\n");
        return;
    }
    char search[50];
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';
    int check = 0;
    int i;
        for(i=0;i<n;i++){
        if (strstr(students[i].Name, search) != NULL) {
            if (check == 0) {
                printf("\n\tThong tin sinh vien tim thay.\n");
                printf("|====|============|====================|====================|==============|\n");
	            printf("| ID |  No.Course |       Name         |      Email         |    Phone     |\n");
	            printf("|====|============|====================|====================|==============|\n");
            }
            printf("| %-2s | %-10s | %-18s | %-18s | %-12d |\n",
            students[i].ID, students[i].numberOfCourse, students[i].Name,
		    students[i].Email, students[i].Phone);
            check = 1;
        }
    }
    if (!check) {
        printf("Thong tin khong tim thay.\n");
    } else {
          printf("|====|============|====================|====================|==============|\n");
    }
    saveFile(); 
}

void back_or_exit(){
	char choice;
	printf("\tGo back (b) or Exit (0) ?: ");
	getchar();
	scanf("%c", &choice);
	if (choice == '0'){
		printf("Exiting program\n");
		finish();
		exit(0);
	} else if(choice == 'b'){
		printMenustudent();
	} else {
		printf("Invalid choice");
	}
}
void finish(){
	printf("\t\n========== Thank You ==========\n");
    printf("\t\n==========See you soon=========\n"); 
}
void loadFile() {
	int n; 
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    while (fscanf(file, "%99[^,], %10[^,], %99[^,], %99[^,], %14[^\n]\n", 
           students[n].ID, students[n].numberOfCourse, students[n].Name, 
           students[n].Email, students[n].Phone) == 5) {
        n++;
    }
    fclose(file);
    printf("Loaded %d students from file.\n", n);
}

void saveFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    int i; 
    int n; 
    for (i = 0; i < n; i++) {
        fprintf(file, "%s, %s, %s, %s, %s\n", 
                students[i].ID, students[i].numberOfCourse, 
                students[i].Name, students[i].Email, 
                students[i].Phone);
    }
    fclose(file);
    printf("Saved %d students to file.\n", n);
}
void printSlowly(const char *mes, int delay){
	int i;
	for(i = 0; mes[i] != '\0'; i++){
		printf("%c",mes[i]);
		fflush(stdout);
		Sleep(delay);
	}
}



