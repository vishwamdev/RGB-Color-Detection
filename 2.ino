#define s0 8         
#define s1 9 
#define s2 10 
#define  s3 11 

#define out 12 

#define LED_R 3    
#define  LED_G 5 
#define LED_B 6 

int Red=0, Blue=0, Green=0; 

void setup()   { 
      pinMode(LED_R,OUTPUT);      
      pinMode(LED_G,OUTPUT); 
      pinMode(LED_B,OUTPUT); 
      pinMode(s0,OUTPUT);     
      pinMode(s1,OUTPUT); 
      pinMode(s2,OUTPUT); 
      pinMode(s3,OUTPUT); 
      pinMode(out,INPUT); 

Serial.begin(9600);  

 digitalWrite(s0,HIGH);   
   digitalWrite(s1,HIGH);  
    
} 
 
void loop() 
{ 
  GetColors();                                   
  analogWrite(LED_R,map(Red,15,60,255,0));       
  analogWrite(LED_G,map(Green,30,55,255,0));     
  analogWrite(LED_B,map(Blue,13,45,255,0)); 
 
} 
 
void GetColors()   
{     
  digitalWrite(s2, LOW);                                            
  digitalWrite(s3, LOW);                                            
  Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);        
  delay(20);   
  digitalWrite(s3, HIGH);                                          
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW  : HIGH); 
  delay(20);   
  digitalWrite(s2, HIGH);   
  Green = pulseIn(out,  digitalRead(out) == HIGH ? LOW : HIGH); 
  delay(20);   
}