char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 13
boolean ledState = LOW; //to toggle our LED


void setup() 


{
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  //initialize serial communications at a 9600 baud rate
  Serial.begin(9600);
  establishContact();  // send a byte to establish contact until receiver responds 
}
void loop()
{
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val

 
  if (val == '1') {         //Check if the received character is 1
  digitalWrite(ledPin, HIGH);   //Make the GPIO High 

  }
  else if (val == '0')  {   ////Check if the received character is 0
  digitalWrite(ledPin, LOW);    //Make the GPIO Low
  }
  else if (val == '2')  {  
    Serial.println(random(90)); 
    Serial.println(random(180));
    Serial.println(random(200));
    Serial.println("sleeping");
    delay(50);
   
  }
  delay(100);
    
  } 
  

    
}
void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   // send a capital A
  delay(300);
  }
}
