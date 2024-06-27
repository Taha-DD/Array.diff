#include <stdlib.h>

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
    int *arr3 = (int *)malloc(n1 * sizeof(int));
    
    if (arr3 == NULL) {
        return NULL;
    }

    size_t c = 0;
    
    for ( size_t i = 0; i < n1; i++)
    {
        int counter = 0;
        
        for (size_t j = 0; j < n2; j++)
            if (arr1[i] == arr2[j])
                counter++;
                
        if (counter == 0)
        {
            arr3[c] = arr1[i];
            c++;
        }    
    }
    
    *z = c;
    return arr3;
}
int main ()
{
    int a[2] = {1, 2}, b[1] = {1}, z;
    int *arr3 = array_diff(a, 2, b, 1, &z);
    
    for (int i = 0; i < z; i++)
        printf("%d ", arr3[i]);
        
    free (arr3);
}
