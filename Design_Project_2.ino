void setup() {
  //pins for Accelerometer
  pinMode(A5, INPUT);

  //pins for joystick
  pinMode(A3, INPUT);
  pinMode(A1, INPUT);

  //pins for touch sensor
  pinMode(13, INPUT);

  //pin for start button
  pinMode(12 ,INPUT);
  
  //pin for power button
  pinMode(11 ,INPUT);

  //pin for LED
  pinMode(10, OUTPUT);

  //pin for speaker
  pinMode(9, OUTPUT);

  //pins for LED Display
  //LED2
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  //LED1
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
    
}
  boolean RUNNING, PLAYING;
  int onesDigit, tensDigit, score = 0;
  

void loop() {

  int ON = digitalRead(11);
  int START = digitalRead(12);
  
  
  
  //turn machine on
  if(ON == HIGH)
  {
    delay(1000);
    RUNNING = true;
    score = 0;
  }
  else if(ON == HIGH && RUNNING == true){
    RUNNING  = false;
    score = 0;
  }

  if(RUNNING == true)
  {
     //LED Display, set both to persisting value
     //set ones digit/LED2
     onesDigit = score%10;
     if(onesDigit == 0)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 1)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 2)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 3)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 4)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 5)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 6)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 7)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 8)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 9)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }

     //set tens digit/LED1
     tensDigit = score/10U%10;
          if(onesDigit == 0)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 1)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 2)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 3)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 4)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 5)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 6)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 7)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 8)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 9)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     

     //start game
     if(START == HIGH)
     {
        delay(1000);
        PLAYING = true;
        score = 0;
     }

     if(PLAYING == true)
      {
       int randNumber = random(3);

       //touch sensor
       if(randNumber==0)
       {
          digitalWrite(9, HIGH);
          delay(100);
          digitalWrite(9, LOW);
          for(int i =0;i<3000;i++)
          {
          int touchInput = digitalRead(13);
          if(touchInput==HIGH)
          {
            score++;
            i = 3000;
          }
          else if(i==2999)
          {
            PLAYING = false;
          digitalWrite(9, HIGH);
          delay(1000); 
          digitalWrite(9, LOW); 
          }
          delay(1);
          }

       }

       //joystick
       if(randNumber==1)
       {
          digitalWrite(9, HIGH);
          delay(100);
          digitalWrite(9, LOW);
          delay(100);
          digitalWrite(9, HIGH);
          delay(100); 
          digitalWrite(9, LOW);         
          for(int i =0;i<3000;i++)
          {
          int stickXinput = analogRead(A3);
          int stickYinput = analogRead(A1);
          if(stickXinput>2 || stickXinput<-2||stickYinput>2||stickYinput<-2)
          {
            score++;
            i = 3000;
          }
          else if(i==2999)
          {
            PLAYING = false;
          digitalWrite(9, HIGH);
          delay(1000); 
          digitalWrite(9, LOW);       
          }
          delay(1);
          }
        
       }
       
       //accelerometer
       if(randNumber==2)
       {
          digitalWrite(9, HIGH);
          delay(100);
          digitalWrite(9, LOW);
          delay(100);
          digitalWrite(9, HIGH);
          delay(100); 
          digitalWrite(9, LOW);       
          delay(100);
          digitalWrite(9, HIGH);
          delay(100); 
          digitalWrite(9, LOW);      
          for(int i =0;i<3000;i++)
          {
          int accelInput = analogRead(A5);
          if(accelInput>2 || accelInput<-2)
          {
            score++;
            i = 3000;
          }
          else if(i==2999)
          {
            PLAYING = false;
          digitalWrite(9, HIGH);
          delay(1000); 
          digitalWrite(9, LOW); 
          }
          delay(1);
          }
          
       }
        
      }
      else if(PLAYING == false)
      {
             //set ones digit/LED2
     onesDigit = score%10;
     if(onesDigit == 0)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 1)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 2)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 3)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 4)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 5)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 6)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 7)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 8)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 9)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }

     //set tens digit/LED1
     tensDigit = score/10U%10;
          if(onesDigit == 0)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 1)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 2)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 3)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 4)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 5)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 6)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 7)
     {
      digitalWrite(8, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(5, HIGH);
     }
     else if(onesDigit == 8)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);
     }
     else if(onesDigit == 9)
     {
      digitalWrite(8, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
     }
      }
    
  }


}
