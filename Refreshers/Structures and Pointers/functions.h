#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char street[100];
    char city[10];
    int zip[10];
} Address;

typedef union {
    int national_id;
    char passport[20];
} IDInfo;

typedef enum {
    STATUS_ACTIVE,
    STATUS_INACTIVE,
    STATUS_SUSPENDED
} Status;

typedef struct node {
    int project_id;
    char name[100];
    struct node *next;
} Projects;

typedef struct {
    int id;
    char name[100];
    Date hire_date;
    Address address;
    IDInfo id_info;
    Status status;
    Projects *projects;
} Employee;

#endif