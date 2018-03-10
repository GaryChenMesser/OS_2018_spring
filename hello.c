#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>

#define HELLO_IOCTL_PRINT    0x12345678

static int hello_open(struct inode* inode, struct file* file);
static
