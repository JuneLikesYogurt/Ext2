#include <sys/types.h>

typedef long off_t; //用于文件长度（大下坡）
#define NAME_LEN 14 //名字长度值
#define ROOT_INO 1 //根i节点

// 缓冲块头数据结构
// struct buffer_head{};   

//磁盘上的索引节点（i节点）数据结构
struct d_inode {
    //简单文件系统应该不需要这个功能
    // unsigned short i_mode;  //文件类型
    unsigned short i_uid;   //用户id（文件拥有着标识符）
    unsigned long i_size;   //文件大小
    unsigned long i_time;   //修改时间
    unsigned char i_gid;    //组id(文件拥有着所在的组)
    unsigned short i_zone[9];   //索引表，逻辑块
                                //直接（0-6）、间接（7）、双重间接（8）逻辑块号
};

// //内存i节点表
// //加快文件名在目录树中的搜索速度，一个系统一个，应该也不用？？
// struct m_inode {
// };

//文件结构（用于在文件句柄与i节点之间建立关系）
struct file {
    unsigned short f_mode;  //文件操作模式(RW位)
    unsigned short f_flags; //文件打开和控制的标志
    unsigned short f_count; //对应文件引用计数值
    struct m_inode * f_inode;   //只想对应i节点（内存i节点）
    off_t f_pos;    //文件位置(读写偏移值)
};

// //内存中磁盘超级块结构
// //要是不用内存部分，也不需要
// struct super_block {
//     unsigned short s_ninodes;   //节点数
//     unsigned short s_nzones;    //逻辑块数
//     unsigned short s_imap_blocks;   //i节点位图所占用的数据块数
// };

struct d_super_block {
    unsigned short s_ninodes;   //节点数
    unsigned short s_nzones;    //逻辑块数
    unsigned short s_imap_blocks;   //i节点位图所占用的数据块数

};


//文件目录项结构
struct dir_entry {
    unsigned short inode;   //  i节点号
    char name[NAME_LEN];    //文件名
};

// int init_fs(void);
