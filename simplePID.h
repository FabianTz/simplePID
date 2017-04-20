
/*
	simplePID is a simple discrete PID library, based on the python original code from 
	http://code.activestate.com/recipes/577231-discrete-pid-controller/
*/

#ifndef simplePID_h
#define simplePID_h

class simplePID {
	
	public:
		//constructor
		simplePID(float P, float I, float D, float derivator, float integrator, float integrator_max, float integrator_min);

		//Recalculates the PID output
		float update(float current_value);
		void setPoint(float set_point);
		void setIntegrator(float integrator);
		void setDerivator(float derivator);
		void setKp(float P);
		void setKi(float I);
		void setKd(float D);
		float getPoint();
		float getError(),
		float getIntegrator();
		float getDerivator();

	private:

		float Kp;
		float Ki;
		float Kd;
		float Derivator;
		float Integrator;
		float Integrator_min;
		float Integrator_max;
		float setpoint;
		float error;
		float P_value;
		float I_value;
		float D_value;
		float PID;
}

#endif
