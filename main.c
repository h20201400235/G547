#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/random.h>

#include "config.h"

#define SUCCESS 0
#define DEVICE_NAME "imu_char"




 
static dev_t first; // variable for device number
static struct cdev c_dev; // variable for the character device structure
static struct class *cls; // variable for the device class



static int open_device (struct inode *i, struct file *f)
{
	printk(KERN_INFO "Device--- open()\n");
	return 0;
}

static int close_device(struct inode *i, struct file *f)
{
	printk(KERN_INFO "Device--- close()\n");
	return 0;
}

static ssize_t read_device(struct file *f, char __user *buf, size_t len, loff_t *off)
{
 uint16_t val,i=0;
 char *addr;
 get_random_bytes(&val, sizeof(val));
 val=val%1023; // For 10 bit number we take num%(2^10), to range in between 0 t0 1023
 addr = (char *)&val;
 while(i<2)
 {
  printk(KERN_INFO "Copied Char:%d\n",*addr);
  put_user(*(addr++),buf++);
  i++;
 }
 put_user('\0',buf++);

	printk(KERN_INFO "Device--- read()\n");
	return 0;
}

static ssize_t write_device(struct file *f, const char __user *buf, size_t len, loff_t *off)
{ 
	
	printk(KERN_INFO "Device--- write()\n");
	return len;
}



 
long ioctl_device(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{

 int i;

 switch(ioctl_num)
 {
  case IOCTL_MAG1:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_MAG2:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_MAG3:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_ACC1:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_ACC2:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_ACC3:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_GYRO1:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_GYRO2:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_GYRO3:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

  case IOCTL_PRESSURE:
   i = read_device(file, (char *)ioctl_param,2,0);
   put_user('\0',(char *)ioctl_param+i);
   break;

 }

return SUCCESS;
}




static struct file_operations fops =
{
  .owner 	= THIS_MODULE,
  .open 	= open_device,
  .release 	= close_device,
  .unlocked_ioctl = ioctl_device,
  .read 	= read_device,
  .write 	= write_device
};
 

static int __init device_init(void) 
{
	printk(KERN_INFO "Hello device driver --- registered");
	
	// STEP 1 : reserve <major, minor>
	if (alloc_chrdev_region(&first, 0, 1, "imu_char") < 0)
	{
		return -1;
	}
	
	// STEP 2 : dynamically create device node in /dev directory
    if ((cls = class_create(THIS_MODULE, "chardrv")) == NULL)
	{
		unregister_chrdev_region(first, 1);
		return -1;
	}
    if (device_create(cls, NULL, first, NULL, "imu_char") == NULL)
	{
		class_destroy(cls);
		unregister_chrdev_region(first, 1);
		return -1;
	}
	
	// STEP 3 : Link fops and cdev to device node
    cdev_init(&c_dev, &fops);
    if (cdev_add(&c_dev, first, 1) == -1)
	{
		device_destroy(cls, first);
		class_destroy(cls);
		unregister_chrdev_region(first, 1);
		return -1;
	}
	return 0;
}
 
static void __exit device_exit(void) 
{
	cdev_del(&c_dev);
	device_destroy(cls, first);
	class_destroy(cls);
	unregister_chrdev_region(first, 1);
	printk(KERN_INFO "Bye device driver --- unregistered\n\n");
}
 
module_init(device_init);
module_exit(device_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("EEE G547");
MODULE_DESCRIPTION("Assignment 1");
