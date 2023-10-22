int buzzer_pin=D8;
int frequency1=1500; //Specified in Hz
int frequency2=400;
int time_on=800; //specified in milliseconds
int time_off=500; //specified in millisecods

/********************************************************************* */
// Звуковий сигнал 
/********************************************************************* */
void button_setup() {
   pinMode(buzzer_pin, OUTPUT);// вывод
}

/********************************************************************* */
// Звуковий сигнал 
/********************************************************************* */
void button_beep(){ 
  delay(time_on);
  tone(buzzer_pin, frequency1);
  delay(time_on);
  tone(buzzer_pin, frequency2);
  //noTone(buzzer_pin);
  delay(time_off);
  noTone(buzzer_pin);
}