#include <stdint.h>

#include "os_task.h"
#include "os_msg_q.h"

#include "co_printf.h"
#include "user_task.h"
#include "button.h"

uint16_t user_task_id;
struct NCOV_DATA event;


static int user_task_func(os_event_t *param)
{
		uint16_t id = param->event_id;    //获取消息ID
	  /* 读取传递的参数 */
    struct NCOV_DATA *event;
	   event = param->param;
    switch(param->event_id)
    {
			 case TASK1:
            co_printf("data1:%d, data2:%d, data3: %s, data4: %d\r\n",event->data1, event->data2, event->data3, event->data4);
            break;
        default: break;
			
			
			
			
			
        case USER_EVT_BUTTON:
            {
                struct button_msg_t *button_msg;
                const char *button_type_str[] = {
                                                    "BUTTON_PRESSED",
                                                    "BUTTON_RELEASED",
                                                    "BUTTON_SHORT_PRESSED",
                                                    "BUTTON_MULTI_PRESSED",
                                                    "BUTTON_LONG_PRESSED",
                                                    "BUTTON_LONG_PRESSING",
                                                    "BUTTON_LONG_RELEASED",
                                                    "BUTTON_LONG_LONG_PRESSED",
                                                    "BUTTON_LONG_LONG_RELEASED",
                                                    "BUTTON_COMB_PRESSED",
                                                    "BUTTON_COMB_RELEASED",
                                                    "BUTTON_COMB_SHORT_PRESSED",
                                                    "BUTTON_COMB_LONG_PRESSED",
                                                    "BUTTON_COMB_LONG_PRESSING",
                                                    "BUTTON_COMB_LONG_RELEASED",
                                                    "BUTTON_COMB_LONG_LONG_PRESSED",
                                                    "BUTTON_COMB_LONG_LONG_RELEASED",
                                                };

                button_msg = (struct button_msg_t *)param->param;
                
                co_printf("KEY 0x%08x, TYPE %s.\r\n", button_msg->button_index, button_type_str[button_msg->button_type]);
            }
            break;
    }

    return EVT_CONSUMED;
}

void user_task_init(void)
{
    user_task_id = os_task_create(user_task_func);
}


uint8_t param = 110; //定义要传递的参数
void user1_task_send(void *param)
{

	event.data1 = 111;
	event.data2 = 222;
	event.data3 = "hello event!";
	event.data4 = 124;
	
	os_event_t USER1;//定义一个消息体：
	USER1.event_id = TASK1;        //消息的ID号
  USER1.param = &event;
  USER1.param_len = sizeof(event);
  USER1.src_task_id = user_task_id;    //任务的ID号
	os_msg_post(user_task_id,&USER1);
}
