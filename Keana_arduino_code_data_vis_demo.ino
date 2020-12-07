//Author: Keana Kief
//Program: ECE 441: Data Visualization Demo
//Purpose: Counts the number of button presses per minute and prints 
//  the value to the Serial stream. 
 
//pin 2 is assigned to the button
const int bPin = 2;
//pin 13 assinged to an led for visual verification that the button
//  was pressed
const int lPin = 13; 

//Initialize global variables: bState is the button's state, bCount is the number
//  of button presses counted this minute, pressed tracks if the button has been
//  released since the last button press was counted (this is done to prevent a 
//  long press from being counted as more than one press), time tracks the 
//  amount of time in milliseconds since the Arduino has been turned on.  
int bState = 0;
int bCount = 0;
int pressed = HIGH;  
unsigned long time = 0; 
 

void setup() {
  // Start the serial connection. 
  Serial.begin(9600); 

  //Initialize led pin as output. 
  pinMode(lPin, OUTPUT); 

  //Initialize button pin as input. 
  pinMode(bPin, INPUT_PULLUP); 

}

void loop() {
  //Flush the Serial stream
  Serial.flush(); 
  //Read the state of the button. If LOW the button is being pressed.
  //  If HIGH the button is not being pressed. 
  bState = digitalRead(bPin); 

  //Get the current time count since the Arduino has been powered. 
  time = millis();
  
  //If there is a new button press.
  if(bState == LOW && pressed == HIGH){
    //Set pressed to LOW, it will stay LOW until the button is released.    
    pressed = bState; 
    
    //Increment the button count by one. 
    bCount++;
       
    //Turn on the led (This is just visual verification that
    //  the button has been pressed). 
    digitalWrite(lPin, HIGH);  
  }

  //If the button is not being pressed.
  else{
    //Set pressed to HIGH, the button has been released or the button
    //  is not currently being pressed. 
    pressed = bState;
    //turn off led
    digitalWrite(lPin, LOW);   
  }

  //After a minute has passed. 
  if(time% 60000 == 0){
    //Print the number of button presses to the serial stream. 
    Serial.println(bCount, DEC); 
    //Reset the button count to 0. 
    bCount = 0; 
    } 
}
