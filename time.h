#ifndef INC_TIME_H_
#define INC_TIME_H_

extern int time_cycle;

void TimerInit(void);
void setTimer0(int duration);
void setTimer1(int duration);
void timer0_run();
void timer1_run();
#endif /* INC_TIME_H_ */
