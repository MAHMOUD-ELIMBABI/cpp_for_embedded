#ifndef _GPIO_AVR_H_
#define _GPIO_AVR_H_

extern "C"
{
extern void AVR_pinMode(int pinNum , int pinMode);
extern void AVR_digitalWrite(int pinNum , int pinMode);
extern int AVR_digitalRead(int pinNum);
}
#endif