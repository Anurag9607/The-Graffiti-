#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper myStepper_d(stepsPerRevolution, 2,3,4,5);
Stepper myStepper_t(stepsPerRevolution, 6,7,8,9);
//int stepCount1 = 0;
//int stepCount2 = 0;

//18.5+6.5 cm cannot be used
//53.8 cm is the range of arm
//
int pwm1=10;
int pwm2=11;
int pwm3=12;
int pwm4=13;
int move_steps_t;
int move_steps_d;
float theta=0;
float theta_i=0;
float theta_f=0;
float d_i;
float d_f,delta_d;
float alpha_i,alpha_f,delta_alpha,delta_alpha1;
float pi=3.1415;
float r=7;//in cm 
float cd=50;//25+25 in cm
//float t_max=1.8*int((asin(r/cd)*180/pi)/1.8);
float roundof(float x)
{int i=0;
while(i<(x-1.8)/1.8)
{i=i+1;}
  if(x-1.8*i>=0.9)
  return(1.8*(i+1));
  else
  return(1.8*i);} 
void setup() {
  myStepper_t.setSpeed(10);
 myStepper_d.setSpeed(10);
  Serial.begin(9600);
   pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  
  // put your setup code here, to run once:
}


void loop() {
  if(theta>363){

}

  //float h =roundof(43.2);
  //Serial.println(h);
  // put your main code here, to run repeatedly:
   analogWrite(pwm1,100);
  analogWrite(pwm2,100);
   analogWrite(pwm3,100);
  analogWrite(pwm4,100);
  theta_i=theta;
  theta_f=theta_i+3.6;
  d_i=sqrt(sq(r*cos(pi*theta_i/180))+sq(r*sin(pi*theta_i/180)+cd));
  alpha_i=180*atan((cd+r*sin(theta_i*pi/180))/(r*cos(theta_i*pi/180)))/pi;
if(alpha_i<0){alpha_i=alpha_i+180;
      alpha_f=180*atan((cd+r*sin(theta_f*pi/180))/(r*cos(theta_f*pi/180)))/pi+180;
  delta_alpha=alpha_f-alpha_i;
  delta_alpha1=roundof(delta_alpha);
  }
else
{alpha_f=180*atan((cd+r*sin(theta_f*pi/180))/(r*cos(theta_f*pi/180)))/pi;
  delta_alpha=alpha_f-alpha_i;
  delta_alpha1=roundof(delta_alpha);}  
  d_f= sqrt(sq(r*cos(pi*theta_f/180))+sq(r*sin(pi*theta_f/180)+cd));  
  delta_d=d_f-d_i;
  move_steps_t=delta_alpha1/1.8;
  myStepper_t.step(move_steps_t);
  move_steps_d=abs(delta_d)/9.4*158;
  if(delta_d<0){//stepCount2=stepCount2+1;
  myStepper_d.step(-move_steps_d);
  //delay(500);
  //Serial.println(2);}
  }else{//stepCount1=stepCount1+1*move_steps_d;
   myStepper_d.step(move_steps_d);
   //delay(500);
    //Serial.println(1);
}
theta=theta_f;
delay(300);
//Serial.println(stepCount1);
}


