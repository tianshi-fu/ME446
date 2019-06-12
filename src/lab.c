#include <tistdtypes.h>
#include <coecsl.h>
#include "user_includes.h"
#include "math.h"

// These two offsets are only used in the main file user_CRSRobot.c  You just need to create them here and find the correct offset and then these offset will adjust the encoder readings
float offset_Enc2_rad = -0.424; //-0.37;
float offset_Enc3_rad = 0.209; //0.27;


// Your global varialbes.  

long mycount = 0;

#pragma DATA_SECTION(whattoprint, ".my_vars")
float whattoprint = 0.0;

#pragma DATA_SECTION(theta1array, ".my_arrs")
float theta1array[100];

long arrayindex = 0;

float printtheta1motor = 0;
float printtheta2motor = 0;
float printtheta3motor = 0;

// Assign these float to the values you would like to plot in Simulink
float Simulink_PlotVar1 = 0;
float Simulink_PlotVar2 = 0;
float Simulink_PlotVar3 = 0;
float Simulink_PlotVar4 = 0;

int statevar = 1;
int statecount = 0;

float x;
float y;
float z;

float theta1DH;
float theta2DH;
float theta3DH;

float alpha;
float beta;
float L;

float theta1M;
float theta2M;
float theta3M;
// This function is called every 1 ms
void lab(float theta1motor,float theta2motor,float theta3motor,float *tau1,float *tau2,float *tau3, int error) {


	*tau1 = 0;
	*tau2 = 0;
	*tau3 = 0;

	//Motor torque limitation(Max: 5 Min: -5)

	// save past states
	if ((mycount%50)==0) {

		theta1array[arrayindex] = theta1motor;

		if (arrayindex >= 100) {
			arrayindex = 0;
		} else {
			arrayindex++;
		}

	}

	statecount++;
        switch(statevar){
        case 1:
            GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
            if (statecount == 500){
                statevar = 2;
                statecount = 0;
            }
        break;
        case 2:
                    GpioDataRegs.GPBSET.bit.GPIO60 = 1;
                    if (statecount == 500){
                        statevar = 3;
                        statecount = 0;
                    }
        break;
        case 3:
                    GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
                    if (statecount == 1000){
                        statevar = 4;
                        statecount = 0;
                    }
                break;
        case 4:
                    GpioDataRegs.GPBSET.bit.GPIO60 = 1;
                    if (statecount == 500){
                        statevar = 5;
                        statecount = 0;
                    }
                break;
        case 5:
                    GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
                    if (statecount == 1500){
                        statevar = 6;
                        statecount = 0;
                    }
                break;
        case 6:
                    GpioDataRegs.GPBSET.bit.GPIO60 = 1;
                    if (statecount == 500){
                        statevar = 1;
                        statecount = 0;
                    }
                break;

        }

	if ((mycount%500)==0) {
		if (whattoprint > 0.5) {
			serial_printf(&SerialA, "I love robotics\n\r");
		} else {
			printtheta1motor = theta1motor;
			printtheta2motor = theta2motor;
			printtheta3motor = theta3motor;
			SWI_post(&SWI_printf); //Using a SWI to fix SPI issue from sending too many floats.
		}
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1; // Blink LED on Control Card
		//GpioDataRegs.GPBTOGGLE.bit.GPIO60 = 1; // Blink LED on Emergency Stop Box
		//GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1; // Turn on LED
		//GpioDataRegs.GPBSET.bit.GPIO60 = 1; // Turn off LED


	}


	Simulink_PlotVar1 = theta1motor;
	Simulink_PlotVar2 = theta2motor;
	Simulink_PlotVar3 = theta3motor;
	Simulink_PlotVar4 = 0;

	x = 10*cos(theta1motor)*(cos(theta3motor)+sin(theta2motor));
	y = 10*sin(theta1motor)*(cos(theta3motor)+sin(theta2motor));
	z = 10*(1+cos(theta2motor)-sin(theta3motor));

	theta1DH = atan2(y,x);
	alpha = atan2(z-10,sqrt(x*x+y*y));
	L = sqrt((z-10)*(z-10)+x*x+y*y);
	beta = acos(L/20);
	theta2DH = -alpha - beta;
	theta3DH = 2 * beta;

	theta1M = theta1DH;
	theta2M = theta2DH + PI/2;
	theta3M = theta3DH + theta2DH;

	mycount++;
}

void printing(void){
	serial_printf(&SerialA, "%.2f %.2f,%.2f, %.2f %.2f %.2f, %.2f %.2f %.2f, %.2f %.2f %.2f   \n\r",printtheta1motor*180/PI,printtheta2motor*180/PI,printtheta3motor*180/PI, x,y,z, theta1DH*180/PI,theta2DH*180/PI,theta3DH*180/PI,theta1M*180/PI,theta2M*180/PI,theta3M*180/PI);

}

