#include <stdio.h>
#include <string.h>


int i, mob_no, count, role, reg, am, ap, ac, day;
char name[50], q, gm, gp, gc, c[50];

void assign() {
    
    if (strcmp(name, "Rahul Chaudhary") == 0) {
        am = 14; ap = 17; ac = 19;
        gm = 'B'; gp = 'A'; gc = 'A';
        strcpy(c, "Artificial Intelligence");
        role = 1;
    } else if (strcmp(name, "Srikanth Tripathi") == 0) {
        am = 17; ap = 15; ac = 20;
        gm = 'B'; gp = 'A'; gc = 'A';
        strcpy(c, "Cybersecurity");
        role = 1;
    } else if (strcmp(name, "Shreya Patil") == 0) {
        am = 20; ap = 19; ac = 17;
        gm = 'A'; gp = 'A'; gc = 'A';
        strcpy(c, "Quantum Computing");
        role = 1;
    } else if (strcmp(name, "Ayush Joshi") == 0) {
        am = 20; ap = 20; ac = 20;
        gm = 'A'; gp = 'A'; gc = 'A';
        strcpy(c, "Artificial Intelligence");
        role = 1;
    }else if(strcmp(name, "Nagendra Avasthi") == 0){
        role=2;
    }
}

void manag() {
    int fg;
    assign();
    printf("Your course is %s\nWould you like to edit it? (1 = yes, 2 = no): ", c);
    scanf("%d", &fg);
    if (fg == 1) {
        printf("Enter your new course: ");
        scanf(" %[^\n]", c);
        printf("Course updated to: %s\n", c);
    }
}

void sche() {
    printf("Enter the day code for the schedule (e.g., 1 for Monday, 3 for Wednesday): ");
    scanf("%d", &day);
    switch (day) {
        case 1:
            printf("9:00-10:00: Mathematics\n10:00-11:00: Physics\n11:00-12:00: Chemistry\n");
            break;
        case 2:
            printf("9:00-10:00: Physics\n10:00-11:00: Physics\n11:00-12:00: Mathematics\n");
            break;
        case 3:
            printf("9:00-10:00: Physics\n10:00-11:00: Physics\n11:00-12:00: Mathematics\n");
            break;
        case 4:
            printf("9:00-10:00: Mathematics\n10:00-11:00: Chemistry\n11:00-12:00: Physics\n");
            break;
        case 5:
            printf("9:00-10:00: Mathematics\n10:00-11:00: Physics\n11:00-12:00: Chemistry\n");
            break;
        default:
            printf("Invalid input\n");
    }
}

void inp() {
    printf("Enter your name: ");
    scanf(" %[^\n]", name);
    printf("Enter your mobile number (excluding country code): ");
    scanf("%d", &mob_no);
    printf("If you are a Teacher press 1, If you are a Student press 2: ");
    scanf("%d", &role);
}

void atten() {
    int t, f;
    assign(); 
    if (role == 2) { 
        printf("1. Edit attendance\n2. View attendance\n");
        scanf("%d", &t);
        switch (t) {
            case 1:
                printf("Enter student name to edit attendance: ");
                scanf(" %[^\n]", name);
                assign();
                printf("1. Mathematics: %d\n2. Physics: %d\n3. Chemistry: %d\n", am, ap, ac);
                printf("Enter the number of the subject to edit attendance: ");
                scanf("%d", &f);
                if (f == 1) {
                    printf("Enter new attendance for Mathematics: ");
                    scanf("%d", &am);
                } else if (f == 2) {
                    printf("Enter new attendance for Physics: ");
                    scanf("%d", &ap);
                } else if (f == 3) {
                    printf("Enter new attendance for Chemistry: ");
                    scanf("%d", &ac);
                } else {
                    printf("Invalid input\n");
                }
                break;
            case 2:
                printf("Enter student name to view attendance: ");
             scanf(" %[^\n]", name);
             assign();
             printf("1. Mathematics: %d\n2. Physics: %d\n3. Chemistry: %d\n", am, ap, ac);
             break;
            default:
                printf("Invalid input\n");
        }
    } else if (role == 1) {
        printf("Your Attendance:\nMathematics: %d\nPhysics: %d\nChemistry: %d\n", am, ap, ac);
    }
}

void grad() {
    int choice;
    assign(); 
    if (role == 2) { 
        printf("Enter the student name to view or edit grades: ");
        scanf(" %[^\n]", name);
        assign();
        printf("Grades for %s:\n1. Mathematics: %c\n2. Physics: %c\n3. Chemistry: %c\n", name, gm, gp, gc);
        printf("Enter the subject number to edit grade, or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter new grade for Mathematics: ");
            scanf(" %c", &gm);
        } else if (choice == 2) {
            printf("Enter new grade for Physics: ");
            scanf(" %c", &gp);
        } else if (choice == 3) {
            printf("Enter new grade for Chemistry: ");
            scanf(" %c", &gc);
        }
    } else if (role == 1) {
        printf("Your Grades:\nMathematics: %c\nPhysics: %c\nChemistry: %c\n", gm, gp, gc);
    }
}

int main() {
    int option;
    
    printf("Welcome to NeuraLearn\nPress 1 to login and 2 for new registration: ");
    scanf("%d", &option);

    if (option == 2) {
        inp(); 
    } else if (option == 1) {
        printf("Enter your name: ");
        scanf(" %[^\n]", name);
        assign(); 
        printf("Welcome, %s!\n", name);
    }

    
    if (role == 2) {  
        while (1) {
            printf("\n1. Check attendance\n2. View schedule\n3. View grades\n4. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &option);
            switch (option) {
                case 1: atten(); break;
                case 2: sche();break;
                case 3: grad();break;
                case 4: printf("Exiting...\n"); return 0;
                default: printf("Invalid input, try again.\n");
            }
        }
    } else if (role == 1) {  
        while (1) {
            printf("\n1. Check your attendance\n2. Manage your courses\n3. View your schedule\n4. View your grades\n5. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &option);
            switch (option) {
                case 1: atten(); break;
                case 2: manag(); break;
                case 3: sche(); break;
                case 4: grad(); break;
                case 5: printf("Exiting...\n"); return 0;
                default: printf("Invalid input, try again.\n");
            }
        }
    } else {
        printf("Role not set. Please register again.\n");
    }

    return 0;
}