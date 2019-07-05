#include <stdio.h>
#include <string.h>
#include "./fs.h"
#include "./operation_fs.h"

void help() {
    printf("touch\t     创建文件\n");
    printf("mkdir\t     创建文件夹\n");
    printf("open\t  打开文件\n");
    printf("write\t 写入文件\n");
    printf("read\t  读取文件\n");
    printf("close\t 关闭文件\n");
    printf("rm\t    删除文件\n");
    printf("cd\t    改变当前工作目录\n");
    printf("ls\t    显示当前文件夹内容\n");
    printf("q\t     退出\n");
}

int main(int argc,char *argv[]) {
    // init_fs();

    char cmd[1024];
    while(1) {
        printf("my_ext2>>");
        scanf("%s", cmd);
        if(!strcmp(cmd,"help"))
            help();
        else if(!strcmp(cmd,"touch")){}
        else if(!strcmp(cmd,"mkdir")){}
        else if(!strcmp(cmd,"open")){}
        else if(!strcmp(cmd,"write")){}
        else if(!strcmp(cmd,"read")){}
        else if(!strcmp(cmd,"close")){}
        else if(!strcmp(cmd,"rm")){}
        else if(!strcmp(cmd,"cd")){}
        else if(!strcmp(cmd,"ls")){}
        else if(!strcmp(cmd,"q")){
            break;
        }
    }
    return 0;
}