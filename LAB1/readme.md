## Lab 1 

1. `swap.c` Write a program in C to swap two numbers using pointer.
2. `structure.c` Write a C program to assign values to each members of the following structure. Pass the populated structure to a function using call-by address and print the value of each member of the structure.
```c
struct info {
    int roll_no;
    char name[50];
    float CGPA;
};
```
3. `extractbyte.c` Write a C program to extract a byte from an integer (user input) value and store them in character variables and print the content of those variables.

4. `disectpkt.c` Write a C program to enter a number and store the number across the following structure and print the content of each member of the structure. Then aggregate each member of the structure to form the original number.
```c
struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};
```
5. `lilbigendian.c` Write a C program to check whether the Host machine is Little Endian or Big Endian. Enter a number, print the content of each byte location and convert the endianess of the same.
