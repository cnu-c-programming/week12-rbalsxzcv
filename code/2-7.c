#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt","r");
    char name[256];
    int num = 0;
    fscanf(fp,"%14s%s\n",&name,config_ptr->InputFileName);
    fscanf(fp,"%8s%d\n",&name,&config_ptr->Options);
    fscanf(fp,"%12s%s\n",&name,config_ptr->SectionName);
    fscanf(fp,"%8s%llx\n",&name,&config_ptr->Address);
    fclose(fp);
}
int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);        
    return 0;
}

