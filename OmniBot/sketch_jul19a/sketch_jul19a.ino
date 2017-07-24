/*
 * This is the code for a headless machine, it is only here to manage motors and sensors
 * 
 */
/*
#include "Vector.h"
#include "Point.h"

double Contrib[3] = {0, 0, 0};
double WheelPos[3] = {60 * 180, 120 * 180, 0 * 180};

double Dist_LinePoint(Line &line, Point &point)
{
  Line Perp(0, 0);
  Point Inter(0, 0);

  if(line.Coef != 0)
    Perp.Coef = -(1 / line.Coef);

  Perp.Const = point.Y - (point.X * Perp.Coef);
  double TempX;

  line.Coef *= 1000;
  line.Const *= 1000;
  Perp.Const *= 1000;
  Perp.Coef *= 1000;

  int deltaCoef = (int(line.Coef) - int(Perp.Coef)) ? (int(line.Coef) - int(Perp.Coef)) > 0 : 1;

  TempX = (int(line.Const) - int(Perp.Const)) / deltaCoef;

    
  line.Coef /= 1000;
  line.Const /= 1000;
  Perp.Const /= 1000;
  Perp.Coef /= 1000;

  TempX /= 1000;

  Inter.Y = Perp.Const;
  Inter.X = TempX;


  double Dist = std::sqrtf(std::powf((Inter.Y - point.Y), 2) + std::powf((Inter.X - point.X), 2)); 

  return Dist;
}

void CalcVects(Vector GlobalVector)
{
  for(int i = 0; i < 3; ++i)
  {
    Dist_LinePoint(Line(GlobalVector), Point(WheelPos[i]))
    Contrib[i] = TempVec.Val;
  }
}

*/

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
    Serial.println(Serial.read());
}

