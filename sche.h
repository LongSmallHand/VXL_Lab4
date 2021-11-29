#ifndef INC_SCHE_H_
#define INC_SCHE_H_

#define SCH_MAX_TASKS 	20
#define NO_TASK_ID 		0
#define RETURN_ERROR 0x00;
#define RETURN_NORMAL 0x01;
#define ERROR_SCH_CANNOT_DELETE_TASK 0x02;
#define ERROR_SCH_TOO_MANY_TASKS 0x03;

unsigned char Error_code_G;

typedef struct {
	void (*pTask)(void);
	unsigned int Delay;
	unsigned int Period;
	unsigned char RunMe;
	unsigned int TaskID;
} sTask;

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init ( void );
void SCH_Dispatch_Tasks (void);
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Update(void);
unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX);
void SCH_Report_Status(void);
//void SCH_Go_To_Sleep(void);

#endif /* INC_SCHE_H_ */
