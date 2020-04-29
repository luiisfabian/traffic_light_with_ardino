const int EchoPin = 6;
const int TriggerPin = 7;

const int led_green = 2;
const int led_yelow = 3;
const int led_red = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(led_green,OUTPUT);  
   pinMode(led_yelow,OUTPUT);  
   pinMode(led_red,OUTPUT);  

}

void loop() {
  // put your main code here, to run repeatedly:

  long duration, distanceCm;
   digitalWrite(led_green, LOW);  
   digitalWrite(led_yelow, LOW);  
   digitalWrite(led_red, LOW);  
   digitalWrite(TriggerPin, LOW);  
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);

   duration = pulseIn(EchoPin, HIGH);  
   distanceCm = duration * 10 / 292/ 2;  
   Serial.println(distanceCm);
  
 if(distanceCm > 121){
  
      digitalWrite(led_green, HIGH);  
      digitalWrite(led_yelow, LOW);  
      digitalWrite(led_red, LOW);      
        Serial.println("LOS CARROS SIGUEN PORQUE PUEDEN SEGUIR");
    delay(1000);
    
  }else
  if(distanceCm < 120){
      digitalWrite(led_green, LOW);  
      digitalWrite(led_yelow, HIGH);  
       delay(1000);
      digitalWrite(led_red, HIGH); 
            digitalWrite(led_yelow, LOW);  

      Serial.println("LOS CARROS VAN A PERDER");
    delay(1000);
  }
    
  
  }
