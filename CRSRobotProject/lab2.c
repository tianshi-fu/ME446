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

// Variables for lab 0
int statevar = 1;
int statecount = 0;

// Variables for forward kinematics
float x;
float y;
float z;

// Variables for inverse kinematics
float theta1DH;
float theta2DH;
float theta3DH;

float alpha;
float beta;
float L;

float theta1M;
float theta2M;
float theta3M;

// Velocity approximation
float Theta1_old = 0;
float Omega1_raw = 0;
float Omega1_old1 = 0;
float Omega1_old2 = 0;
float Omega1 = 0;

float Theta2_old = 0;
float Omega2_raw = 0;
float Omega2_old1 = 0;
float Omega2_old2 = 0;
float Omega2 = 0;

float Theta3_old = 0;
float Omega3_raw = 0;
float Omega3_old1 = 0;
float Omega3_old2 = 0;
float Omega3 = 0;

// Controller gains
float Kp1 = 30;
float Kp2 = 30;
float Kp3 = 30;
float Kd1 = 1.75;
float Kd2 = 1.75;
float Kd3 = 1.75;
float Ki1 = 200;
float Ki2 = 300;
float Ki3 = 300;

// Tracking error integration
float Ik1 = 0;
float Ik2 = 0;
float Ik3 = 0;
float Ik1_p = 0;
float Ik2_p = 0;
float Ik3_p = 0;
float ek1 = 0;
float ek2 = 0;
float ek3 = 0;
float ek1_p = 0;
float ek2_p = 0;
float ek3_p = 0;

// Reference motor angles
float theta1dM = 0;
float theta2dM = 0;
float theta3dM = 0;

// Temp tau values to be checked
float tau1temp = 0;
float tau2temp = 0;
float tau3temp = 0;

// Integral control threshold regions
float region1 = 0.017;
float region2 = 0.013;
float region3 = 0.013;

// Cubic trajectory position, velocity and acceleration
float theta = 0;
float theta_d = 0;
float theta_dd = 0;

// Feedforward constants
float J1 = 0.0167;
float J2 = 0.03;
float J3 = 0.0128;

// Temp time variable for feedforward
float temptime = 0;


// This function is called every 1 ms
void lab(float theta1motor,float theta2motor,float theta3motor,float *tau1,float *tau2,float *tau3, int error) {


    /**tau1 = 0;
     *tau2 = 0;
     *tau3 = 0;*/

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
// LED on/off exercise for lab 0
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

// motor angles assigned to Simulink variables
    Simulink_PlotVar1 = theta1motor;
    Simulink_PlotVar2 = theta2motor;
    Simulink_PlotVar3 = theta3motor;
//    Simulink_PlotVar4 = theta1dM; //without feedforward
    Simulink_PlotVar4 = theta;  //feedforward

// end effector's location with expressions calculated with Robotica  (forward kinimatics)
//    x = 10*cos(theta1motor)*(cos(theta3motor)+sin(theta2motor));
//    y = 10*sin(theta1motor)*(cos(theta3motor)+sin(theta2motor));
//    z = 10*(1+cos(theta2motor)-sin(theta3motor));

// Parametric equations for Viviani's  curve with offsets
    x = 3*cos(mycount*0.001)+15;
    y = 3*sin(mycount*0.001);
    z = 6*sin(mycount*0.0005) + 12;

//	geometric approach for inverse kinematics
    theta1DH = atan2(y,x);
    alpha = atan2(z-10,sqrt(x*x+y*y));
    L = sqrt((z-10)*(z-10)+x*x+y*y);
    beta = acos(L/20);
    theta2DH = -alpha - beta;
    theta3DH = 2 * beta;
	
// expressing motor angles in terms of DH angles
    theta1M = theta1DH;
    theta2M = theta2DH + PI/2;
    theta3M = theta3DH + theta2DH;

// Velocity approximation
    Omega1_raw = (theta1motor - Theta1_old)/0.001;
    Omega1 = (Omega1_raw + Omega1_old1 + Omega1_old2)/3.0;
    Theta1_old = theta1motor;    
    Omega1_old2 = Omega1_old1;
    Omega1_old1 = Omega1_raw;

    Omega2_raw = (theta2motor - Theta2_old)/0.001;
    Omega2 = (Omega2_raw + Omega2_old1 + Omega2_old2)/3.0;
    Theta2_old = theta2motor;
    Omega2_old2 = Omega2_old1;
    Omega2_old1 = Omega2_raw;

    Omega3_raw = (theta3motor - Theta3_old)/0.001;
    Omega3 = (Omega3_raw + Omega3_old1 + Omega3_old2)/3.0;
    Theta3_old = theta3motor;
    Omega3_old2 = Omega3_old1;
    Omega3_old1 = Omega3_raw;

// Squarewave reference
//    if ((mycount%1000)==0) {
//        if (theta1dM >0.25) {
//            theta1dM = 0;
//        }
//        else{
//            theta1dM = PI/6.0;
//        }
//        if (theta2dM >0.25) {
//            theta2dM = 0;
//        }
//        else{
//            theta2dM = PI/6.0;
//        }
//        if (theta3dM > 0.25) {
//            theta3dM = 0;
//        }
//        else{
//            theta3dM = PI/6;
//        }
//
//    }

//	setting desired motor angles
    theta1dM = theta1M;
    theta2dM = theta2M;
    theta3dM = theta3M;
	
// error calculation	
    ek1 = theta1dM - theta1motor;
    ek2 = theta2dM - theta2motor;
    ek3 = theta3dM - theta3motor;
	
// integral approximation with trapezoidal rule
    Ik1 = Ik1_p + (ek1_p + ek1)/2 * 0.001;
    Ik2 = Ik2_p + (ek2_p + ek2)/2 * 0.001;
    Ik3 = Ik3_p + (ek3_p + ek3)/2 * 0.001;

// threshold regions for integral control
    if (fabs(ek1)>region1){
        Ik1 = 0;
        Ik1_p = 0;
        }

    if (fabs(ek2)>region2){
           Ik2 = 0;
           Ik2_p = 0;
           }

    if (fabs(ek3)>region3){
           Ik3 = 0;
           Ik3_p = 0;
           }
		   
		   
		   
//without feedforward
	//	control law
    tau1temp = Kp1 * (theta1dM - theta1motor) - Kd1 * Omega1 + Ki1 * Ik1;
    tau2temp = Kp2 * (theta2dM - theta2motor) - Kd2 * Omega2 + Ki2 * Ik2;
    tau3temp = Kp3 * (theta3dM - theta3motor) - Kd3 * Omega3 + Ki3 * Ik3;


// torque safety check for error integration
    if(fabs(tau1temp)>5){
        Ik1 = Ik1_p;
       }
    if(fabs(tau1temp)>5){
        Ik2 = Ik2_p;
       }
    if(fabs(tau1temp)>5){
        Ik3 = Ik3_p;
       }

// setting motor torques
    *tau1 = tau1temp;
    *tau2 = tau2temp;
    *tau3 = tau3temp;

    Ik1_p = Ik1;
    Ik2_p = Ik2;
    Ik3_p = Ik3;
    ek1_p = ek1;
    ek2_p = ek2;
    ek3_p = ek3;

////feedforward
// //cubic trajectory
//    if ((mycount%2000)<=1000) {
//        temptime = mycount%2000/1000.0;
//        theta = 1.5*temptime*temptime - temptime*temptime*temptime;
//        theta_d = 3*temptime - 3*temptime*temptime;
//        theta_dd = 3 - 6*temptime;
//    }
//
//    if ((mycount%2000)>1000) {
//        temptime = mycount%2000/1000.0;
//            theta = -2 + 6*temptime - 4.5*temptime*temptime + temptime*temptime*temptime;
//            theta_d = 6 - 9*temptime + 3*temptime*temptime;
//            theta_dd = -9 + 6*temptime;
//        }
//
//		// control law
//    tau1temp = J1*theta_dd + Kp1*(theta - theta1motor) + Ki1 * Ik1 + Kd1*(theta_d - Omega1);
//    tau2temp = J2*theta_dd + Kp2*(theta - theta2motor) + Ki2 * Ik2 + Kd2*(theta_d - Omega2);
//    tau3temp = J3*theta_dd + Kp3*(theta - theta3motor) + Ki3 * Ik3 + Kd3*(theta_d - Omega3);
//
//
//
//
//// torque safety check for error integration
//        if(fabs(tau1temp)>5){
//            Ik1 = Ik1_p;
//           }
//        if(fabs(tau1temp)>5){
//            Ik2 = Ik2_p;
//           }
//        if(fabs(tau1temp)>5){
//            Ik3 = Ik3_p;
//           }
//
//
//
//
//// setting motor torques
//    *tau1 = tau1temp;
//    *tau2 = tau2temp;
//    *tau3 = tau3temp;
//
//
//        Ik1_p = Ik1;
//        Ik2_p = Ik2;
//        Ik3_p = Ik3;
//        ek1_p = ek1;
//        ek2_p = ek2;
//        ek3_p = ek3;





    mycount++;
}

void printing(void){
    serial_printf(&SerialA, "%.2f %.2f,%.2f, %.2f %.2f %.2f, %.2f %.2f %.2f, %.2f %.2f %.2f   \n\r",printtheta1motor*180/PI,printtheta2motor*180/PI,printtheta3motor*180/PI, x,y,z, theta1DH*180/PI,theta2DH*180/PI,theta3DH*180/PI,theta1M*180/PI,theta2M*180/PI,theta3M*180/PI);

}

