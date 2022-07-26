//defining motors and sensors
#define LMS 12   // Leftmost sensor
#define LS 11   // Left sensor
#define MS 10   // Middle sensor
#define RS 9 // Right sensor
#define RMS 8 // Rightmost sensor


#define LM1 2   // left motor
#define LM2 3   
#define RM1 4   // right motor
#define RM2 5   



int irlms;
int irls;
int irms;
int irrs;
int irrms;

char path[100]= " ";
int pathLength = 0;
int pathIndex = 0;



void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(MS, INPUT);
  pinMode(LMS, INPUT);
  pinMode(RMS, INPUT);


  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  

  Serial.begin(9600);
}

void loop()
{
   irlms = digitalRead(LMS);
   irls = digitalRead(LS);
   irms = digitalRead(MS);
   irrs = digitalRead(RS);
   irrms = digitalRead(RMS);

   if (irlms==0 && irls==0 && irms==0 && irrs==0 && irrms==0){
    //01
    turnRight();
   }
   else if (irlms==0 && irls==0 && irms==0 && irrs==0 && irrms==1){
    //02
    turnRight();
   }
   else if (irlms==0 && irls==0 && irms==0 && irrs==1 && irrms==0){
    //03
    turnRight();
   }
   else if (irlms==0 && irls==0 && irms==0 && irrs==1 && irrms==1){
    //04
    turnRight();
   }
   else if (irlms==0 && irls==0 && irms==1 && irrs==0 && irrms==0){
    //05
    forward();
   }
   else if (irlms==0 && irls==0 && irms==1 && irrs==0 && irrms==1){
    //06
    turnRight();
   }
   else if (irlms==0 && irls==0 && irms==1 && irrs==1 && irrms==0){
    //07
    turnRight();
   }
   else if (irlms==0 && irls==0 && irms==1 && irrs==1 && irrms==1){
    //08
    turnRight();
   }
   else if (irlms==0 && irls==1 && irms==0 && irrs==0 && irrms==0){
    //09
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==0 && irrs==0 && irrms==1){
    //10
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==0 && irrs==1 && irrms==0){
    //11
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==0 && irrs==1 && irrms==1){
    //12
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==1 && irrs==0 && irrms==0){
    //13
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==1 && irrs==0 && irrms==1){
    //14
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==1 && irrs==1 && irrms==0){
    //15
    turnLeft();
   }
   else if (irlms==0 && irls==1 && irms==1 && irrs==1 && irrms==1){
    //16
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==0 && irrs==0 && irrms==0){
    //17 
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==0 && irrs==0 && irrms==1){
    //18 NODE
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==0 && irrs==1 && irrms==0){
    //19 NODE
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==0 && irrs==1 && irrms==1){
    //20 NODE
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==1 && irrs==0 && irrms==0){
    //21 NODE
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==1 && irrs==0 && irrms==1){
    //22 NODE
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==1 && irrs==1 && irrms==0){
    //23
    turnLeft();
   }
   else if (irlms==1 && irls==0 && irms==1 && irrs==1 && irrms==1){
    //24 NODe
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==0 && irrs==0 && irrms==0){
    //25
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==0 && irrs==0 && irrms==1){
    //26
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==0 && irrs==1 && irrms==0){
    //27
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==0 && irrs==1 && irrms==1){
    //28 NODE
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==1 && irrs==0 && irrms==0){
    //29
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==1 && irrs==0 && irrms==1){
    //30 NODE T
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==1 && irrs==1 && irrms==0){
    //31
    turnLeft();
   }
   else if (irlms==1 && irls==1 && irms==1 && irrs==1 && irrms==1){
    //32 NODE T
    turnLeft();
   }
}

void forward(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(LM2, 90);
    analogWrite(RM2, 90);
    Serial.println("FORWARD");
}

void backward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(LM1, 90);
    analogWrite(RM2, 90);
    Serial.println("BACKWARD");
}

void turnLeft(){
    digitalWrite(LM1, HIGH); 
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(LM1, 90);
    analogWrite(RM2, 90);
    Serial.println("TURN Left");
}

void turnRight(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH); 
    digitalWrite(RM2, LOW);
    analogWrite(LM2, 90);
    analogWrite(RM1, 90);
    Serial.println("TURN Right");
}



void stopMotor(){
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  Serial.println("STOP");
}
