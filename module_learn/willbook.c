// Below is the sample codes for module install and remove in linux

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static char* bookName = "will book";
static  int bookNum = 100;


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Will Sun");
MODULE_DESCRIPTION("A simple Hello world module");


static int __init book_init(void)
{
	printk(KERN_INFO "Will Book name is %s \n", bookName);
	printk(KERN_INFO "Will Book number is %d \n", bookNum);
	return 0;
}


static void __exit book_exit(void)
{
	printk(KERN_INFO "Will Book module exit.\n");
}


module_param(bookName, charp, S_IRUGO);
module_param(bookNum, int, S_IRUGO);


module_init(book_init);
module_exit(book_exit);
