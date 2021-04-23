#include <Keypad.h>
#include <Stepper.h>

// define the symbols on the buttons of the keypad
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
String filmLen = "";
String newNum = "";
int currFrame = 1;

byte rowPins[4] = {14, 27, 26, 25}; // connect to the row pinouts of the keypad
byte colPins[4] = {13, 21, 22, 23};   // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

//Motor
const int stepsPerRevolution = 1300;
int in1 = 4;
int in2 = 0;
int in3 = 2;
int in4 = 15;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, in1, in3, in2, in4);  

void moveOneFrame(){
  
}

void setup() {
  Serial.begin(115200); // Initialize the serial port and set the baud rate to 115200
  Serial.println("ESP32 is ready!");  // Print the string "UNO is ready!"
  while (true){
    newNum = myKeypad.getKey();
    if (newNum == "*"){
      break;
    }else{
      filmLen += newNum;
    }
  }
  Serial.println(filmLen);
}

void loop() {
  String goToFrame = "";
  int framesToMove = 0;
  
  
  // Get the character input
  while (true){
    newNum = myKeypad.getKey();
    if (newNum == "*"){
      break;
    }else{
      goToFrame += newNum;
    }
  }
  Serial.println(filmLen);
  Serial.println(goToFrame);
  
  myStepper.setSpeed(15);
  if (goToFrame.toInt() <= filmLen.toInt()){
    Serial.println("move");
      
    framesToMove = goToFrame.toInt()-currFrame;

    myStepper.step(2*stepsPerRevolution*framesToMove);
    currFrame = goToFrame.toInt();      
   
  }
}
