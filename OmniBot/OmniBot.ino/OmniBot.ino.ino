
#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include "State.h"

#define UPDATE_STATE 0
#define GET_GOAL 1
#define SEND_DATA 2
#define DATA_ANALITIC 3
#define SHUTDOWN 4
#define MOVE 5
#define UPDATE_ROBOT 6

int Mot1[2] = {13, 12}, Mot2[2] = {11, 10}, Mot3[2] = {9, 8};

double Contrib[3] = {0, 0, 0};
Point WheelPos[3];
Vector GlobalVec;
int Speed = 0;

char Input [16];
int TurretAngle = 0;// Value = 1 / 1000
State RobotState;


void UpdateDir(Vector Dir)
{
  Dir.Angle -= RobotState.Yaw[0];
  Line TempLine(Dir);

  //GlobalVec = TempLine;
}

void CalcContrib()
{

  
  for(int i = 0; i < 3; ++i)
  {
    
    Contrib[i] = GlobalVec.Val * cos(((i * 120 + 90) - GlobalVec.Angle) * PI / 180);

    Serial.print("C ");
    Serial.print(i);
    Serial.print(":  ");
    Serial.print(Contrib[i]);
    Serial.print(",  ");
   // Serial.println(GlobalVec.Angle);
  }
}

void WriteMot1(int Freq)
{
  static int Cycle_Count;
  static double Time = millis();
  
  if(Time + 0.001 < millis())
  {
    Time = millis();
        
    if(Cycle_Count < abs(Freq))
    {
      if(Freq > 0)
      {
        analogWrite(Mot1[0], 400);
        digitalWrite(Mot1[1], 0);  
      }
      else
      {
        analogWrite(Mot1[1], 400);
        digitalWrite(Mot1[0], 0);  
      }
    }
    else
    {
      digitalWrite(Mot1[0], 0);
      digitalWrite(Mot1[1], 0);  
    }
    Cycle_Count++;

    if(Cycle_Count > 100)
    {
      Cycle_Count = 0;  
    }
  }
}


void WriteMot2(int Freq)
{
  static int Cycle_Count;
  static double Time = millis();
  
  if(Time + 0.001 < millis())
  {
    Time = millis();
        
    if(Cycle_Count < abs(Freq))
    {
      if(Freq > 0)
      {
        analogWrite(Mot2[0], 400);
        digitalWrite(Mot2[1], 0);  
      }
      else
      {
        analogWrite(Mot2[1], 400);
        digitalWrite(Mot2[0], 0);  
      }
    }
    else
    {
      digitalWrite(Mot2[0], 0);
      digitalWrite(Mot2[1], 0);  
    }
    Cycle_Count++;

    if(Cycle_Count > 100)
    {
      Cycle_Count = 0;  
    }
  }
}


void WriteMot3(int Freq)
{
  static int Cycle_Count;
  static double Time = millis();
  
  if(Time + 0.001 < millis())
  {
    Time = millis();
        
    if(Cycle_Count < abs(Freq))
    {
      if(Freq > 0)
      {
        analogWrite(Mot3[0], 400);
        digitalWrite(Mot3[1], 0);  
      }
      else
      {
        analogWrite(Mot3[1], 400);
        digitalWrite(Mot3[0], 0);  
      }
    }
    else
    {
      digitalWrite(Mot3[0], 0);
      digitalWrite(Mot3[1], 0);  
    }
    Cycle_Count++;

    if(Cycle_Count > 100)
    {
      Cycle_Count = 0;  
    }
  }
}

String Partial(int Begin, int End)
{
  String str(Input);
  str = str.substring(Begin, End);
  return str;
}

int GetVal(String string)
{
  return atoi(string.c_str());
}

void ProcessInput()
{
  if(Input[0] == 'D' && Input[1] == '=')
  {
    GlobalVec.Angle = GetVal(Partial(2, 9));
    GlobalVec.Val = GetVal(Partial(10, 16));
    
    Serial.print("Vec : ");
    Serial.print(Partial(0, 16));
    Serial.print(",  ");
    Serial.print(Partial(2, 9));
    Serial.print(",  ");
    Serial.println(Partial(9, 16));
  }
}

void Clear()
{
  for(int i = 0; i < 16; ++i)
  {
    Input[i] = "";  
  }  
}

void SendState()
{
  /*
  Serial.send("M1=");
  Serial.send(0);
  Serial.send("M2=");
  Serial.send(0);
  Serial.send("M3=");
  Serial.send(0);

  Serial.send("YW=");
  Serial.send(Yaw);
  Serial.send("PT");
  Serial.send(Pintch);
  Serial.send("RL");
  Serial.send(Roll);

  Serial.send("FI=");
  Serial.send(0);

  */
}

int GetInfo()
{
  static int incr = 0;
  if(Serial.available())
    Input[incr++] = Serial.read();

  if(incr == 16) 
  {
    incr = 0;
    ProcessInput();
    return 1;
    Clear();
  }
  return 0;
}

void UpdateState()
{
  
}

int DataAnalitic()
{
  return 0;  
}

void setup()
{
  Serial.begin(9600);


  pinMode(Mot1[0], OUTPUT);
  pinMode(Mot1[1], OUTPUT);

  pinMode(Mot2[0], OUTPUT);
  pinMode(Mot2[1], OUTPUT);

  pinMode(Mot3[0], OUTPUT);
  pinMode(Mot3[1], OUTPUT);
}

  
void loop() 
{
  static bool Data = 0;
  static int State_Machine = 0;
/*
int input_pos = 0;

if(Serial.available())
{
  while(Serial.available())
  {
    Input[input_pos++] = Serial.read();
  }
  
} 


delay(100);
 //Serial.println("");
  
  //Input = ;
  
  ProcessInput(); 
  CalcContrib();
  Move();
  Clear();
  */


  switch(State_Machine)
  {
    case UPDATE_STATE:  //read sensors
    {
      UpdateState();
      State_Machine = GET_GOAL;
      break; 
    }
    case GET_GOAL:  //get things to do from Pi
    {
      Data = GetInfo();
      State_Machine = DATA_ANALITIC;
      break;
    }
    case SEND_DATA: //send state or ask permissions
    {
      SendState();
      break;
    }
    case DATA_ANALITIC: //changes values of variables to react to external dangers
    {
      if(Data)State_Machine = MOVE;//DataAnalitic();
      else State_Machine = UPDATE_ROBOT;
      break;
    }
    case SHUTDOWN:
    {
      delay(500); //let Pi finish ShutDown
      //Maybe a servo to pull up the switch...
      delay(5000);
    }
    case MOVE:  //Sets Motor Values
    {
      CalcContrib();
      //while(1){};
      State_Machine = UPDATE_ROBOT;
      break;
    }
    case UPDATE_ROBOT:  //Move motor, move camera, etc ...
    {
      WriteMot1(Contrib[0]);
      WriteMot2(Contrib[1]);
      WriteMot3(Contrib[2]);
      //Serial.println("Update");
      State_Machine = UPDATE_STATE;
      break;
    }
  }
  /*
  if(Print)
    CalcContrib();
  Print = 0;*/
/*
  delay(400);
  GlobalVec.Val = 10;
  GlobalVec.Angle = 75;
  CalcContrib();
  while(1){};
*/
}

