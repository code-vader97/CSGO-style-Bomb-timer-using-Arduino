#include <LiquidCrystal.h>

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);  //initializing object LCD (RS = pin 10, E = pin 9, pins (5,4,3,2) are data pins)
int redLed = 12;  // red LED is connected to digital pin no. 12 of arduino.
int buzzer = 7;  //buzzer is connected to digital pin no. 7 of arduino.
int timer;  // variable for countdown timer.
char choice;  // variable for storing user Choice.


void setup() {
  LCD.begin(16,2);  //initializing 16x2 LCD display
  pinMode(redLed, OUTPUT);             
  Serial.begin(9600);
}

void loop() {
  LCD.clear();
  Serial.println("Plant the Bomb:");  //Printing message in Serial monitor
  Serial.println("press (y/n)\n");
  LCD.print("Plant the Bomb:"); LCD.setCursor(0,1); LCD.print("press (y/n)");  //Printing message in LCD display
  
  while (Serial.available() == 0);  // Waiting for user input 
  choice = Serial.read();  //assigning user input to charter variable choice

  //desision control Structure.
  if (choice == 'y'){
    Serial.println("Set Timer :\n");  //Printing message in Serial monitor
    LCD.clear();  //clear LCD display
    LCD.print("Set Timer:");   //Printing message in LCD display
    
    while (Serial.available() == 0 );  // Waiting for user input
    timer = Serial.parseInt();  //assigning user input to integer variable timer
    LCD.clear();  //clear LCD display
    LCD.print("!!Bomb Planted!!");  //Printing message in LCD display
    LCD.setCursor(0,1);  //setting cursor to next row
    LCD.print("Time Left:");  //Printing message in LCD display
    for (int i=timer ; i>0 ; i--){
      LCD.setCursor(10,1);
      LCD.print(i);  //Printing time
      LCD.print(" ");  //Overwriting garbage value with Space when digit shift from ten's place to one's place.
      digitalWrite(redLed, HIGH);  // red LED on.
      tone(buzzer, 5000, 100);  //buzzer on with 5000hz frequency for 100ms.
      delay(100);
      digitalWrite(redLed, LOW);  //red LED off.
      delay(900);
    }
    digitalWrite(redLed ,HIGH);  // red LED on.
    LCD.clear();
    LCD.print("Terriost Win!!"); //Printing message in LCD display
    delay(3000);
    digitalWrite(redLed, LOW);  // red LED on.
  }
  
  else if(choice == 'n'){
    LCD.clear();
    Serial.println("Counter Terriost Win."); 
    LCD.print("Counter Terriost"); LCD.setCursor(6,1); LCD.print("Win");  //Printing message in LCD display
    delay(3000);
  }
  else{
    LCD.clear();
    Serial.println("Wrong Choice.");
    LCD.print("Wrong Choice.");  //Printing message in LCD display
    delay(1000);
    
  }
}
