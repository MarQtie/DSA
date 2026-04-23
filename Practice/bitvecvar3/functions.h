#include <stdio.h>
#include <stdbool.h>

#define ROOM_SIZE 8

typedef bool AccessRoom[ROOM_SIZE];

/* FUNCTION PROTOTYPES */
void initializeAccess(AccessRoom room);
void grantAccess(AccessRoom room, int employeeID);
void revokeAccess(AccessRoom room, int employeeID);
bool hasAccess(AccessRoom room, int employeeID);
void getCombinedAccess(AccessRoom roomA, AccessRoom roomB, AccessRoom result);
void getSharedAccess(AccessRoom roomA, AccessRoom roomB, AccessRoom result);
void getExclusiveAccess(AccessRoom roomA, AccessRoom roomB, AccessRoom result);
void displayAccessList(AccessRoom room);

void initializeAccess(AccessRoom room){
    for(int i = 0; i < ROOM_SIZE; i++){
        room[i] = false;
    }
}

void grantAccess(AccessRoom room, int employeeID){
    if(employeeID >= 0 && employeeID < ROOM_SIZE){
        room[employeeID] = true;
    }else {
        printf("Employee ID does not exist!");
    }
}

void revokeAccess(AccessRoom room, int employeeID){
    if(employeeID >= 0 && employeeID < ROOM_SIZE){
        room[employeeID] = false;
    }else {
        printf("Employee ID does not exist!");    
    }
}

bool hasAccess(AccessRoom room, int employeeID){
    if(employeeID >= 0 && employeeID < ROOM_SIZE){
        return room[employeeID] = false;
    }else {
        printf("Employee ID does not exist!");    
    }
}

void getCombinedAccess(AccessRoom roomA, AccessRoom roomB, AccessRoom result){
    for(int i = 0; i < ROOM_SIZE; i++){
        result[i] = roomA[i] || roomB[i];
    }
}

void getSharedAccess(AccessRoom roomA, AccessRoom roomB, AccessRoom result){
    for(int i = 0; i < ROOM_SIZE; i++){
        result[i] = roomA[i] && roomB[i];
    }
}

void getExclusiveAccess(AccessRoom roomA, AccessRoom roomB, AccessRoom result){
        for(int i = 0; i < ROOM_SIZE; i++){
        result[i] = roomA[i] && !roomB[i];
    }
}

void displayAccessList(AccessRoom room){
    printf("{");
    for(int i = 0; i < ROOM_SIZE; i++){
        if(room[i]){
            printf("%d ", i);
        }
    }
    printf("}\n");
}