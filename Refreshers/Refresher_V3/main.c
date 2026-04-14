#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[20];
};

union Data {
    int i;
    float f;
};

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    // memcpy
    struct Student s1 = {1, "John"};
    struct Student s2;

    memcpy(&s2, &s1, sizeof(struct Student));

    // union
    union Data d;

    d.i = 10;
    printf("i = %d\n", d.i);

    d.f = 5.5;
    printf("f = %.2f\n", d.f);

    // enum
    enum Day today;

    today = TUESDAY;

    printf("Value Equivalent of Day: %d\n", today);

    // strcpy
    char src[] = "Hello\n";
    char dest[20];

    strcpy(dest, src);

    printf("%s", dest);



    return 0;

    return 0;
}