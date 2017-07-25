/*
 * This is the code for a headless machine, it is only here to manage motors and sensors
 * 
 */

#include "Vector.h"
#include "Point.h"
#include "Line.h"

double Contrib[3] = {0, 0, 0};
Vector WheelPos[3];
Vector GlobalVec;

char Input[16];
int TurretAngle = 0;// Value = 1 / 1000

Vector GlobalVector;

double Dist_LinePoint(Line line, Point point)
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


  double Dist = sqrt(pow((Inter.Y - point.Y), 2) + pow((Inter.X - point.X), 2)); 

  return Dist;
}

void CalcVects()
{
  for(int i = 0; i < 3; ++i)
  {
    Contrib[i] = Dist_LinePoint(Line(GlobalVec), Point(WheelPos[i])); 
  }
}



int GetVal(int IndBeg, int IndEnd)
{
  char * string;

  for(int i = IndBeg; i < IndEnd; ++i)
  {
    string[i] = Input[i];  
  }

  return (int)string;
}

void ProcessInput()
{
  if(Input[0] == 'A' && Input[1] == 'D' && Input[2] == '=')
   GlobalVec.Angle = GetVal(3, 16);

  else if(Input[0] == 'V' && Input[1] == 'D' && Input[2] == '=')
    GlobalVec.Val = GetVal(3, 16);
}

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  static char input_line [16];
  static unsigned int input_pos = 0;

  while(Serial.available())
     Input [input_pos++] = Serial.read();

  ProcessInput(); 
}

