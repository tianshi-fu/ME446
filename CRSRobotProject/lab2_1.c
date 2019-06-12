#include <tistdtypes.h>
#include <coecsl.h>
#include "user_includes.h"
#include "math.h"

// These two offsets are only used in the main file user_CRSRobot.c  You just need to create them here and find the correct offset and then these offset will adjust the encoder readings
float offset_Enc2_rad = -0.37;
float offset_Enc3_rad = 0.27;


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
float a = 2.54;
float d1 = 2.54;
float xpos = 0;
float ypos = 0;
float zpos = 0;
float theta1DH = 0;
float theta2DH = 0;
float theta3DH = 0;
float theta1M = 0;
float theta2M = 0;
float theta3M = 0;

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

float Kp1 = 10;
float Kp2 = 10;
float Kd1 = 1;
float Kd2 = 1;

float theta2dM = 0;
float theta3dM = 0;

// This function is called every 1 ms
void lab(float theta1motor,float theta2motor,float theta3motor,float *tau1,float *tau2,float *tau3, int error) {


  /*  *tau1 = 0;
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
        GpioDataRegs.GPBTOGGLE.bit.GPIO60 = 1; // Blink LED on Emergency Stop Box
    }


    Simulink_PlotVar1 = theta1motor;
    Simulink_PlotVar2 = theta2motor;
    Simulink_PlotVar3 = theta3motor;
    Simulink_PlotVar4 = 0;

    xpos = cos(theta1motor) * (a * cos(theta3motor) + a * sin(theta2motor));
    ypos = sin(theta1motor) * (a * cos(theta3motor) + a * sin(theta2motor));
    zpos = a + a * cos(theta2motor) - a * sin(theta3motor);

    theta1DH = atan2(ypos, xpos);
    theta3DH = PI - acos(-((zpos - d1)*(zpos - d1) + xpos*xpos + ypos*ypos - 2*a*a)/(2*a*a));
    theta2DH = -theta3DH/2 - atan2((zpos - d1), sqrt(xpos*xpos + ypos*ypos));
    theta1M = theta1DH;
    theta2M = theta2DH + PI/2;
    theta3M = theta3DH + theta2M - PI/2;

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



    while ((mycount%1000)==0) {
        theta2dM = PI/6;
        theta3dM = PI/6;
        if (theta2dM == PI/6) {
            theta2dM = 0;
        }
        else{
            theta2dM = PI/6;
        }
        if (theta3dM == PI/6) {
            theta3dM = 0;
        }
        else{
            theta3dM = PI/6;
        }

    }
    *tau2 = Kp1 * (theta2dM - theta2motor) - Kd1 * Omega2;
    *tau3 = Kp2 * (theta3dM - theta3motor) - Kd2 * Omega3;




    mycount++;
}

void printing(void){
    serial_printf(&SerialA, "theta1 %.2f theta 2 %.2f theta3 %.2f x %.2f y %.2f z %.2f t1new %.2f t2new %.2f t3new %.2f \n\r",
     printtheta1motor*180/PI,printtheta2motor*180/PI,printtheta3motor*180/PI, xpos, ypos, zpos,
     theta1M*180/PI, theta2M*180/PI, theta3M*180/PI);
}

