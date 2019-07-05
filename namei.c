/*根据目录名or文件名找到对应i节点
  目录的建立和删除
  目录项的建立和删除 */


/*寻找一个与名字匹配的目录项
  返回一个含有找到目录项的高速缓冲块以及目录项本身 */
void find_entry();

//创建一个目录
int sys_mkdir();

int empty_dir();
int sys_rmdir();

/* 
int sys_unlink();
int sys_symlink(); //符号链接
int sys_link(); //硬链接
*/