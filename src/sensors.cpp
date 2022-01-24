#include "main.h"
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;
extern double encdL, encdR, bearing, angle;

void Sensors(void * ignore){
  Motor FL (FLmotor);
  Motor BL (BLmotor);
  Motor FR (FRmotor);
  Motor BR (BRmotor);
  Imu imu (imuPort);
  while(true){
    if(!imu.is_calibrating()){
      encdL = FL.get_position();
      encdR = FR.get_position();
      bearing = imu.get_rotation();
      angle = halfPI - bearing * toRad;
    }
    delay(5);
  }
}