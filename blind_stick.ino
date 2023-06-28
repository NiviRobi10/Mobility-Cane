int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int const trigPin = 10; 
int const echoPin = 9;
int const buzzPin = 2;
void setup()
{
 pinMode(trigPin, OUTPUT);
 // trig pin will have pulses output
 pinMode(echoPin, INPUT);
 // echo pin should be input to get pulse width
 pinMode(buzzPin, OUTPUT);
 // buzz pin is output to control buzzering
 }
 void loop()
 {
 // Duration will be the input pulse width and distance will be the distance to the 
obstacle in centimeters
 int duration, distance;
 // Output pulse with 1ms width on trigPin 
 digitalWrite(trigPin, HIGH);
 delay(1);
 digitalWrite(trigPin, LOW);
 // Measure the pulse input in echo pin
 duration = pulseIn(echoPin, HIGH);
 // Distance is half the duration devided by 29.1 (from datasheet)
 distance = (duration/2) / 29.1;
 // if distance less than 0.5 meter and more than 0 (0 or less means over range)
 if (distance <= 50 && distance >= 0)
 { 
 // Buzz digitalWrite(buzzPin, HIGH); 
 }
 else
 { 
 // Don't buzz
 digitalWrite(buzzPin, LOW);
 }
 // Waiting 60 ms won't hurt any one
 delay(60);
 }
 // TCS230 or TCS3200 pins wiring to Arduino
void setup() {
 // Setting the outputs
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 
 // Setting the sensorOut as an input
 pinMode(sensorOut, INPUT);
 
 // Setting frequency scaling to 20%
 digitalWrite(S0,HIGH);
 digitalWrite(S1,LOW);
 
 // Begins serial communication 
 Serial.begin(9600);
}
void loop() {
 // Setting RED (R) filtered photodiodes to be read
 digitalWrite(S2,LOW);
 digitalWrite(S3,LOW);
  // Reading the output frequency
 redFrequency = pulseIn(sensorOut, LOW);
 
 // Printing the RED (R) value
 Serial.print("R = ");
 Serial.print(redFrequency);
 delay(100);
 
 // Setting GREEN (G) filtered photodiodes to be read
 digitalWrite(S2,HIGH);
 digitalWrite(S3,HIGH);
 
 // Reading the output frequency
 greenFrequency = pulseIn(sensorOut, LOW);
 
 // Printing the GREEN (G) value 
 Serial.print(" G = ");
 Serial.print(greenFrequency);
 delay(100);
 // Setting BLUE (B) filtered photodiodes to be read
 digitalWrite(S2,LOW);
digitalWrite(S3,HIGH);
 
 // Reading the output frequency
 blueFrequency = pulseIn(sensorOut, LOW);
 
 // Printing the BLUE (B) value 
 Serial.print(" B = ");
 Serial.println(blueFrequency);
 delay(100);
}
