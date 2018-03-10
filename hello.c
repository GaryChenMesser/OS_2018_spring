#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>

#define HELLO_IOCTL_PRINT    0x12345678

static int hello_open(struct inode* inode, struct file* file);
static int hello_close(struct inode* inode, struct file* file);
static long hello_ioctl(struct file* file, unsigned int ioctl_num, unsigned long ioctl_param);

static struct file_operations hello_fops = {
  .owner = THIS_MODULE,
  .unlocked_ioctl = hello_ioctl,
  .open = hello_open,
  .release = hello_close
};

static struct miscdevice hello_dev = {
  .minor = MISC_DYNAMIC_MINOR,
  .name = "hello",
  .fops = &hello_fops
};
