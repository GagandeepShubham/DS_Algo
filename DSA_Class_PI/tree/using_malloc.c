/**malloc : dynamically allocate for an int array of size 10
 * This program demonstrates the use of malloc function.
**/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr = (int *)malloc(10 * sizeof(int));
    if(ptr == NULL)
        printf("memory not available\n");
    else
    {
        for(int i = 0; i < 10; i++)
        {
            *(ptr + i) = i + 2; //assigning the value.
        }
        for(int i = 0; i < 10; i++)
        {
            printf("%d\n", ptr[i]);
        }
    }
    return 0;
}