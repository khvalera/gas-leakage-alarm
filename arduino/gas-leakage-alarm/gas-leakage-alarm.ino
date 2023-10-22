int sensor      = A0; //sensor
int led_green   = D1; //no leakage indication
int led_yellow1 = D2; //no leakage indication
int led_yellow2 = D5; //no leakage indication
int led_red     = D6; // leakage indication
int led_blue    = D7; // leakage indication
int sensor_value;
 
int sensor_limit_yellow1  = 300;
int sensor_limit_yellow2  = 400;
int sensor_limit_red      = 500;

/********************************************************************* */
// Читання даних із датчика
/********************************************************************* */
void get_sensor_value(){
   sensor_value = analogRead(sensor);
   Serial.print("Gas Level:");
   Serial.println(sensor_value);
}

/********************************************************************* */
// Очікування прогріву датчика
/********************************************************************* */
void warming_up(){
   for (int i=0; i <= 30; i++){
      digitalWrite(led_green, HIGH);
      delay(500);
      digitalWrite(led_green, LOW);
      delay(500);
      get_sensor_value();
   }  
}

void setup(){
   button_setup();
   pinMode(sensor, INPUT);
   pinMode(led_green, OUTPUT);
   pinMode(led_yellow1, OUTPUT);
   pinMode(led_yellow2, OUTPUT);
   pinMode(led_red, OUTPUT);
   pinMode(led_blue, OUTPUT);   
   digitalWrite(led_green, LOW);
   digitalWrite(led_yellow1, LOW); 
   digitalWrite(led_yellow2, LOW); 
   digitalWrite(led_red, LOW);
   digitalWrite(led_blue, LOW);
   Serial.begin(115200);
   warming_up();
}
 
void loop(){
   get_sensor_value();
   // Перевіряє, чи досягнуто порогового значення
  if (sensor_value < sensor_limit_yellow1){
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow1, LOW);    
      digitalWrite(led_yellow2, LOW); 
      digitalWrite(led_red, LOW);     
   } else if (sensor_value >= sensor_limit_yellow1 and sensor_value < sensor_limit_yellow2){
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow1, HIGH);
      digitalWrite(led_yellow2, LOW);      
      digitalWrite(led_red, LOW);       
   } else if (sensor_value >= sensor_limit_yellow2 and sensor_value < sensor_limit_red){
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow1, HIGH);
      digitalWrite(led_yellow2, HIGH);
      digitalWrite(led_red, LOW);       
   } else if (sensor_value >= sensor_limit_red){
      digitalWrite(led_green, HIGH);   
      digitalWrite(led_yellow1, HIGH);
      digitalWrite(led_yellow2, HIGH);            
      digitalWrite(led_red, HIGH);
      button_beep();
   } else {
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow1, LOW);     
      digitalWrite(led_red, LOW);
  }
  delay(200);
}
