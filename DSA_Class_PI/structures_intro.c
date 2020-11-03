//This Program is the introduction of structures.
#include<stdio.h>
struct point
{
    int x;
    int y;
};

int main()
{
    struct point pt = {320, 200};
    printf("%d, %d", pt.x, pt.y);
}