#include<stdio.h>

// assuming format 1RV15CS001

int main() {
    // open the file
    FILE* fp = fopen("OERegistration.txt", "r");
    if (fp == NULL) {
        // THIS IS EDGE CASE: test if it works
        printf("File open failed!\n");
        return -1; // exit(1)
    }

    // just because we can use it and count will not negative here
    // VIVA: program is limited by size of int, if large dataset, might have to long or even bigger count holder
    unsigned int count = 0;

    // Size of a line
    // VIVA: why 13? USN is only 10 letters. what happens if we give 10 or 11? (note how data is in your file)
    // NOTE: since file read with \n
    // VIVA: if we want to declare this as a constant or global variable, what is the change?
    unsigned int max_size = 13; 

    // store string -> this is based on USN format on LINE3
    // VIVA: how is the string written in memory?
    // VIVA: string fns - how do we know a string has ended?
    // VIVA: dynamic memory allocation - replace below line using memory fns instead
    char line[max_size];

    printf("Mech USNs are listed below:\n");

    // read about fgets
    // iterate till NULL
    while (fgets(line, max_size, fp) != NULL) {
        // commented as not required by question, only to debug/verify
        // printf("Read USN: %s", line);
        
        // VIVA/debug: can you use 'line' for printing more than once? => NO
        // based on format -> Mech dept -> ME
        if (line[5]=='M' && line[6]=='E') {
            count++;
            printf("%s", line);
        }
    }

    // print total count
    printf("\nTotal count is %u\n", count); //formatter is important

    // close the file
    fclose(fp);

    return 0;
}