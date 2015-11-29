#define FORWARD_1 8
#define BACKWARD_1 9
#define FORWARD_2 10
#define BACKWARD_2 11
#define PWM_1 12
#define PWM_2 13

#define m_forward 100
#define m_backward 101
#define m_rotate_left 201
#define m_rotate_right 202


void setup()
{

  /* add setup code here */
	pinMode(FORWARD_1, OUTPUT);
	pinMode(BACKWARD_1, OUTPUT);
	pinMode(FORWARD_2, OUTPUT);
	pinMode(BACKWARD_2, OUTPUT);
	pinMode(PWM_1, OUTPUT);
	pinMode(PWM_2, OUTPUT);
}

void loop()
{

  /* add main program code here */
  setMotion(m_forward);
  analogWrite(PWM_1, 255);
  analogWrite(PWM_2, 255);
}

void setMotion(int motion)
{
	switch(motion){
	case m_forward:
		digitalWrite(FORWARD_1,HIGH);
		digitalWrite(BACKWARD_1,LOW);
		digitalWrite(FORWARD_2,HIGH);
		digitalWrite(BACKWARD_2,LOW);
		break;
	case m_backward:
		digitalWrite(FORWARD_1,LOW);
		digitalWrite(BACKWARD_1,HIGH);
		digitalWrite(FORWARD_2,LOW);
		digitalWrite(BACKWARD_2,HIGH);
		break;
	case m_rotate_left:
		digitalWrite(FORWARD_1,LOW);
		digitalWrite(BACKWARD_1,HIGH);
		digitalWrite(FORWARD_2,HIGH);
		digitalWrite(BACKWARD_2,LOW);
		break;	
	case m_rotate_right:
		digitalWrite(FORWARD_1,HIGH);
		digitalWrite(BACKWARD_1,LOW);
		digitalWrite(FORWARD_2,LOW);
		digitalWrite(BACKWARD_2,HIGH);
		break;
	}
}