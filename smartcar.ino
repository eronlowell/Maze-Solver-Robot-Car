//defining motors and sensors
#define LMS 11   // Leftmost sensor
#define LS 10   // Left sensor
#define MS 12   // Middle sensor
#define RS 13 // Right sensor
#define RMS 9 // Rightmost sensor


#define LM1 2   // left motor
#define LM2 3   
#define RM1 4   // right motor
#define RM2 5   

#define S0 A0   // Color Sensor
#define S1 A1   
#define S2 A2   
#define S3 A3   
#define sensorOut 8

int irlms;
int irls;
int irms;
int irrs;
int irrms;

char path[100]= {};
int pathLength = 0;
int readLength = 0;

int replaystage;

int red;

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(MS, INPUT);


  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(S0, OUTPUT);  
  pinMode(S1, OUTPUT);  
  pinMode(S2, OUTPUT);  
  pinMode(S3, OUTPUT); 
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);  
  digitalWrite(S1, LOW); 

  Serial.begin(9600);
}

void loop()
{
  readSensors();
//ColorSensor
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW); 
  red = pulseIn(sensorOut, LOW);
   if (red <= 41 || red >= 70){

     if (irlms==0 && irls==0 && irms==0 && irrs==0 && irrms==0){
      //01-UTurn
       if (path[pathLength-1] != 'B'){
        path[pathLength]= 'B';
        pathLength++;
        Serial.println(path);
        turnRight();
       }
       else{
        turnRight();
       }
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
      if (path[pathLength-1] != 'R' || path[pathLength-1] != 'B'){
        path[pathLength]= 'R';
        pathLength++;
        Serial.println(path);
        turnRight();
        if (path[pathLength-2] == 'B'){
          shortPath();
        }
       }
       else{
        turnRight();
       }
     }
     else if (irlms==0 && irls==0 && irms==1 && irrs==0 && irrms==0){
      //05
        if (path[pathLength-1] != 'S'){
        path[pathLength]= 'S';
        pathLength++;
        Serial.println(path);
        forward();
       }
       else{
        forward();
       }
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
        if (path[pathLength-1] != 'L'){
        path[pathLength]= 'L';
        pathLength++;
        Serial.println(path);
        turnLeft();
        if (path[pathLength-2] == 'B'){
          shortPath();
        }
       }
       else{
        turnLeft();
       }
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
        if (path[pathLength-1] != 'L'){
        path[pathLength]= 'L';
        pathLength++;
        Serial.println(path);
        turnLeft();
        if (path[pathLength-2] == 'B'){
          shortPath();
        }
       }
       else{
        turnLeft();
       }
     }
   }
   else{
    stopMotor();
   }
}

void readSensors(){
  irlms = digitalRead(LMS);
  irls = digitalRead(LS);
  irms = digitalRead(MS);
  irrs = digitalRead(RS);
  irrms = digitalRead(RMS);
}

void forward(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(LM2, 90);
    analogWrite(RM2, 90);
}


void backward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(LM1, 90);
    analogWrite(RM2, 90);
}


void turnLeft(){
    digitalWrite(LM1, HIGH); 
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(LM1, 90);
    analogWrite(RM2, 90);
}


void turnRight(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH); 
    digitalWrite(RM2, LOW);
    analogWrite(LM2, 90);
    analogWrite(RM1, 90);
}



void stopMotor(){
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);

  replaystage=1;
  path[pathLength]='D';
  pathLength++;
  delay(5000);
  replay();
}

void shortPath(){

 int shortDone=0;

  if(path[pathLength-3]=='L' && path[pathLength-1]=='R'){
    pathLength-=3;
    path[pathLength]='B';
    shortDone=1;
  }

  if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
    shortDone=1;
  }

  if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
    shortDone=1;
  }

  if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
    shortDone=1;
  }

  if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
    shortDone=1;
  }
    if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='S';
    shortDone=1;
  }
  
  path[pathLength+1]='D';
  path[pathLength+2]='D';
  pathLength++;
}

void replay(){
   readSensors();
  if(irlms == 0 && irrms == 0 && irrs == 0 && irls == 0){
    forward();
  }
  else if (irlms==0 && irls==0 && irms==0 && irrs==1 && irrms==0){
    turnRight();
  }
  else if (irlms==0 && irls==0 && irms==1 && irrs==1 && irrms==0){
    turnRight();
  }
  else if (irlms==0 && irls==1 && irms==0 && irrs==0 && irrms==0){
    turnLeft();
  }
  else if (irlms==0 && irls==1 && irms==1 && irrs==0 && irrms==0){
    turnLeft();
  }
  else{
    if(path[readLength]=='D')
    {
    forward();
    delay(100);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
      endMotion();
    }
    if(path[readLength]=='R')
    {
      while (irlms == 0 && irrms == 0 &&irms==1 && irrs == 0 && irls == 0) {
        turnRight();
      }
    }
    if(path[readLength]=='L'){
      while (irlms == 0 && irrms == 0 &&irms==1 && irrs == 0 && irls == 0){
        turnLeft();
      }
    }
    if(path[readLength]=='S'){
    forward();
    }
    readLength++;
  }
  replay();
}

void endMotion()

{
  endMotion();
}
