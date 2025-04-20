/* Code needs to be opened in Arduino IDE */
/* This code is for controlling a stepper motor using an Arduino. The motor will move to a specified angle based on the input from an analog sensor. */

const int Step_1 = 11;
const int Dir_1 = 10;
int time;
bool Logic = HIGH;
long Input_Control = analogRead(A0);
long angle;
long GoalAngle;

/**************************************************************************************************************************************************************************
3 Stages are needed for this to function as a GoTo. 
The first stage is the initiation where the stepper motors will 0 out on the rotational axis.
The second stage is the callibration the Motor will determine the extremeties of its movement axis (to be calibrated by user of telescope as function of Full-Step Degree)
The third stage is the operation stage, here the Motors will move to the determined angular positions from 0,0

The movement will be done by keeping record of the steps taken from calibration stage
*
*
*
***************************************************************************************************************************************************************************/

void setup() {
  pinMode(Step_1, OUTPUT);
  pinMode(Dir_1, OUTPUT);
  Serial.begin(9600);
  Logic = HIGH;
  GoalAngle = analogRead(A0);
  GoalAngle = map(GoalAngle, 0, 1023, -135, 135);
   
}

void loop() {
  Input_Control = analogRead(A0);
  Input_Control = map(Input_Control, 0, 1023, -135, 135);
  if((GoalAngle - Input_Control) > 0){
  digitalWrite(Dir_1, HIGH);
  digitalWrite(Step_1, HIGH);
  delay(10);
  digitalWrite(Step_1, LOW);
  }
  if((GoalAngle - Input_Control) < 0){
    digitalWrite(Dir_1, LOW);
  digitalWrite(Step_1, HIGH);
  delay(10);
  digitalWrite(Step_1, LOW);
  }
  

  


  

}
