#include <Servo.h>
#include <stdio.h>
#define DEBUG

Servo leftServo;
Servo rightServo;

    int ldrLeft;
    int ldrCenter;
    int ldrRight;
    
  bool btnBlackRead;

  int leftDarkInt;
  int centerDarkInt;
  int rightDarkInt;

  int lightCal = 0;
  

//merged all robot movement functions into onto for easier integration further down.

// 0 = forward | 1 = right | 2 = stop | 3 = left - clockwise

void moveRobot( int moveTime, int moveDirection ){

   if ( moveDirection == 0 ) {

   rightServo.write(-20); //20 -go 88 -stop
   leftServo.write(200); //160 -go 81 -stop
   delay(moveTime*1000);
    
    } 
  
   if ( moveDirection == 1 ) {

    
   rightServo.write(200); //20 -go 88 -stop
   leftServo.write(200); //160 -go 81 -stop
   delay(moveTime*1000);
    
    }

    if ( moveDirection == 2 || moveDirection > 3) {
   rightServo.write(83); //20 -go 83 -stop
   leftServo.write(92); //160 -go 91 -stop
   delay(500);
    
    
    }
    
   
   if ( moveDirection == 3 ) {

   rightServo.write(0); //20 -go 88 -stop
   leftServo.write(0); //160 -go 81 -stop
   delay(moveTime*1000);
    
    }

   
 
  
  
  }



    


void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);

  //Btn setup
  pinMode(2, INPUT);
  pinMode(4, INPUT);

  //LDR setup
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  //Servo setup
  rightServo.attach(5);
  leftServo.attach(6);

    ldrLeft = analogRead(A0);
  ldrCenter = analogRead(A1);
  ldrRight = analogRead(A2);

     pinMode(LED_BUILTIN, OUTPUT);
     
      
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   
  

  
       
  
//stop robot for 0 seconds 
moveRobot(0,2);




  

}

void loop() {



  
  btnBlackRead = digitalRead(2);
  
  ldrLeft = analogRead(A0);
  ldrCenter = analogRead(A1);
  ldrRight = analogRead(A2);

  #ifdef DEBUG
  
  Serial.print("A0: ");
  Serial.println(ldrLeft);
  Serial.print("A1: ");
  Serial.println(ldrCenter);;
  Serial.print("A2: ");
  Serial.println(ldrRight);

  delay(1000);

  #endif
 
  //moveRobot(0,2);


       // put your main code here, to run repeatedly:

 while ( btnBlackRead == LOW ){

          btnBlackRead = digitalRead(2);
          
  Serial.print("A0: ");
  Serial.println(ldrLeft);
  Serial.print("A1: ");
  Serial.println(ldrCenter);;
  Serial.print("A2: ");
  Serial.println(ldrRight);

  leftDarkInt = ldrLeft ;
  centerDarkInt = ldrCenter ;
  rightDarkInt = ldrRight ;

    Serial.print("LEFT THRESHOLD: ");
  Serial.println( leftDarkInt*1.3 );
  Serial.print("CENTER THRESHOLD: ");
  Serial.println(centerDarkInt*1.3);;
  Serial.print("RIGHT THRESHOLD: ");
  Serial.println(rightDarkInt*1.3);
  

  lightCal++;


        }

        
         


      

                   while ( lightCal >= 1 && ldrLeft < leftDarkInt*1.5){

                    ldrLeft = analogRead(A0);

              moveRobot(0,1);

             
      }


              while (lightCal >= 1 && ldrCenter < centerDarkInt*1.5){

                    ldrCenter = analogRead(A1);

              moveRobot(0,0);

 
      }


      
                 while (lightCal >= 1 && ldrRight < rightDarkInt*1.5){

                    ldrRight = analogRead(A2);

              moveRobot(0,3);

 
      }

        moveRobot(0,2);
//      while ( lightCal >= 1 && ldrRight > rightDarkInt && ldrCenter > centerDarkInt && ldrLeft > leftDarkInt ){
//
//               ldrLeft = analogRead(A0);
//               ldrCenter = analogRead(A1);
//               ldrRight = analogRead(A2);
//                     
//        
//              moveRobot(0,2);
//              // moveRobot(0,0);
//        
//        
//        }

  
  
  
  }

        
              

      
