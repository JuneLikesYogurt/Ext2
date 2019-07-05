// #include <sys/types.h>
#include <stdio.h>
#include <string.h>

/*  目的是让别人明白，你这个变量占多大内存 
    代码规范*/
#define __u32 unsigned int 
#define __u16 unsigned short 
#define __s32 int 
#define __s16 short int 
#define __u8  unsigned char 
#define __s8  char

#define InodeCount  1024 //i节点总数
#define BlockCount  (80*1024)    //磁盘块总数
#define FileSystem  "file_system.txt"

#define SuperBegin 0    //超级块起始位置
#define InodeBegin sizeof(super_block)  //i节点表起始位置
#define BlockBegin (InodeBegin + InodeCount*sizeof(inode)) 


#define FILE_NAME_LEN 14 //名字长度值




//超级块
struct super_block {
    //索引节点总数和总块数定义为常量
    //索引节点大小、块大小，头文件define

    /*  i节点位图，为1，表示被占用
        块位图，为1，表示磁盘块空闲 */
    __u32 s_inode_map[InodeCount];  //i节点位图
    __u32 s_block_map[BlockCount];  //磁盘块位图

    __u32 s_used_blocks_count;  //已被使用块总数
    __u32 s_used_inodes_count;  //已被使用节点总数
};

//inode表
struct inode {
    __u16 i_mode;  //文件类型
    __u32 i_size;   //文件大小
    // __u32 i_time;   //修改时间,估计不一定有时间写这个
    __u16 i_block[9];   //索引表，逻辑块，指向磁盘块
                        //简单文件系统，直接索引应该就ok了
                        //直接（0-6）、间接（7）、双重间接（8）逻辑块号
};

//文件目录项结构
struct dir_entry {
    __u16 inode;   //   i节点号
    char name[FILE_NAME_LEN];    //文件名
};
/*  1. 文件名 获取节点号（文件目录项结构）
    2. 在i节点表中查找指向的磁盘块
 */


extern int init_fs();
extern int format();    //格式化
