 int pinA = 3;  // Connected to CLK on KY-040
 int pinB = 2;  // Connected to DT on KY-040
 int encoderPos = 0; 
 int pinALast;  
 int aVal;
 boolean bCW;

 void setup() { 
   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   /* Read Pin A
   Whatever state it's in will reflect the last position   
   */
   pinALast = digitalRead(pinA);   
   Serial.begin (9600);
 } 

 void loop() { 
   aVal = digitalRead(pinA);
   //Serial.println(aVal);
   if (aVal != pinALast){ // Means the knob is rotating
     // if the knob is rotating, we need to determine direction
     // We do that by reading pin B.
     if (digitalRead(pinB) != aVal) {  // Means pin A Changed first - We're Rotating Clockwise
       encoderPos ++;
       //bCW = true;
     } 
     else {// Otherwise B changed first and we're moving CCW
       //bCW = false;
       encoderPos--;
     }
     Serial.println(encoderPos);
     
   } 
   pinALast = aVal;
 } 
