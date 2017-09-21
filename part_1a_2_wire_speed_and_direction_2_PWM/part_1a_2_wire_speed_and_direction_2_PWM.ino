
/* L298 DC Motor Drive Demos
 *  The L298 can drive 2 DC Motors, these demos only use one motor
 *  but can be duplicated on the remaining pins of the L298.
 *  SO for these demos, a 2 wire setup could be duplicated for 4 wires
 *  a 3 wire setup could be duplicated for 6 wires.
 *  That is to say At a minimum you need 2 wires per DC motor. (This will
 *  drive one motor)
 *  And at minimum 4 wires are needed for 2 DC motors.
 *  
 *  Part 1a - 2 Wire Direction Control Speed control using 2 PWM pins. 
 *  For this demo the Enable PINs are left jumpered.
 *  
 *  Copyright (C) 2017 LeRoy Miller
 *  
 *  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>

If you find this or any of my projects useful or enjoyable please support me.
Anything I do get goes to buy more parts and make more/better projects.
https://www.patreon.com/kd8bxp
https://ko-fi.com/lfmiller
    
 */

//Setup Motor Pins 

#define in1 3 //PWM pin.
#define in2 5 //PWM pin
// in1 and in2 are the pins on the L298 drive board, 
// 3 and 5 are PWM pins on the Arduino board.

int stallSpeed = 60; //These motors go very slow or not at all under a certain vaule. This is a PWM value and not a speed value
int maxSpeed = 255; //The Arduino boards max PWM is 255, this will make the motors appear to move at top speed.
int speed; //This is a changing PWM vaule. Speed is really the wrong term here, since we are talking PWM. But the effect is a change in motor speed.

void setup() {
  //set the pins for output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 //set PWM to Zero - this will keep the motor from moving.
 analogWrite(in1, 0);
 analogWrite(in2, 0);
}

void loop() {

  //set PWM to Zero - this will keep the motor from moving.
  analogWrite(in1, 0);
  analogWrite(in2, 0);

 for (speed = stallSpeed; speed<maxSpeed; speed++) {
  //Spin Motor in one direction with speed control
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
  delay(100); //let it up spin slowly
 }
 
  //Stop the motor
  analogWrite(in1, 0);
  analogWrite(in2, 0);

for (speed = stallSpeed; speed<maxSpeed; speed++) {
  //Spin Motor in the other direction with speed control
  digitalWrite(in1, LOW);
  analogWrite(in2, speed);
  delay(100); //let it up spin slowly
}
}
