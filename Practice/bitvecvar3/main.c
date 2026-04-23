#include <stdio.h>
#include "functions.h"

int main() {
    AccessRoom serverRoom, researchLab;
    AccessRoom allAccess, sharedAccess, serverOnly;

    /* Initialize rooms */
    initializeAccess(serverRoom);
    initializeAccess(researchLab);
    initializeAccess(allAccess);
    initializeAccess(sharedAccess);
    initializeAccess(serverOnly);

    /* Grant Server Room Access: 0,2,4,6 */
    grantAccess(serverRoom, 0);
    grantAccess(serverRoom, 2);
    grantAccess(serverRoom, 4);
    grantAccess(serverRoom, 6);

    /* Grant Research Lab Access: 1,2,3,6,7 */
    grantAccess(researchLab, 1);
    grantAccess(researchLab, 2);
    grantAccess(researchLab, 3);
    grantAccess(researchLab, 6);
    grantAccess(researchLab, 7);

    /* Display current access */
    printf("Server Room Access: ");
    displayAccessList(serverRoom);

    printf("Research Lab Access: ");
    displayAccessList(researchLab);

    /* Check employee access */
    printf("\nChecking Access:\n");

    if (hasAccess(serverRoom, 4))
        printf("Employee 4 has Server Room access.\n");
    else
        printf("Employee 4 does NOT have Server Room access.\n");

    if (hasAccess(researchLab, 5))
        printf("Employee 5 has Research Lab access.\n");
    else
        printf("Employee 5 does NOT have Research Lab access.\n");

    /* Employee 6 resigned */
    revokeAccess(serverRoom, 6);
    revokeAccess(researchLab, 6);

    printf("\nAfter removing Employee 6:\n");

    printf("Server Room Access: ");
    displayAccessList(serverRoom);

    printf("Research Lab Access: ");
    displayAccessList(researchLab);

    /* Union */
    getCombinedAccess(serverRoom, researchLab, allAccess);
    printf("\nEmployees with access to either room: ");
    displayAccessList(allAccess);

    /* Intersection */
    getSharedAccess(serverRoom, researchLab, sharedAccess);
    printf("Employees with access to both rooms: ");
    displayAccessList(sharedAccess);

    /* Difference */
    getExclusiveAccess(serverRoom, researchLab, serverOnly);
    printf("Employees with only Server Room access: ");
    displayAccessList(serverOnly);

    return 0;
}