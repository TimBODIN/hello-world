#define Sonic1 A0 
#define Sonic2 A1 
int d1; 
int d2; 
int distance = 50; 


int heron(int d1,int d2, int distance) 
{
  int p; 
  int aire; 
  p = (d1 + d2 + distance)/2; 
  aire = sqrt( p* (p-d1) * (p-d2) * (p-distance)); 
  return aire; 
}

int hauteur(int distance) 
{
  int h; 
  h = 2 * heron(d1, d2, distance) / distance; 
  return h; 
}

int pythagore(int d1) 
{
  int res;  
  res = sqrt( pow(d1,2)/pow(hauteur(distance),2)); 
  return res; 
}

long readUltrasonic1() 
{
  
  pinMode(Sonic1, OUTPUT); // identifier recepteur et emetteur et transformer en cm
  digitalWrite(Sonic1, LOW);
  delayMicroseconds(2);
  digitalWrite(Sonic1, HIGH);
  delayMicroseconds(5);
  digitalWrite(Sonic1, LOW);

  
  pinMode(Sonic1, INPUT);
  long duration = pulseIn(Sonic1, HIGH);

  
  return duration / 29 / 2;
}

long readUltrasonic2() 
{
  
  pinMode(Sonic2, OUTPUT);// pour deuxieme capteur
  digitalWrite(Sonic2, LOW);
  delayMicroseconds(2);
  digitalWrite(Sonic2, HIGH);
  delayMicroseconds(5);
  digitalWrite(Sonic2, LOW);

  
  pinMode(Sonic2, INPUT);
  long duration = pulseIn(Sonic2, HIGH);

  
  return duration / 29 / 2;
}

void setup()   
{
  d1=0;
  d2=0;
  Serial.begin(9600); 
}

void loop()  
{  
    
    
    d1 = readUltrasonic1();
    d2 = readUltrasonic2();
   
    Serial.println( heron(d1,d2,distance));
    Serial.print("y=");
    Serial.println(hauteur(distance));
    Serial.print("x=");
    Serial.println(pythagore(d1));
    delay(2000);
   
}
