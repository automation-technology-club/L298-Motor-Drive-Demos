
/* L298 DC Motor Drive Demos
 *  The L298 can drive 2 DC Motors, these demos only use one motor
 *  but can be duplicated on the remaining pins of the L298.
 *  SO for these demos, a 2 wire setup could be duplicated for 4 wires
 *  a 3 wire setup could be duplicated for 6 wires.
 *  That is to say At a minimum you need 2 wires per DC motor. (This will
 *  drive one motor)
 *  And at minimum 4 wires are needed for 2 DC motors.
 *  
 *  Part 3 - 3 Wire Direction Control NO PWM. Enable 
 *  PIN is used.
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

#define enA 3 //We moved to a PWM pin for later demos
#define in1 4 
#define in2 5


void setup() {
  //set the pins for output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
 //set the pins low - this will keep the motor from moving.
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(enA, LOW); //IF this is LOW motors will not move even if the other pins are high
}

void loop() {

  //Stop Motor using just the enable Pin
  //This is not the best way to do this since if we re-enable this pin we don't know what the state of the motors are.
  //This works well for this demo so we can see how the enable pin works.
  digitalWrite(enA, LOW);
delay(5000); //wait about 5 seconds between movements
 
  //Spin Motor in one direction
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enA, HIGH); //if we put the enable at the end of the motor control, we can change the state of the in1 and in2 while the motor is stopped.
  delay(5000); //let it spin for about 5 seconds

  //Stop the motor using just the enable Pin
  //This is not the best way to do this since if we re-enable this pin we don't know what the state of the motors are.
  //This works well for this demo so we can see how the enable pin works.
  digitalWrite(enA, LOW);
  delay(10000); //wait about 10 seconds between movements
  
  //Spin Motor in the other direction
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(enA, HIGH); //if we put the enable at the end of the motor control, we can change the state of the in1 and in2 while the motor is stopped.
  delay(10000); //let it spin for about 10 seconds

}
