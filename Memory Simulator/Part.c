#include <stdio.h>
#include <string.h>
#include "Part.h"

Part * find_longest(Part *parts, int num_of_parts) {
    // Complete this function
    return NULL;
}

void read_parts(Part parts[], int *num_of_parts) {
    FILE *fp;
    fp = fopen("in_data.txt", "r");
    char buff[255];
    long l = 0;
    double d = 0;
    int i = 0;
    while (1) {
        if (fscanf(fp, "%s %lu %lf", buff, &l, &d) == EOF) {
            break;
        }
        else {
            strcpy(parts[i].name, buff);
            parts[i].number = l;
            parts[i].cost = d;
        }
        i++;
    }
    fclose(fp);
    *num_of_parts = i;
    return;
}
