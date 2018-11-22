#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QuickSortAlgorithm(char string[][20], int, int);
int HoarePartition(char string[][20], int, int);
int LomutoPartition(char array[][20], int, int);

int main(void){
    int coolKids, badKids = 0, index = 0;
    scanf("%d", &coolKids);

    char tmp, list[coolKids][20];
    while(index < coolKids){
        scanf(" %c %s", &tmp, list[index]);
        if (tmp == '-')
            badKids++;
        index++;
    }

    QuickSortAlgorithm(list, 0, coolKids-1);
    for (int index = 0; index < coolKids; index++)
		printf("%s\n", list[index]);

    printf("Se comportaram: %d | Nao se comportaram: %d\n", coolKids - badKids, badKids);
    return 0;
}

void QuickSortAlgorithm(char string[][20], int start, int end){
    if (start < end){
        int pi = LomutoPartition(string, start, end); /* pi is partitioning index, string[p] is now at right place */
        QuickSortAlgorithm(string, start, pi - 1);   /* Separately sort elements before partition and after partition */
        QuickSortAlgorithm(string, pi + 1, end);
    }
}

int LomutoPartition(char array[][20], int start, int end){ 
    char pivot[20];    
    strcpy(pivot, array[end]);
    int index = (start - 1);                     /* Index of smaller element */
  
    for (int element = start; element <= end-1; element++){ 
        if (strcmp(array[element], pivot) < 0){  /* If current element is smaller than or equal to pivot */ 
            index++;      
            char aux[20];                        /* increment index of smaller element */
            strcpy(aux, array[index]); 
            strcpy(array[index], array[element]);
            strcpy(array[element], aux);
        } 
    }
    char aux[20];
    strcpy(aux, array[index + 1]);
    strcpy(array[index + 1], array[end]);
    strcpy(array[end], aux);

    return (index + 1); 
}