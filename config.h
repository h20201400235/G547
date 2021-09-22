

#ifndef sayan_H
#define sayan_H

#include <linux/ioctl.h>


/*
 * The major device number. We can't rely on dynamic
 * registration any more, because ioctls need to know
 * it.
 */
 
 
#define MAJOR_NUM 77

/*
 * Set the message of the device driver
 */
 
 
#define IOCTL_PRESSURE _IOR(MAJOR_NUM, 0, char *)

#define IOCTL_MAG1 _IOR(MAJOR_NUM, 1, char *)
#define IOCTL_MAG2 _IOR(MAJOR_NUM, 2, char *)
#define IOCTL_MAG3 _IOR(MAJOR_NUM, 3, char *)

#define IOCTL_GYRO1 _IOR(MAJOR_NUM, 4, char *)
#define IOCTL_GYRO2 _IOR(MAJOR_NUM, 5, char *)
#define IOCTL_GYRO3 _IOR(MAJOR_NUM, 6, char *)

#define IOCTL_ACC1 _IOR(MAJOR_NUM, 7, char *)
#define IOCTL_ACC2 _IOR(MAJOR_NUM, 8, char *)
#define IOCTL_ACC3 _IOR(MAJOR_NUM, 9, char *)


/*
 * _IOR means that we're creating an ioctl command
 * number for passing information from a user process
 * to the kernel module.
 *
 * The first arguments, MAJOR_NUM, is the major device
 * number we're using.
 *
 * The second argument is the number of the command
 * (there could be several with different meanings).
 *
 * The third argument is the type we want to get from
 * the process to the kernel.
 */
 
 

/*
 * The name of the device file
 */
#define DEVICE_FILE_NAME "/dev/imu_char"

#endif

