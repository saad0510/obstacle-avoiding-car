// Developed by Saad Bin Khalid
// Contact : k200161@nu.edu.pk

#ifndef CAR_H
#define CAR_H

#include "wheel.h"

// specify arduino nano pins :
const unsigned LeftMotorDir1 = 7;
const unsigned LeftMotorDir2 = 8;
const unsigned LeftMotorSpeed = 6;
const unsigned RightMotorDir1 = 9;
const unsigned RightMotorDir2 = 13;
const unsigned RightMotorSpeed = 10;

const unsigned LeftSensorTrig = 12;
const unsigned LeftSensorEcho = 11;
const unsigned MidSensorTrig = 5;
const unsigned MidSensorEcho = 4;
const unsigned RightSensorTrig = 3;
const unsigned RightSensorEcho = 2;

// wheel objects:
Wheel wheelLeft(LeftMotorDir1, LeftMotorDir2, LeftMotorSpeed);
Wheel wheelRight(RightMotorDir1, RightMotorDir2, RightMotorSpeed);

class Car
{
  // for conversion of distance to inches
  const double constant = (765. * 5280. * 12.) / (3600. * 1000000. * 2.);
  const unsigned Speed;

public:
  // constructor:
  Car(const unsigned& theSpeed) : Speed(theSpeed) {}
  
  // signal the given pin and return the distance from obstacle
  double Signal(const unsigned &trigPin, const unsigned& echoPin)
  {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // sending a signal:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // receiving the signal
    return pulseIn(echoPin, HIGH) * constant;
  }

  double SignalLeft()
  {
    return Signal(LeftSensorTrig, LeftSensorEcho);
  }
  
  double SignalRight()
  {
    return Signal(RightSensorTrig, RightSensorEcho);
  }
  
  double SignalMid()
  {
    return Signal(MidSensorTrig, MidSensorEcho);
  }
  
  // move the car in forward direction
  void forward()
  {
    wheelLeft.forward(Speed);
    wheelRight.forward(Speed);
  }
  
  // move the car in backward direction
  void back()
  {
    wheelRight.backward(Speed);
    wheelLeft.backward(Speed);
  }
  
  // move the car right
  void right()
  {
    wheelLeft.forward(Speed);
    wheelRight.Stop();
  }
  
  // move the car left
  void left()
  {
    wheelLeft.Stop();
    wheelRight.forward(Speed);
  }
  
  // stop the car
  void Stop()
  {
    wheelLeft.Stop();
    wheelRight.Stop();
  }
};

#endif
