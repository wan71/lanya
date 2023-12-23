#include <stdbool.h>
#include "os_timer.h"
#include "gap_api.h"
#include "gatt_api.h"
#include "driver_gpio.h"
#include "simple_gatt_service.h"
#include "ble_simple_peripheral.h"
#include "user_task.h"
#include "sys_utils.h"
#include "flash_usage_config.h"

os_timer_t test_timer;

static void test_time_fn(void *param)
{
 co_printf("1s timer\r\n");
	user1_task_send(NULL);
}
void user1_init(void)
{
	os_timer_init(&test_timer,test_time_fn, NULL);
  os_timer_start(&test_timer,1000, true); //启动一个 1s 的定时器。

}

os_timer_t lanya_writer_timer;
extern uint8_t sp_conidxx;//蓝牙连接号conidx
extern uint8_t sp_svc_id;//服务号
static void lanya_writer_time_fn(void *param)
{
	co_printf("1ss timer\r\n");
	gatt_ntf_t ntf_att;
	ntf_att.att_idx = 2;
	ntf_att.conidx = sp_conidxx;
	ntf_att.svc_id = sp_svc_id;
//ntf_att.svc_id = svc_id;
	ntf_att.data_len = 5;
  uint8_t tmp[] = "12345";
  ntf_att.p_data = tmp;
	gatt_notification(ntf_att);


}	

void lanya_writer_init(void)
{
	os_timer_init(&lanya_writer_timer,lanya_writer_time_fn, NULL);
	os_timer_start(&lanya_writer_timer,1000, true); //启动一个 1s 的定时器。
	
}

