#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    int sum = 0;
    int num;
    char errorval[256];
    while (feof(fp)==0)
    {
        if(fscanf(fp,"%d\n",&num) != 0){
            sum += num;
        }else{
            fgets(errorval,sizeof(errorval),fp);
            fprintf(stderr,"invalid input %s",errorval);
        }    
    }
    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
