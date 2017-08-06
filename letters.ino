void gap() 
{
  pot_pos();
  while (analogRead(analogpin) > pot_init - 20)
  {
    mov_m2(m2_spd);
  }
  mov_m2(0);
  delay(500);
}

void M()
{
  read_ultra();
  while (val_ultra < 20)
  { //servo downlift
    myservo.write(pos_f);
    mov_m1(m1_spd);
       read_ultra();
    //Serial.println(val_ultra);
  }myservo.write(pos_i);
  mov_m1(0);
  delay(500);

  pot_pos();
  while (analogRead(analogpin) > pot_init - 10)
  {myservo.write(pos_f);
    mov_m2(m2_spd);
  }
  myservo.write(pos_i);
  mov_m2(0);
  delay(500);

  while (val_ultra > 15)
  {myservo.write(pos_f);
    mov_m1(-m1_spd);
    read_ultra();
  }myservo.write(pos_i);
  //servo uplift
mov_m1(0);
  delay(500);

  while (val_ultra < 20)
  {
    mov_m1(m1_spd);
    read_ultra();
    Serial.println(val_ultra);
  }
  mov_m1(0);
  delay(500);

  pot_pos();
  while (analogRead(analogpin) > pot_init - 10){
    myservo.write(pos_f);
   mov_m2(m2_spd);}
   myservo.write(pos_i);
  mov_m2(0);
  delay(500);

  while (val_ultra > 10)
  {myservo.write(pos_f);
    mov_m1(-m1_spd);
   read_ultra();
    //Serial.println(val_ultra);
  }myservo.write(pos_i);
  mov_m1(0);
}
void A() {
  {
  while (val_ultra < 20)
  { //servo downlift
    myservo.write(pos_f);
    mov_m1(m1_spd);
    read_ultra();
    // Serial.println(val_ultra);

  }
  myservo.write(pos_i);
 mov_m1(0);
  delay(500);
}
pot_init = analogRead(analogpin);
while (analogRead(analogpin) > pot_init - 30)
{myservo.write(pos_f);
  mov_m2(m2_spd);
}myservo.write(pos_i);
mov_m2(0);
delay(500);

while (val_ultra > 15)
{myservo.write(pos_f);
  mov_m1(-m1_spd);
  read_ultra();
}myservo.write(pos_i);
//servo uplift
mov_m1(0);
delay(500);
pot_init = analogRead(analogpin);
while (analogRead(analogpin) < pot_init + 50)
{myservo.write(pos_f);
  mov_m2(-m2_spd);
}
myservo.write(pos_i);
mov_m2(0);
//servo uplift
delay(500);
pot_init = analogRead(analogpin);
while (analogRead(analogpin) > pot_init - 40)
{
  mov_m2(m2_spd);
}
mov_m2(0);
delay(500);
while (val_ultra > 10)
{myservo.write(pos_f);
  mov_m1(-m1_spd);
  read_ultra();
}myservo.write(pos_i);
//servo uplift
mov_m1(0);}
void R() 
{
  while (val_ultra < 20)
  {myservo.write(pos_f);
    mov_m1(m1_spd);
    read_ultra();
  }myservo.write(pos_i);
  //servo uplift
  mov_m1(0);
  delay(500);
  pot_pos();
  while (analogRead(analogpin) > pot_init - 25)
  {myservo.write(pos_f);
    mov_m2(m2_spd);
  }myservo.write(pos_i);
  mov_m2(0);
  delay(500);
  while (val_ultra > 15)
  {myservo.write(pos_f);
    mov_m1(-m1_spd);
    read_ultra();
  }myservo.write(pos_i);
  //servo uplift
  mov_m1(0);
  delay(500);
  pot_pos();
  while (analogRead(analogpin) < pot_init + 50)
  {myservo.write(pos_f);
    mov_m2(-m2_spd);
  }myservo.write(pos_i);
  mov_m2(0);
  delay(500);
  //servo uplift
  pot_pos();
  while (analogRead(analogpin) > pot_init - 30)
  {
    mov_m2(m2_spd);
  }
  mov_m2(0);
  delay(500);
  while (val_ultra > 10)
  {myservo.write(pos_f);
    mov_m1(-m1_spd);
    read_ultra();
  }myservo.write(pos_i);
  //servo uplift
  mov_m1(0);
}
void S() 
{
  pot_pos();
  while (analogRead(analogpin) > pot_init - 30){
   myservo.write(pos_f);
    mov_m2(m2_spd);}
    myservo.write(pos_i);
  mov_m2(0);
  delay(500);
  while (val_ultra < 15)
  {myservo.write(pos_f);
    mov_m1(m1_spd);
    read_ultra();
  }myservo.write(pos_i);
  //servo uplift
  mov_m1(0);
  delay(500);
  pot_pos();
  while (analogRead(analogpin) < pot_init + 45){
    myservo.write(pos_f);
    mov_m2(-m2_spd);}
    myservo.write(pos_i);
  mov_m2(0);
  delay(500);
  while (val_ultra < 20)
  {myservo.write(pos_f);
    mov_m1(m1_spd);
    read_ultra();
  }myservo.write(pos_i);
  //servo uplift
  mov_m1(0);
  delay(500);
  pot_pos();
  while (analogRead(analogpin) > pot_init - 40){
    myservo.write(pos_f);
    mov_m2(m2_spd);}
    myservo.write(pos_i);
  mov_m2(0);
}
