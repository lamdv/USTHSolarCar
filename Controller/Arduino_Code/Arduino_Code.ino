#define FORWARD_1 8
#define BACKWARD_1 9
#define FORWARD_2 12
#define BACKWARD_2 13
#define PWM_1 10
#define PWM_2 11

#define m_forward 100
#define m_backward 101
#define m_left 201
#define m_right 202

void setMotion(int motor, int motion);
void setSpeed(int motor, int speed);

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
	setMotion(m_right,m_forward);
	setMotion(m_left,m_forward);
	setSpeed(m_left,255);
	setSpeed(m_right,255);
}

void setMotion(int motor, int motion)
{
	switch(motor)
	{
		case m_left:
			switch(motion)
			{
				case m_forward:
				digitalWrite(FORWARD_1,HIGH);
				digitalWrite(BACKWARD_1,LOW);
				break;
				case m_backward:
				digitalWrite(FORWARD_1,LOW);
				digitalWrite(BACKWARD_1,HIGH);
				break;
			}
			break;
		case m_right:
			switch(motion)
			{
				case m_forward:
				digitalWrite(FORWARD_2,HIGH);
				digitalWrite(BACKWARD_2,LOW);
				break;
				case m_backward:
				digitalWrite(FORWARD_2,LOW);
				digitalWrite(BACKWARD_2,HIGH);
				break;
			}
			break;
	}
	
}

void setSpeed(int motor, int speed)
{
	switch(motor)
	{
		case m_left:
			analogWrite(PWM_1, speed);
			break;
		case m_right:
			analogWrite(PWM_2, speed);
			break;
	}
}