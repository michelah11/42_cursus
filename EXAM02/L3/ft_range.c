#include <stdlib.h>
int *ft_range(int start, int end)
{
    int size;
    int *array;
    int i;
    if (start > end)
        size = start - end + 1;
    else 
        size  = end - start + 1;
    array = malloc(sizeof(int) * size);
    if (!array)
        return (0);
    i = 0;
    while(i < size)
    {
        if (start < end)
            array[i] = start + i;
        else 
            array[i] = start - i;
        i++;
    }
    return (array);
}

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end);

int main(void)
{
    int *range;
    int i;
    int start;
    int end;
    int size;

    start = 5;
    end = 10;
    range = ft_range(start, end);

    if (!range)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    // Calculate the size based on start and end
    size = (start > end) ? (start - end + 1) : (end - start + 1);

    // Print the range
    printf("Range from %d to %d: ", start, end);
    for (i = 0; i < size; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    // Free allocated memory
    free(range);

    // Test for a descending range
    start = 10;
    end = 5;
    range = ft_range(start, end);

    if (!range)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    // Calculate the size based on start and end
    size = (start > end) ? (start - end + 1) : (end - start + 1);

    // Print the range
    printf("Range from %d to %d: ", start, end);
    for (i = 0; i < size; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    // Free allocated memory
    free(range);

    return 0;
}
