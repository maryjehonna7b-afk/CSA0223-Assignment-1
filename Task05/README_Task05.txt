TASK 05 — HEADER FILES AND DEBUGGING

Files:
- main.c: calls the billing function and prints the bill.
- billing.c: contains the compute_bill() function.
- billing.h: contains constants, the function declaration, and include guards.

IMPORTANT:
Do not compile main.c by itself. The compute_bill() function is implemented in billing.c,
so both .c files must be compiled together.

Expected output:
Bill for 150 units: Rs 162.50

To compile with GCC from this folder:
    gcc main.c billing.c -o Task05.exe
Then run:
    Task05.exe

For a debug build:
    gcc -DDEBUG main.c billing.c -o Task05.exe

In Dev-C++, add BOTH main.c and billing.c to the same C project. Keep billing.h in the
same folder. Do not add billing.h as a source file; it is included by the two .c files.
