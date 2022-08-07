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

bool pathRecorded = false;
bool pathTaken = false;

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

      if (pathRecorded == false && irrmms == 1 && irlmms == 0){
            path[pathLength] = 'B';
            pathLength++;
            turnRight();
            pathRecorded = true;
          }
          else{
          turnRight();
        }
        
      if (irrmms == 1 && irlmms == 1){
        stopMotor();
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
      if (pathRecorded == false){
            path[pathLength] = 'R';
            pathLength++;
            turnRight();
            pathRecorded = true;
          }
          else{
          turnRight();
        }
     }
     else if (irlms==0 && irls==0 && irms==1 && irrs==0 && irrms==0){
      //05
        forward();
        pathRecorded = false;
     }
     else if (irlms==0 && irls==0 && irms==1 && irrs==0 && irrms==1){
      //06
      if (pathRecorded == false){
          path[pathLength]= 'S';
          pathLength++;
          turnLeft();
          pathRecorded = true;
          }
          else{
            turnRight();
          }
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
        if (pathRecorded == false){
        path[pathLength]= 'L';
        pathLength++;
        turnLeft();
        pathRecorded = true;
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
        if (pathRecorded == false){
        path[pathLength]= 'L';
        pathLength++;
        turnLeft();
        pathRecorded = true;
        }
        else{
          turnLeft();
        }
     }

     shortPath();
     
     
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


  if(path[pathLength-3]=='L' && path[pathLength-2]=='B' && path[pathLength-1]=='R'){
    pathLength-=3;
    path[pathLength]='B';
    pathLength++;
  }

  else if(path[pathLength-3]=='L' && path[pathLength-2]=='B' && path[pathLength-1]=='S'){
    pathLength-=3;
    path[pathLength]='R';
    pathLength++;
  }

  else if(path[pathLength-3]=='R' && path[pathLength-2]=='B' && path[pathLength-1]=='L'){
    pathLength-=3;
    path[pathLength]='B';
    pathLength++;
  }

  else if(path[pathLength-3]=='S' && path[pathLength-2]=='B' && path[pathLength-1]=='L'){
    pathLength-=3;
    path[pathLength]='R';
    pathLength++;
  }

  else if(path[pathLength-3]=='S' && path[pathLength-2]=='B' && path[pathLength-1]=='S'){
    pathLength-=3;
    path[pathLength]='B';
    pathLength++;
  }
  else if(path[pathLength-3]=='L' && path[pathLength-2]=='B' && path[pathLength-1]=='L'){
    pathLength-=3;
    path[pathLength]='S';
    pathLength++;
  }
  else{
    Serial.println(path);
  }
  path[pathLength+1] = ' ';
  path[pathLength] = ' ';
}

void replay(){
  
   readSensors();
  if ((irrms == 1) || (irlms == 1)){
    delay(1000);
    if (pathTaken == false){
      if(path[readLength]=='D')
      {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
        endMotion();
      }
      else if(path[readLength]=='R')
      {
        turnRight();
      }
      else if(path[readLength]=='L'){
        turnLeft();
      }
      else if(path[readLength]=='S'){
        forward();
      }
      readLength++;
      pathTaken = true;
    }
    else{
      if (irrs == 1){
        turnRight();
      }
      if (irls == 1){
        turnLeft();
      }
    }
  }
  else{
    if (irls == 0 && irms == 0 && irrs == 0){
      turnRight();
    }
    else if (irls == 0 && irms == 0 && irrs == 1){
      turnRight();
    }
    else if (irls == 0 && irms == 1 && irrs == 0){
      forward();
      pathTaken = false;
    }
    else if (irls == 0 && irms == 1 && irrs == 1){
      turnRight();
    }
    else if (irls == 1 && irms == 0 && irrs == 0){
      turnLeft();
    }
    else if (irls == 1 && irms == 1 && irrs == 0){
      turnLeft();
    }
    else if (irls == 1 && irms == 1 && irrs == 1){
      turnLeft();
    }
    
  }
}

void endMotion()

{
   Serial.println("ENDDDDD");
  endMotion();
}
