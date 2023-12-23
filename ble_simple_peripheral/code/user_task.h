#ifndef _USER_TASK_H
#define _USER_TASK_H

enum user_event_t {
    USER_EVT_AT_COMMAND,
    USER_EVT_BUTTON,
		TASK1,
};
struct NCOV_DATA
{
    uint16_t data1;
    uint16_t data2;
    char *data3;
    uint8_t data4;
};


extern uint16_t user_task_id;

void user_task_init(void);
void user1_task_send(void *param);
#endif  // _USER_TASK_H

