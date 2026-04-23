/*
=========================================================
SCENARIO: COMPANY ACCESS CARD SYSTEM
=========================================================

A small company uses an electronic access card system to
control employee entry into restricted rooms.

There are 8 employees represented by ID numbers:

0 - Alice
1 - Bob
2 - Carl
3 - Dana
4 - Ethan
5 - Fiona
6 - George
7 - Hannah

The company wants to manage access permissions for:

1. Server Room
2. Research Lab

Each room stores employee access using a SET where:
true  = employee has access
false = employee has no access

=========================================================
FUNCTION GUIDE
=========================================================

initializeAccess(room)
- Sets all employee access values to false.
- Used when creating a new room access list.

grantAccess(room, employeeID)
- Gives access to a specific employee.
- Changes the employee's value to true.

revokeAccess(room, employeeID)
- Removes access from a specific employee.
- Changes the employee's value to false.

hasAccess(room, employeeID)
- Checks if an employee has access.
- Returns true if allowed, false otherwise.

getCombinedAccess(roomA, roomB, result)
- Stores employees who can access either room.
- Equivalent to UNION.

getSharedAccess(roomA, roomB, result)
- Stores employees who can access both rooms.
- Equivalent to INTERSECTION.

getExclusiveAccess(roomA, roomB, result)
- Stores employees who only have access to roomA
  and not roomB.
- Equivalent to DIFFERENCE (A - B).

displayAccessList(room)
- Displays all employee IDs who have access.

=========================================================
PROGRAM TASKS
=========================================================

1. Add employees with Server Room access:
   {0, 2, 4, 6}

2. Add employees with Research Lab access:
   {1, 2, 3, 6, 7}

3. Check access of specific employees.

4. Remove employee 6 because of resignation.

5. Show:
   - Employees with access to either room
   - Employees with access to both rooms
   - Employees with only Server Room access

=========================================================
*/