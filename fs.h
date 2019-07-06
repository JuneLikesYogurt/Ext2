// #include <sys/types.h>
#include <stdio.h>
#include <string.h>


#define SUPER_BEGIN 0    //超级块起始位置
#define INODE_BEGIN 1024  //i节点表起始位置
#define BLOCK_BEGIN 2048

#define SUPER_SIZE 1024 //超级块大小
#define INODE_SIZE 1024
#define BLOCK_SIZE 1024 

#define INODE_NUM 128  //inode表，inode数目
                        //默认8kb分配一个inode，1M分区对应128inode
#define BLOCK_NUM 1024 //块（磁盘块）数目

#define FILE_NAME_LEN 14 //文件名字长度值



/*---------数据结构 -----------*/
//超级块
typedef struct {
    /*  i节点位图，为1，表示被占用
        块位图，为1，表示磁盘块空闲 */

    int s_inode_map[BLOCK_NUM];  //i节点位图
                                    //有多少个块就会有多少个位图
    int s_block_map[BLOCK_NUM];  //磁盘块位图
    int s_used_blocks_count;  //已被使用块总数
    int s_used_inodes_count;  //已被使用节点总数
}SuperBlock;

//inode表
typedef struct {
    int i_mode;  //文件类型
    int i_size;   //文件大小
    int i_block[9];   //索引表，逻辑块，指向磁盘块
                        //简单文件系统，直接索引应该就ok了
                        //直接（0-6）、间接（7）、双重间接（8）逻辑块号
}Inode;

//文件目录项结构
typedef struct {
    int dir_inode;   //   i节点号
    char name[FILE_NAME_LEN];    //文件名
}DirEntry;



/* ----------全局变量？？？---------*/
extern FILE* fs;
extern SuperBlock super_block;
extern Inode inode;
extern DirEntry dir_entry;

extern int curr_inode_num;   //当前目录的inode编号
extern Inode curr_inode;    //当前目录的inode结构

static char block[BLOCK_NUM];  //数据块
static int curr_block_num;   //当前数据块区块号



/*------------函数 --------------*/
extern int init_fs();
extern int format();    //格式化


// 接口、表层函数
extern int sys_create();    //创建目录

