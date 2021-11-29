#include "time.h"
#include "main.h"
#include "sche.h"

int time_cycle = 10;
int timer0_counter = 0;
int timer1_counter = 0;
int timer0_flag = 0;
int timer1_flag = 0;

void setTimer0 (int duration) {
	timer0_counter = duration/time_cycle ;
	timer0_flag = 0;
}
void setTimer1 (int duration) {
	timer1_counter = duration/time_cycle ;
	timer1_flag = 0;
}
void TimerInit(void) {
	setTimer0(10);
	setTimer1(10);
}
void timer0_run () {
	if(timer0_counter > 0) {
		timer0_counter --;
		if(timer0_counter == 0) timer0_flag = 1;
	}
}
void timer1_run(){
	if(timer1_counter > 0) {
		timer1_counter --;
		if(timer1_counter == 0) timer1_flag = 1;
	}
}
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	SCH_Update();
	timer0_run();
	timer1_run();
}
