// Developed by Saad Bin Khalid
// Contact : k200161@nu.edu.pk

#include "Car.h"

Car myCar(150);									  // car with speed 150 (range: 0-255)
double left, right, mid;    					  // to store readings of sensors
const double safe = 10, danger = 3, minSafe = 6;  //  distance in inches

// to make sure car stays in the safe zone
void adjust()
{
  if ( mid <= danger )	// middle sensor is in danger?
  {
    while (mid <= minSafe )
    {
      myCar.back();
      mid = myCar.SignalMid();
    }
  }
  
  if ( right <= danger || left <= danger) // left or right sensor is in danger?
  {
    while (right <= minSafe || left <= minSafe)
    {
      myCar.back();
      right = myCar.SignalRight();
      left = myCar.SignalLeft();
    }
  }
}

void setup()
{
  // nothing
}

void loop()
{
  // read sensors:
  left  = myCar.SignalLeft();
  right = myCar.SignalRight();
  mid   = myCar.SignalMid();

  // if there is nothing in the way
  if (left > safe && mid > safe && right > safe)
  {
    myCar.forward();
  }

  // if right detects something
  if (left > safe && mid > safe && right <= safe)
  {
    adjust();
    myCar.left();
  }

  // if mid detects something
  if (left > safe && mid <= safe && right > safe)
  {
    adjust();

    if (right < left)
      myCar.left();
    else
      myCar.right();
  }

  // if left is open only
  if (left > safe && mid <= safe && right <= safe)
  {
    adjust();
    myCar.left();
  }

  // if left detects something
  if (left <= safe && mid > safe && right > safe)
  {
    adjust();
    myCar.right();
  }

  // if mid is open only
  if (left <= safe && mid > safe && right <= safe)
  {
    adjust();

    if (right < left)
      myCar.left();
    else
      myCar.right();
  }

  // if right is open only
  if (left <= safe && mid <= safe && right > safe)
  {
    adjust();
    myCar.right();
  }

  // if the way is blocked completely 
  if (left <= safe && mid <= safe && right <= safe)
  {
    adjust();
  }
}
