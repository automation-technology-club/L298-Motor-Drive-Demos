
/* L298 DC Motor Drive Demos
 *  The L298 can drive 2 DC Motors, these demos only use one motor
 *  but can be duplicated on the remaining pins of the L298.
 *  SO for these demos, a 2 wire setup could be duplicated for 4 wires
 *  a 3 wire setup could be duplicated for 6 wires.
 *  That is to say At a minimum you need 2 wires per DC motor. (This will
 *  drive one motor)
 *  And at minimum 4 wires are needed for 2 DC motors.
 *  
 *  Part 4a - 3 Wire Direction Control & Speed Control Using Two PWM PINS 
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

#define enA 4 
#define in1 5 
#define in2 3

int stallSpeed = 60; //These motors go very slow or not at all under a certain vaule. This is a PWM value and not a speed value
int maxSpeed = 255; //The Arduino boards max PWM is 255, this will make the motors appear to move at top speed.
int speed; //This is a changing PWM vaule. Speed is really the wrong term here, since we are talking PWM. But the effect is a change in motor speed.


void setup() {
  //set the pins for output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
 //set the pins low - this will keep the motor from moving.
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 analogWrite(enA, 0); //IF this is LOW motors will not move even if the other pins are high
}

void loop() {

  //Stop Motor using just the enable Pin
  //This is not the best way to do this since if we re-enable this pin we don't know what the state of the motors are.
  //This works well for this demo so we can see how the enable pin works.
  analogWrite(enA, 0);
delay(5000); //wait about 5 seconds between movements

 // Move one direction speeding up from stallSpeed to maxSpeed. (slow down)

for (speed = stallSpeed; speed<maxSpeed; speed++) {
  //Spin Motor in one direction
  
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
  digitalWrite(enA, HIGH); //if we put the enable at the end of the motor control, we can change the state of the in1 and in2 while the motor is stopped.
  delay(100); //let it spin up slowly
}

  //Stop the motor using just the enable Pin
  //This is not the best way to do this since if we re-enable this pin we don't know what the state of the motors are.
  //This works well for this demo so we can see how the enable pin works.
  analogWrite(enA, 0);
  delay(5000); //wait about 5 seconds between movements

  // move the opposite direction with speed going from maxSpeed to stallSpeed (slow down)

for (speed = stallSpeed; speed <maxSpeed; speed++) {
  //Spin Motor in the other direction
  
  digitalWrite(in1, LOW);
  analogWrite(in2, speed);
  digitalWrite(enA, HIGH); //if we put the enable at the end of the motor control, we can change the state of the in1 and in2 while the motor is stopped.
  delay(100); //let it spin down slowly
}
}
