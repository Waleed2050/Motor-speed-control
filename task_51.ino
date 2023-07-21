const int MOTOR = 6;
const int DIR = 4;
const int trig = 12 ;
const int echo = 13;
 long int t ;
 long int d ;
int OUT;
void setup()
{
  pinMode(MOTOR, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
Serial.begin(9600);
}
void loop()
{
  digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
    t = pulseIn (echo,HIGH);
    d = 0.0343*t/2;
  Serial.print(d);
  if (d<=199){ 
    OUT = map(d,0,199,255,0);
  Serial.println(OUT);
    analogWrite(MOTOR,OUT);
    digitalWrite(DIR,HIGH);}
  else{digitalWrite(DIR,LOW);}
}