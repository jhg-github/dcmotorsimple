/*
 * pid.h
 *
 *  Created on: Dec 16, 2020
 *      Author: javi
 */

#ifndef PID_H_
#define PID_H_

typedef struct pid_Class pid_Class;
struct pid_Class{
	float setpoint;
	float kp;
	float ki;
	float kd;
	float ts;
	float ki_x_ts;
	float last_error;
	float last_integral;
	float upper_limit;
	float lower_limit;
};

void pid_Ctor(pid_Class * me, float kp, float ki, float kd, float ts, float upper_limit, float lower_limit);
void pid_Set_Setpoint(pid_Class * me, float setpoint);
float pid_Get_Setpoint(pid_Class * me);
void pid_Set_Gains(pid_Class * me, float kp, float ki, float kd);
void pid_Set_Limits(pid_Class * me, float upper_limit, float lower_limit);
float pid_Calc_Output(pid_Class * me, float input);

#endif /* PID_H_ */
