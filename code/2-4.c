#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    int alpha[26] = {0};

    int c;
    while((c = fgetc(fp)) != EOF){
        if(c >= 97 && c<= 122)
            alpha[c-97]++;
    }
        

    for(int i = 0;i<26;i++)
        printf("%c: %d\n",(char) i+97,alpha[i]);
    fclose(fp);
    return 0;
}

