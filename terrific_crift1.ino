const int res1 =A0;
const int res2 =A2;
const int gearmotor1 =9;
const int gearmotor2 =10;
const int switch1 = 2;
const int switch2 = 3;
int switch1read;
int switch2read;
int res1read;
int res2read;
char serial;
void setup()
{
  pinMode(res1, INPUT);
  pinMode(res2, INPUT);
  pinMode(switch1, INPUT);
  pinMode(switch1, INPUT);
  pinMode(gearmotor1, OUTPUT);
  pinMode(gearmotor2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  switch1read = digitalRead(switch1);
  switch2read = digitalRead(switch2);
  res1read = analogRead(res1);
  res2read = analogRead(res2);
  if(switch1read==HIGH)
    {
      analogWrite(gearmotor1,map(res1read,0,1023,0,255));
    }
  else if(switch1read==LOW)
    {
      analogWrite(gearmotor1,0);
    }
  if(switch2read==HIGH)
    {
      analogWrite(gearmotor2,map(res2read,0,1023,0,255));
    }
  else if(switch2read==LOW)
    {
      analogWrite(gearmotor2,0);
    }
  if(Serial.available()>0)
  {
    serial = Serial.read();
    if(serial=='R')
    {
    analogWrite(gearmotor1,map(res1read,0,1023,0,255));
    }
    else if(serial=='L')
    {
    analogWrite(gearmotor2,map(res2read,0,1023,0,255));
    }
    else if(serial=='S')
    {
    analogWrite(gearmotor1,0);
    analogWrite(gearmotor2,0);
    }  
  }
  
}