#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];
    int i = 0;
    while (feof(fp) == 0){
        if(fscanf(fp, "%s %d\n", &students[i].name,&students[i].score)==2)
            i++;
    }  
    
    


    int max = 0;
    float avg = 0;

    for(int j = 0;j<i;j++){
        
        if(max < students[j].score)
            max = students[j].score;
        avg += students[j].score;
    }
    avg /= i;




    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);

    return 0;
}

