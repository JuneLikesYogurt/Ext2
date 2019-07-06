# EXT2

## main

1. filesystem.txt  
   对一个文件进行操作,将其初始化、格式化，里面套一个文件系统，存储数据
2. 仅实现文件系统的功能，涉及到的内核、进程、驱动等等不考虑

## 功能模块

1. 创建文件 touch
2. 读文件 read
3. 写文件 write
4. 关闭文件 close
5. 删除文件 rm
6. 创建目录 mkdir
7. 打开目录 cd
8. 查看当前目录 ls
9. help()

## 底层函数

1. 初始化  
   init_fs()
2. 格式化
   format()

---

1. bitmap.c
   i节点位图、逻辑块位图--释放和占用
   <!-- 已经使用的节点总数??? -->

   ```C
   int free_block();
   int new_block();

   void free_inode();
   void new_inode();   //格式化可能用到???
   ```  

2. namei.c
   根据目录名or文件名找到对应i节点  
   目录的建立和删除  
   目录项的建立和删除

      ```C
      void find_entry();

      //创建一个目录
      int sys_mkdir();

      int empty_dir();
      int sys_rmdir();
      ```

## 高级函数

interface.c
    mkdir create read write等高级函数

## 超级块

1. 要mount??

---

1. 超级块
   记录整个文件系统的整体信息
   1. **超级块起始地址**
   2. *超级块大小* --应该是由其数据结构决定
      1. i节点位图  --i节点总数
      2. 磁盘块位图 --磁盘块总数
2. inode
   文件的属性、权限
   1. *inode整体大小??*
   2. **inode数目**
3. block 磁盘块
   数据块，实际记录文件的内容
   1. **每个块的大小**,要和内核态的对应
   2. 块的总数

<!-- 2. 块位图
    描述整个块组中哪些块已用哪些块空闲的 -->
<!-- 3. inode 位图 -->

---

1. inode table --- inode
   inode表
2. block bitmap
   区块对照表
   inode bitmap   inode对照表
3. 使用一个**目录项**的数据结构存储在数据块中。每个目录项存储了文件的文件名，inode号，文件类型，记录长度

---

1. 文件名 获取节点号（文件目录项结构）
2. 在i节点表中查找指向的磁盘块
