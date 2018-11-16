//  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄         ▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄ 
// ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌
// ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ 
// ▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          
// ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄ 
// ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌
//  ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌
//           ▐░▌▐░▌       ▐░▌          ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
//  ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
// ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
//  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀ 
// Name: Sashwat K
// Code: Home automation using particle.io and IFTTT
// Created on: 15 Nov 2018
// Revision: 1
// Variables used
// relay - integer - D0 (GPIO4)
// indiLed - integer - D1 (GPIO17)
// vin - boolean - on/off states
                                                                                           
int relay = D0; //pin to which relay is connected
bool vin = HIGH; //a virtual boolean variable

// setup() is run only once, it's where we set up GPIO and initialise peripherals
void setup() {
    
  // Setup GPIO
  pinMode(relay,OUTPUT); // relay pin is set as output
  digitalWrite(relay,LOW);
  // Subscribe to events published by IFTTT using Particle.subscribe
  Particle.subscribe("Event_Light_On", offHandler); //turning light on function declaration
  Particle.subscribe("Event_Light_Off", onHandler); //turning light off function declaration
}

// loop() runs continuously, it's our infinite loop.
void loop() {
     if (vin==HIGH)
     {
         digitalWrite(relay,LOW);
     }
else if (vin==LOW)
      {
         digitalWrite(relay,HIGH);
     }

}

//our events are called when IFTTT applets are triggered
void offHandler(const char *event, const char *data)
{
    vin=LOW;
}
void onHandler(const char *event, const char *data)
{
     vin=HIGH;
}