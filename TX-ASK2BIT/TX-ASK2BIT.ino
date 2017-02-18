#include <Wire.h>                             // library for I2C
#include <Adafruit_MCP4725.h>                 // library for DAC

  Adafruit_MCP4725 dac;                       // create DAC object
  uint16_t input[4] = {0,0,0,0};              // for get input
  const uint16_t sine[4] = {2048,4095,2048,0}; //at 1700 Hz

void setup() {
  Serial.begin(115200);                       // for set serial baudrate
  dac.begin(0x62);                            // set DAC default ID
  Serial.flush();                             // for clear buffer serial
}

void loop() {
  
    if(Serial.available() > 0){
      
        int in = Serial.parseInt();             // get Dec from Serial
        for(int i=0 ; i<4 ; i++){               // 4 time of loop for a byte input
          input[i] = in & 3;                    // and bit b0000 0011 and save to array
          in >>= 2;                             // shift bit right 2 bit
        }
        //Serial.parseInt();
        //for(int x=0 ; x<10 ; x++)
        for(int k=3 ; k>=0 ; k--){              // 4 time loop for read data from LSB
            //Serial.println(input[k]);         // for debug program
            for(int i=0 ; i<4 ; i++){
               dac.setVoltage(sine[i]*(input[k]+1)/4, false);   // calculate amplitude of sinewave
            }
         }
      }   
      dac.setVoltage(0, false);                 // for don't sent

}
