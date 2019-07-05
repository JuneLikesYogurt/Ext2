/*供上层的文件名和目录操作函数使用
  文件系统加载、卸载
  根文件系统加载*/

void put_super();

int sys_mount();
int sys_unmount();

void mount_root();