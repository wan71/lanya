/**
 * Copyright (c) 2019, Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef BLE_SIMPLE_PERIPHERAL_H
#define BLE_SIMPLE_PERIPHERAL_H
 
 /*
 * INCLUDES (����ͷ�ļ�)
 */

/*
 * MACROS (�궨��)
 */

/*
 * CONSTANTS (��������)
 */


/*
 * TYPEDEFS (���Ͷ���)
 */


/*
 * GLOBAL VARIABLES (ȫ�ֱ���)
 */



/*
 * LOCAL VARIABLES (���ر���)
 */
 
/*
 * LOCAL FUNCTIONS (���غ���)
 */

/*
 * EXTERN FUNCTIONS (�ⲿ����)
 */

/*
 * PUBLIC FUNCTIONS (ȫ�ֺ���)
 */


/** @function group ble peripheral device APIs (ble������ص�API)
 * @{
 */
 
void app_gap_evt_cb(gap_event_t *p_event);


/*********************************************************************
 * @fn      simple_peripheral_init
 *
 * @brief   Initialize simple peripheral profile, BLE related parameters.
 *
 * @param   None. 
 *       
 *
 * @return  None.
 */
void simple_peripheral_init(void);

#endif
