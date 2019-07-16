#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); //TX, RX  pins of arduino respetively
String command;
void setup()
{
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  command += c; //build the string.
  } 
  if (command.length() > 0) {
    Serial.println(command);
  if(command == "light on") //this command will be given as an input to switch on light1
  {
    digitalWrite(2, HIGH);
  }
  else if(command == "light off") //this command will be given as an input to switch off light1 simillarly other commands work
  {
    digitalWrite(2, LOW);
  }
  else if (command == "lamp on")
  {
    digitalWrite (3, HIGH);
  }
  else if ( command == "lamp off")
 {
   digitalWrite (3, LOW);
 }
  else if (command == "fan on")
 {
   digitalWrite (4, HIGH);
 }
  else if (command == "fan of")
 {
   digitalWrite (4, LOW);
 }
  else if (command == "all on") //using this command you can switch on all devices
 {
   digitalWrite (2, HIGH);
   digitalWrite (3, HIGH);
   digitalWrite (4, HIGH);
 }
  else if (command == "off")//using this command you can switch off all devices
 {
   digitalWrite (2, LOW);
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
 }
command="";}} //Reset the variable
//you can add other command to control addition devices by adding an elseif 
