#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];

    char str[512];
    while(feof(fp) == 0){
        fgets(str, sizeof(str),fp);
        if(strstr(str,target_str) != NULL)
            printf("%s",str);
    }

    
    fclose(fp);
}

