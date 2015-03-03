#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

struct file {
        char fileName[100];
        char permissions[12];
        char type[10];
        char date[10];
};

void main() {
        struct file MainFile;
        int blockSize, partitionSize, i, j, k;
        FILE *f[100], *g;
        printf("Enter the size of a block.\n");
        scanf("%d", &blockSize);
        printf("Enter the filename:\n");
        //MainFile.fileName = fgets();
        //gets(MainFile.fileName);
        scanf("%s", MainFile.fileName);
        mkdir(MainFile.fileName, 0777);
        /*for(i = 0; i < 100; i++) {
                //fopen here
        }*/
}
