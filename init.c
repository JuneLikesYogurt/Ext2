//init format
#include "./fs.h"

//SEEK_SET 文件头

static void reload_super_block() {
    fseek(fs,SUPER_BEGIN,SEEK_SET); //将读写位置移动到超级块开始的地方
    fread(&super_block,SUPER_SIZE,1,fs);    //读取超级块
}

void reload_block(int block_num) {
    curr_block_num = block_num;
    fseek(fs,BLOCK_BEGIN,SEEK_SET);
    // fread();
}

// 加载节点信息，并加载第一个数据块内容
void reload_inode(int inode_num) {
    fseek(fs,INODE_BEGIN,SEEK_SET);
	fread(&inode,INODE_SIZE,1,fs);
    curr_block_num = inode.i_block[0];
    // reload_block(curr_block_num);
}



int init_fs() {
    fs = fopen("file_system.txt","w+");
    if(!fs)
        printf("打开失败\n");
    reload_super_block();

    /*	读根目录inode，读出后保存在内存inode（这里应该不是）结构中
		分配根目录的内存目录项
		（因为根目录没有父目录，直接在内存中构造）
		https://www.cnblogs.com/wuchanming/p/3864216.html
	*/
    curr_inode_num = 0;  //当前根目录的inode=0
    reload_inode(curr_inode_num);    //加载根节点目录信息
	printf("%x\n", inode.i_mode);   //%x 16进制输出
	printf("%d\n", inode.i_mode);   

    return 0;
}