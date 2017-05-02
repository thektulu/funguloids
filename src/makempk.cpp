# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "mpak.h"


bool extract(char *mpak_name, char *directory) {

    MPAK_FILE *mPakFile;
    int i;

    mPakFile = new MPAK_FILE();
    mPakFile->init();

    if(!mPakFile->open_mpk(MPAK_READ, mpak_name)) {
        printf("Cannot open mpak file: %s\n", mpak_name);
        return false;
    }

    for(i=0; i<mPakFile->num_files; i++){
        mPakFile->extract_file(mPakFile->files[i], directory);
    }

    mPakFile->close_mpk();
    return true;
}


bool add(char *mpak_name, char *files[], int first_file, int last_file) {
    MPAK_FILE *mPakFile;
    int i;

    mPakFile = new MPAK_FILE();
    mPakFile->init();

    if(!mPakFile->open_mpk(MPAK_WRITE, mpak_name)) {
        printf("Cannot open mpak file: %s\n", mpak_name);
        return false;
    }

    for(i=first_file; i<=last_file; i++){
        mPakFile->add_file(files[i]);
    }
    mPakFile->close_mpk();
    return true;
}


int main(int argc, char *argv[]) {
    char *operation;

    if (argc < 2) {
        printf("Not enough arguments\n");
        return 1;
    }

    operation = argv[1];

    if (strcmp(operation, "extract") == 0) {
        if (argc < 4) {
            printf("Not enough arguments\n");
            return 1;
        }
        if (!extract(argv[2], argv[3])) {
            printf("Extraction failed\n");
            return 1;
        }
    } else if (strcmp(operation, "add") == 0) {
        if (argc < 4) {
            printf("Not enough arguments\n");
            return 1;
        }
        add(argv[2], argv, 3, argc - 1);
    } else {
        printf("Unrecognized operation '%s'\n", operation);
        return 1;
    }

    return 0;
}