
#include <Servo.h> //Only needed for connecting servos


int dist;
int strength;
int check;
int uart[9];
int i;
int LED1 = 13;
const int HEADER=0x59;

int pos = 0;  
int PIN = 8;
Servo test;

void setup ()
{
  Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(LED1, OUTPUT);

  test.attach(PIN);
  test.write(pos);
}

byte rx_byte = 0; 

void loop()
{
  if(Serial3.available())
  {
    if(Serial3.read()==HEADER)
    {
      uart[0]=HEADER;
      Serial3.read()==HEADER;
      
        uart[1]=HEADER;
        for(i=2;i<9;i++)
        {
          uart[i]=Serial3.read();
        }
        check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
        
          dist=uart[2]+uart[3]*256;
          strength=uart[4]+uart[5]*256;
          if(dist<1000&&dist>-1000){          //This IF statement should throw out most weird values. (Only counts values between -1000 and 1000)
          Serial.print("Distance=");
          Serial.print(dist);
          Serial.print('\t');
          Serial.print("Strength=");
          Serial.print(strength);
          Serial.print('\n');
          delay(100);
            
         // if (dist<25){
         // digitalWrite(LED1, HIGH);        // To test on a LED
         // pos = pos + 5;
         // if (pos>=360){
           // pos = 0;
        //  }
        
          // test.write(pos);                // To test on a servo plugged into port 8
          //}
         // else {
         //   digitalWrite(LED1, LOW);
         // }
         
          }
          }
          else{;}
       
      //}
    }
  }
