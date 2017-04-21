#include "simplePID.h"

#define PROPORTIONAL 20
#define INTEGRAL 0
#define DERIVATIVE 0
#define INTEGRATOR_MAX 500
#define INTEGRATOR_MIN -500

//syntax: simplePID PID(Kp,Ki,Kd, initial derivator value (should be 0), initial integrator value (should be 0), maximum integrator value, minimum integrator value)
simplePID PID(PROPORTIONAL,INTEGRAL,DERIVATIVE,0,0,INTEGRATOR_MAX,INTEGRATOR_MIN);


void setup() {


}

void loop() {


}