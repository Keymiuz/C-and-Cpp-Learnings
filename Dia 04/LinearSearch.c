#include <stdio.h>


struct Array {
    int A[10];
    int size;    
    int length;  
};

int LinearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}


void Display(struct Array arr) {
    printf("Elements of the array are: ");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%d\n", LinearSearch(arr, 2));

    Display(arr);

    return 0;
}
