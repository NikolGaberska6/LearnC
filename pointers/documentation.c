//УКАЗАТЕЛИ
#include <stdio.h>
int main() {
    int var = 20;  /* декларация на реална променлива*/
    int *ip;      /* декларация на указател */
    ip = &var;   /* подаване на стойност на указателя адреса на променлива */

    /* адреса на променливата */
    printf("Address of the variable is: %x\n", &var);

    /* адреса запазен в указателя */
    printf("Address stored in ip variable is: %x\n", ip);

    /* достъп до стойността в указателя */
    printf("Value of *ip variable %d\n", *ip);

    /* достъп до стойността на променливата */
    printf("Value of the variable: %d\n", var);

    int *ptr = NULL;
    printf("The value of ptr is: %x\n", ptr);
    printf("The address of ptr is: %x\n", &ptr);

    int c, *pc;
    /* pc is address but c is not */
    // pc = c;  // Error

    /* &c is address but *pc is not */
    //*pc = &c;  // Error

    /* both &c and pc are addresses */
    //pc = &c;  // Not an error

    /* both c and *pc are values */
    //pc = c;  // Not an error

    //🧠 Най-важното правило:
    //pc и &c → адреси
    //c и *pc → стойности

    //Когато имаме *p=&c не получаваме грешка, защото е еквивалентно на
    //int *p:
    //p = &c;
}