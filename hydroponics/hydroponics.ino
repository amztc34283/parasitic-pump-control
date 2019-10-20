
enum states {OFF, ON};

/*
 * Initialize variabless, set starting state.
 */
static states state;
static int count;

void setup() {
    state = OFF;
    count = 0;

    
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

}


/*
 * Program logic. For now just switching between on and off states after every second.
 */
void loop() {

  delay(10); //Delay for 10 milliseconds per loop.

  switch(state){
    case ON:
      /*
       * Stay in the on state
       */
      if (count < 100){
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.print("we are currently ON\n");  
        count++;
      }

      
      /*
       * Change from on state.
       */
      else if(count >= 10){
        count = 0;
        state = OFF;
      }
      break;
      
    case OFF:
      /*
       * Stay in the off state
       */
      if (count < 100){
        digitalWrite(LED_BUILTIN, LOW);
        Serial.print("we are currently off\n");  
        count++;
      }

      
      /*
       * Change from on state.
       */
      else if(count >= 10){
        count = 0;
        state = ON;
      }
      break;
  }
  

}
