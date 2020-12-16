/*
 * pid.c
 *
 *  Created on: Dec 16, 2020
 *      Author: javi
 */


#include "pid.h"

void pid_Ctor(pid_Class * me, float kp, float ki, float kd, float ts, float upper_limit, float lower_limit){
	me->kp = kp;
	me->ki = ki;
	me->kd = kd;
	me->ts = ts;
	me->upper_limit = upper_limit;
	me->lower_limit = lower_limit;
	me->ki_x_ts = ki * ts;
	me->setpoint = 0.0F;
	me->last_integral = 0.0F;
	me->last_error = 0.0F;
}

void pid_Set_Setpoint(pid_Class * me, float setpoint){
	me->setpoint = setpoint;
}

float pid_Get_Setpoint(pid_Class * me){
	return me->setpoint;
}

float pid_Calc_Output(pid_Class * me, float input){
	float error;
	float proportional;
	float integral;

	error = me->setpoint - input;
	proportional = error * me->kp;
	integral = me->ki_x_ts * me->last_error + me->last_integral;
	if(integral > me->upper_limit){
		integral = me->upper_limit;
	}else if (integral < me->lower_limit){
		integral = me->lower_limit;
	}
	me->last_error = error;
	me->last_integral = integral;
	return proportional + integral;
}
