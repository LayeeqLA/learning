#include<stdio.h>

// assuming format 1RV15CS001

int main() {
    FILE* fp = fopen("OERegistration.txt", "r");
    if (fp == NULL) {
        printf("File open failed!\n");
        return -1;
    }

    unsigned int count = 0;
    unsigned int max_size = 13; 
    char line[max_size];

    printf("Mech USNs are listed below:\n");
    while (fgets(line, max_size, fp) != NULL) {
        if (line[5]=='M' && line[6]=='E') {
            count++;
            printf("%s", line);
        }
    }

    printf("\nTotal count is %u\n", count);
    fclose(fp);
    return 0;
}