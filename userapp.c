#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>

#include "config.h"

int ioctl_gyro1(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_GYRO1,msg);
 return 0;
}

int ioctl_gyro2(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_GYRO2,msg);
 return 0;
}

int ioctl_gyro3(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_GYRO3,msg);
 return 0;
}

int ioctl_accel1(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_ACC1,msg);
 return 0;
}

int ioctl_accel2(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_ACC2,msg);
 return 0;
}

int ioctl_accel3(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_ACC3,msg);
 return 0;
}

int ioctl_pressure(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_PRESSURE,msg);
 return 0;
}

int ioctl_magnet1(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_MAG1,msg);
 return 0;
}

int ioctl_magnet2(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_MAG2,msg);
 return 0;
}

int ioctl_magnet3(int file_desc, char *msg)
{
 int ret_val;

 ret_val = ioctl(file_desc, IOCTL_MAG3,msg);
 return 0;
}

int main()
{
 int file_desc, ret_val;
 char *msg="From User space\n";
 char message_recieved[100];

 file_desc = open(DEVICE_FILE_NAME,0);

 if(file_desc<0)
 {
  printf("Device file not opened. Name:%s\n",DEVICE_FILE_NAME);
  exit(-1);
 }

 ioctl_gyro1(file_desc,message_recieved);
 printf("Gyro 1:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_gyro2(file_desc,message_recieved);
 printf("Gyro 2:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);
 
 ioctl_gyro3(file_desc,message_recieved);
 printf("Gyro 3:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_accel1(file_desc,message_recieved);
 printf("Accel 1:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_accel2(file_desc,message_recieved);
 printf("Accel 2:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_accel3(file_desc,message_recieved);
 printf("Accel 3:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_magnet1(file_desc,message_recieved);
 printf("Magnet 1:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_magnet2(file_desc,message_recieved);
 printf("Magnet 2:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_magnet3(file_desc,message_recieved);
 printf("Magnet 3:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 ioctl_pressure(file_desc,message_recieved);
 printf("Pressure:%X",message_recieved[0]);
 printf("%X\n",message_recieved[1]);

 close(file_desc);
 return 0;
}
