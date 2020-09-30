#define LS 2
#define MIDDLE 3
#define RS 4


#define LM2 6
#define LM1 5
#define RM2 10
#define RM1 11
int s1,s2,s3;
void setup() 
{
  Serial.begin(9600);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(MIDDLE, INPUT) ;

  pinMode(LM1, OUTPUT);  //left motors forward
  pinMode(LM2, OUTPUT);  //left motors reverse
  pinMode(RM1, OUTPUT);  //right motors forward
  pinMode(RM2, OUTPUT);  //right motors reverse
}

void loop() {
  s3 = digitalRead(LS);
  s2 = digitalRead(MIDDLE);
  s1 = digitalRead(RS);
  Serial.print(s1);
  Serial.print(" -- ");
  Serial.print(s2);
  Serial.print(" -- ");
  Serial.print(s3);
  Serial.print(" -- ");

    if(  s3==0 && s2== 1 &&  s1==0  )     
{
  forward();
  }
  


  if( s3==0 && s2==0 && s1==1)     
  {
    //stopm();
    right();   
}
if(  (s3==1 && s2== 0&& s1== 0))     
  {
    //stopm();
    left();
   
  }




if(  s3==0 && s2==1 && s1==1 )     
  {
    //stopm();
    sright();
   
  }


if(  s3==1 && s2== 1 && s1==0  )     
  {
    //stopm();
    sleft();
  }
if(  s3==1 && s2== 1 && s1==1  )  
  {
    stopm();
   
    //stopm();
  }
  if(  s3==0 && s2== 0 && s1==0  )  
  { 
   //back();
  }


}


void forward()
{
  analogWrite(LM2, 0);
  analogWrite(LM1, 60);
  analogWrite(RM2, 0);
  analogWrite(RM1, 60);
  Serial.println(" Moving forward");

}
void back()
{
  analogWrite(LM2, 60);
  analogWrite(LM1, 0);
  analogWrite(RM2, 60);
  analogWrite(RM1, 0);
  Serial.println("Moving Backward");
  //delay(300);
}
void stopm()
{
  analogWrite(LM2, 0);
  analogWrite(LM1, 0);
  analogWrite(RM2, 0);
  analogWrite(RM1, 0);
  Serial.println("stop");
}
void left()
{
  analogWrite(LM2, 0);
  analogWrite(LM1, 0);
  analogWrite(RM2, 0);
  analogWrite(RM1, 60);
  Serial.println(" Rotate Left");
  //delay(300);
}
void right()
{
  analogWrite(LM2, 0);
  analogWrite(LM1, 60);
  analogWrite(RM2, 0);
  analogWrite(RM1, 0);
  Serial.println(" Rotate Right");
}
void sleft()
{
  analogWrite(LM2, 0);
  analogWrite(LM1, 80);
  analogWrite(RM2, 50);
  analogWrite(RM1, 0);
  Serial.println(" Rotate Left sharp");
  //delay(300);
}
void sright()
{
  analogWrite(LM2, 40);
  analogWrite(LM1, 0);
  analogWrite(RM2,0 );
  analogWrite(RM1, 80);
  Serial.println(" Rotate Right sharp");
  //delay(300);
}
