#include "Arduino.h"
#include "simplePID.h"

//constructor to initialise

simplePID::simplePID(float P, float I, float D, float derivator, float integrator, float integrator_max, float integrator_min)
{
	this->Kp = P;
	this->Ki = I;
	this->Kd = D;
	this->Derivator = derivator;
	this->Integrator = integrator;
	this->Integrator_max = integrator_max;
	this->Integrator_min = integrator_min;
	setpoint = 0.0;
	error = 0.0;
}

float simplePID::update(float current_value)
{
	//recalculates the PID output value for a given current value
	//work out the error value
	error = setpoint - current_value;

	//proportional output
	P_value = Kp * error;

	//gets the difference between the current and the previous error and gains it up by Kd 
	D_value = Kd * (error - Derivator);

	//set derivator equal to the last error
	Derivator = error;

	//accumulate the error "integral"
	Integrator = Integrator + error;

	//prevent the integrator term getting too large
	if(Integrator > Integrator_max){
		Integrator = Integrator_max;
	}

	//prevent the integrator term getting too small
	if(Integrator < Integrator_min){
		Integrator = Integrator_min;
	}

	//calculate the I value
	I_value = Ki * Integrator;

	//add it all up
	PID = P_value + I_value + D_value;

	//..and return it
	return PID;
}

void simplePID::setPoint(float set_point)
{
	this->setpoint = set_point;
	Integrator = 0;
	Derivator = 0;
}

void setIntegrator(float integrator){
	this->Integrator = integrator;
}

void setDerivator(float derivator){
	this->Derivator = derivator;
}

void setKp(float P){
	this->Kp = P;
}

void setKi(float I){
	this->Ki = I;
}

void setKd(float D){
	this->Kd=  D;
}

float getPoint(){
	return setpoint;
}

float getError(){
	return error;
}

float getIntegrator(){
	return Integrator;
}

float getDerivator(){
	return Derivator;
}