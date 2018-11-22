#include <stdio.h>
#include <stdlib.h>

void QuickStringSort(char **, int);
void swap(const char **, const char **);

int main(void){
    int coolKids;
    scanf("%d", &coolKids);

    char **string;
    while((scanf("%s", string[0]) == 1))

    QuickStringSort(string, sizeof(string) / sizeof(*string));

    return 0;
}

void QuickStringSort(char **string, int length){
    if (length <= 1)
        return;

    swap(string + ((unsigned int)rand() % length), string + length - 1);
    
    int pivot = 0;
    for (int index = 0; index < length - 1; ++index){
        if (strcmp(string[index], string[length - 1]) < 0)
            swap(string + index, string + pivot++);
    }

    swap(string + pivot, string + length - 1);
    QuickStringSort(string, pivot++);
    QuickStringSort(string + pivot, length - pivot);
}

/*** swap Function: uses call-by-reference to swap values ***/
void swap(const char **pastString, const char **thisString){
    const char *temp = *pastString;   /* Saving `x` value in `temp`                        */
    *pastString = *thisString;        /* Setting `x` value to `y` value                    */
    *thisString = temp;               /* Setting `iterato` value to `temp` value (old `x`) */
}