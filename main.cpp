#include "mbed.h" 
#include "TCS3200.h" 
TCS3200 color(p19, p18, p17, p16, p15); //Create a TCS3200 object  
// S0 S1 S2 S3 OUT 
//Class to control an RGB LED using three PWM pins 
class RGBLed 
{ 
public: 
 RGBLed(PinName redpin, PinName greenpin, PinName  
bluepin); 
 void write(float red,float green, float blue); 
private: 
 PwmOut _redpin; 
 PwmOut _greenpin; 
 PwmOut _bluepin; 
}; 
RGBLed::RGBLed (PinName redpin, PinName greenpin,  
PinName bluepin) 
 : _redpin(redpin), _greenpin(greenpin), _bluepin(bluepin) 
{ 
 //50Hz PWM clock default a bit too low, go to 2000Hz (less flicker) 
 _redpin.period(0.0005f); 
} 
void RGBLed::write(float red,float green, float blue) 
{ 
 _redpin = red; 
 _greenpin = green; 
 _bluepin = blue; 
} 
//class could be moved to include file 
//Setup RGB led using PWM pins and class 
RGBLed myRGBled(p23,p24,p25); //RGB PWM pins 
int main() 
{ 
 float red, green, blue; 
 float r,g,b; 
 //Set the scaling factor to 100% 
 color.SetMode(TCS3200::SCALE_100);  
 while(1) {  
     red = color.ReadRed(); 
        r=red/255; 
    green = color.ReadGreen(); 
        g=green/255; 
    blue = color.ReadBlue(); 
        b=blue/255; 
//clear = color.ReadClear(); 
    myRGBled.write(r,g,b);  
    ThisThread::sleep_for(1000ms); 
        } 
} 