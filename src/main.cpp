#include <mbed.h>
#include "motor.h"
#define rep(i,n) for (int i = 0; i < (n) ; ++i) 
Serial pc(USBTX, USBRX, 115200);
InterruptIn UB(USER_BUTTON);

DigitalOut led(LED2, false);

PwmOut PWM_FR(PB_13);
DigitalOut PHASE_FR(PB_14);
Motor FR(PWM_FR, PHASE_FR, 100, true);
void test(void)
{
  led.write(true);
  FR.Brake();
  wait(1);
  FR.CW(30);
  wait(3);
  FR.Brake();
  wait(1);
  FR.CCW(80);
  wait(60);
}
int main()
{
  while(true)
  {
    UB.rise(test);
  }
}
