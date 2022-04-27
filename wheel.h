// Developed by Saad Bin Khalid
// Contact : k200161@nu.edu.pk

#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
  const unsigned dir1;		 // direction pin#1
  const unsigned dir2;		 // direction pin#2
  const unsigned controlPin; // speed control pin

public:
  // constructor:
  Wheel(const unsigned &Dir1, const unsigned &Dir2, const unsigned &ControlPin)
  		: dir1(Dir1), dir2(Dir2), controlPin(ControlPin)
  {
    // setting pins on output mode
    pinMode(dir1, OUTPUT);
    pinMode(dir2, OUTPUT);
    pinMode(controlPin, OUTPUT);

    // initialy, the wheel is stopped
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
	
  // move the wheel in forward direction
  void forward(const unsigned& Speed)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(controlPin, Speed);
  }
	
  // move the wheel in backward direction
  void backward(const unsigned& Speed)
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(controlPin, Speed);
  }
  
  // stop the wheel
  void Stop()
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    analogWrite(controlPin, 0);
  }
};

#endif
