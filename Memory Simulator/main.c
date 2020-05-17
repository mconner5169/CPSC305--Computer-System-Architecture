#include <stdio.h>

struct student_no_typedef {
    char name[12];
    int age;
    double gpa;
};

typedef struct {
    char name[12];
    int age;
    double gpa;
} student;

// Actual param of int[] is passed to formal param int *a 
void print_array(int *a) {
    for (int i = 0; i < 10; i++)
        printf("a[%d]: %d\n", i, a[i]);
}

// Formal param with array syntax instead of pointer syntax
void print_student1(student s[], int n) {
    for (int i = 0; i < n; i++)
        // Three ways to use s to access the structs members
        printf("s[%d]: %s. %d, %lf\n", i, s[i].name, (*(s+i)).age, s->gpa);
}
// Formal param with pointer syntax instead of array syntax
void print_student2(student *s, int n) {
    for (int i = 0; i < n; i++)
        // Three ways to use s to access the structs members
        printf("s[%d]: %s. %d, %lf\n", i, s[i].name, (*(s+i)).age, s->gpa);
}

void print_student(student s, int i) {
    printf("s%d: %s. %d, %lf\n", i, s.name, s.age, s.gpa);
}

int main() {
    int x = 5;
    int i = 0, j = 0;
    int *p, *q;
    
    // Uncomment next two lines to get an error message
    //double d = 1.0;
    //p = &d;

    p = &x;
    printf("x: %d, *p: %d, p: %p\n", x, *p, p);
    
    *p = 8; // assign 8 to x since p has the address of x
    q = p;  // q and p now point to x, *p and *q evaluate to 8
    printf("x: %d, *p: %d, p: %p, *q: %d, q: %p\n", x, *p, p, *q, q);
    
    j = *p + *q; // assign 16 to j, *p and *q reference x which is 8
    printf("j: %d, *p: %d, *q: %d\n", j, *p, *q);

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    p = arr; // arr is equivalent to &arr[0]
    printf("arr[2]: %d, *(p+2): %d\n", arr[2], *(p+2));
    
    // pass arr to formal parameter that is int *
    print_array(arr);
    
    student s1 = {"Gusty", 122, 13.2};
    student s2 = s1;
    student *s3 = &s1;
    print_student(s1, 1);
    print_student(s2, 2);
    print_student(*s3, 3);

    struct student_no_typedef snt = {"No Typedef", 333, 33.3};
    printf("snt: %s. %d, %lf\n", snt.name, snt.age, snt.gpa);
    
    // declare and initialize a student[] with 3 elements
    student sa[] = { {"Gusty", 22, 3.1}, {"Emily", 25, 3.6}, {"Coletta", 4, 4.0}};
    i = 0;
    // Iterate through sa using a student *
    // initialize s to sa, which is &sa[0]
    // terminal loop with s has an address beyond sa
    // increment s on each iteration - s points to next element
    for (student *s = sa; s < sa+3; s++) {
        printf("s[%d]: %s. %d, %lf\n", i, s[0].name, (*s).age, s->gpa);
        i++;
    }
    print_student1(sa, 3);
    print_student2(sa, 3);
    print_student1(s3, 1);
    print_student2(&s2, 1);
}
