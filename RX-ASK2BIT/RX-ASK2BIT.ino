  int sum = 0;
  int max = 0;
  int prev = 0;
  int check = false;
  int output = -1;
  int count = 0;
  
void setup() {
  Serial.begin(115200);                   // set serial baudrate
}

void loop() {

  int tmp = analogRead(A0);               // read signal from analog pin
  
  //Serial.println(tmp);
  
  if(tmp-prev>10 && check==false){        // check for rising signal
    max = 0;
    check = true;                         // change check status is true
  }
  
  if(tmp>max){                            // for change max value
    max=tmp;
  }
  
  if(max-tmp > 10){                       // check for falling signal
    if(check == true){
      if(128<max && max<384){             // if max between 128 and 384
        Serial.print("0 0 ");             
        count++;
      }        
      else if(384<max && max<640){        // if max between 384 and 640
        Serial.print("0 1 ");
        count++;
      }
      else if(640<max && max<896){        // if max between 640 and 896
        Serial.print("1 0 ");
        count++;
      }
      else if(896<max && max<1024){       // if max between 896 and 1024
        Serial.print("1 1 ");
        count++;
      }
      if(count == 5){
        Serial.println();
        count = 0;
      }
    }
    check = false;                        // change check status is false
  }

prev = tmp;                               // assign temp value to previous
}
