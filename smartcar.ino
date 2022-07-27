//defining motors and sensors
#define LMS 11   // Leftmost sensor
#define LS 10   // Left sensor
#define MS 12   // Middle sensor
#define RS 13 // Right sensor
#define RMS 9 // Rightmost sensor
#define RMMS 7
#define LMMS 8


#define LM1 2   // left motor
#define LM2 3   
#define RM1 4   // right motor
#define RM2 5   

int irlms;
int irls;
int irms;
int irrs;
int irrms;
int irrmms;
int irlmms;

char path[100]= {};
int pathLength = 0;
int readLength = 0;

int replaystage;

void setup()
{
  pinMode(LS, INPUT);
  pinMode(LMS, INPUT);
  pinMode(LMMS, INPUT);
  pinMode(RS, INPUT);
  pinMode(RMS, INPUT);
  pinMode(RMMS, INPUT);
  pinMode(MS, INPUT);


  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  readSensors();
    if (irlms==0 && irls==0 && irms==0 && irrs==0 && irrms==0){
      //01-UTurn
      if (irlmms == 1 && irrmms == 1){
        Serial.println("stoppp");
        stopMotor();
      }
      else{
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
      if (path[pathLength-1] != 'R'){
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
        if (path[pathLength-2] == 'B'){
          shortPath();
        }
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
      if (path[pathLength-1] != 'R'){
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
     else if (irlms==0 && irls==1 && irms==1 && irrs==0 && irrms==1){
      //14
      turnLeft();
     }
     else if (irlms==0 && irls==1 && irms==1 && irrs==1 && irrms==0){
      //15
      forward();
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


void readSensors(){
  irlms = digitalRead(LMS);
  irls = digitalRead(LS);
  irms = digitalRead(MS);
  irrs = digitalRead(RS);
  irrms = digitalRead(RMS);
  irrmms = digitalRead(RMMS);
  irlmms = digitalRead(LMMS);
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

  Serial.println("STOP");

  replaystage=1;
  path[pathLength]='D';
  pathLength++;
  delay(7000);
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
  pathLength++;
}

void replay(){
  Serial.println("REPLAY");
   readSensors();
  if(irlms == 0 && irrms == 0 && irms==1 && irrs == 0 && irls == 0){
    forward();
     Serial.println("REPLAY:1");
  }
  else if (irlms==0 && irls==0 && irms==0 && irrs==0 && irrms==0){
      //01-UTurn
      turnRight();
  }
  else if (irlms==0 && irls==0 && irms==0 && irrs==1 && irrms==0){
    turnRight();
     Serial.println("REPLAY:2");
  }
  else if (irlms==0 && irls==0 && irms==1 && irrs==1 && irrms==0){
    turnRight();
     Serial.println("REPLAY:3");
  }
  else if (irlms==0 && irls==1 && irms==0 && irrs==0 && irrms==0){
    turnLeft();
     Serial.println("REPLAY:4");
  }
  else if (irlms==0 && irls==1 && irms==1 && irrs==0 && irrms==0){
    turnLeft();
     Serial.println("REPLAY:4");
  }
  else if (irlms==0 && irls==1 && irms==1 && irrs==1 && irrms==0){
    forward();
     Serial.println("REPLAY:5");
  }
  else{
     Serial.println("REPLAY:ELSE");
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
       turnRight();
    }
    if(path[readLength]=='L'){
        turnLeft();
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
   Serial.println("ENDDDDD");
  endMotion();
}
