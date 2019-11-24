static int WAIT_TIME = 10;
static int HOLD_TIME = 5;
static int COUNTER = 0;
enum state {WAIT_STATE, HOLD_STATE};
static state CURRENT_STATE = WAIT_STATE;

//On Arduino Uno, the PWM pins are 3, 5, 6, 9, 10 and 11.
//The frequency of PWM signal on pins 5 and 6 will be about 980Hz and on other pins will be 490Hz.
int pwm_pin = 5;
void setup() {
  pinMode(pwm_pin, OUTPUT);
}
void loop() {

  delay(1000); //delay for one second
  COUNTER += 1;

  switch (CURRENT_STATE) {
    case WAIT_STATE: 
      if (COUNTER == WAIT_TIME) {
        CURRENT_STATE = HOLD_STATE;
        COUNTER = 0;
        analogWrite(pwm_pin, 255); //255 is full power
      }
      break;
    case HOLD_STATE:
      if (COUNTER == HOLD_TIME) {
        CURRENT_STATE = WAIT_STATE;
        COUNTER = 0;
        analogWrite(pwm_pin, 0); //0 is no power
      }
      break;
  }
}
  
/*
  1. How frequent is the pwm
  2. DC Motor
  3. PWM pin
  4
*/
