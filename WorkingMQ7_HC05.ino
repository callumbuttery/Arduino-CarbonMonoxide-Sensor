#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Bluetooth(0, 1); // RX, TX

char Incoming_value = 0;                //Variable for storing Incoming_value
const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino const 
int value;
int limit;

void setup() {
  // put your setup code here, to run once:
  Bluetooth.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino 

}

void loop() {
  value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin 
  limit= digitalRead(DOUTpin);//reads the digital value from the CO sensor's DOUT pin 
  
  delay(100);

  if(Bluetooth.available() > 0)
  {
  Bluetooth.print("value: "); Bluetooth.println(value);//prints the CO value 
  Bluetooth.print("\n");
  Bluetooth.print("Limit: "); Bluetooth.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)  
  delay(1000);
  }

  
   //if(Bluetooth.available() > 0)  
  //{
    //Incoming_value = Bluetooth.read();      //Read the incoming data and store it into variable Incoming_value
    //Bluetooth.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    //Bluetooth.print("\n");        //New line 
    //if(Incoming_value == '1')            //Checks whether value of Incoming_value is equal to 1 
      //Bluetooth.write("Hello world");
    //else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
      //Bluetooth.write("Goodbye world");
      
  //}

}
