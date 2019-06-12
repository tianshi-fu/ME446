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


float x=0;
float y=0;
float z=0;

float theta1DH=0;
float theta2DH=0;
float theta3DH=0;

float alpha=0;
float beta=0;
float L=0;

float theta1M=0;
float theta2M=0;
float theta3M=0;

float Theta1_old = 0;
float Omega1_raw = 0;
float Omega1_old1 = 0;
float Omega1_old2 = 0;
float Omega1 = 0;

float Theta2_old = -0.424;
float Omega2_raw = 0;
float Omega2_old1 = 0;
float Omega2_old2 = 0;
float Omega2 = 0;

float Theta3_old = 0.209;
float Omega3_raw = 0;
float Omega3_old1 = 0;
float Omega3_old2 = 0;
float Omega3 = 0;

//world frame velocity---------------------
float x_old = 0;
float Omega_x_raw = 0;
float Omega_x_old1 = 0;
float Omega_x_old2 = 0;
float Omega_x = 0;

float y_old = 0;
float Omega_y_raw = 0;
float Omega_y_old1 = 0;
float Omega_y_old2 = 0;
float Omega_y = 0;

float z_old = 0;
float Omega_z_raw = 0;
float Omega_z_old1 = 0;
float Omega_z_old2 = 0;
float Omega_z = 0;


//// lab3_1
//float KPx = 0.5;
//float KPy = 0.5;
//float KPz = 0.5;
//float KDx = 0.025;
//float KDy = 0.025;
//float KDz = 0.025;
//
//
//
//float Ik1 = 0;
//float Ik2 = 0;
//float Ik3 = 0;
//float Ik1_p = 0;
//float Ik2_p = 0;
//float Ik3_p = 0;
//float ek1 = 0;
//float ek2 = 0;
//float ek3 = 0;
//float ek1_p = 0;
//float ek2_p = 0;
//float ek3_p = 0;

float theta1dM = 0;
float theta2dM = 0;
float theta3dM = 0;

float tau1temp = 0;
float tau2temp = 0;
float tau3temp = 0;

//float region1 = 0.017;
//float region2 = 0.013;
//float region3 = 0.013;

//float theta1 = 0;
//float theta_d1 = 0;
//float theta_dd1 = 0;
//float theta2 = 0;
//float theta_d2 = 0;
//float theta_dd2 = 0;
//float theta3 = 0;
//float theta_d3 = 0;
//float theta_dd3 = 0;



//float J1 = 0.0167;
//float J2 = 0.03;
//float J3 = 0.0128;

//float temptime = 0;

float u_fric1 = 0;
float u_fric2 = 0;
float u_fric3 = 0;

float vp1 = 0.15;
float vp2 = 0.2000;
float vp3 = 0.1922;

float cp1 = 0.40;
float cp2 = 0.30;
float cp3 = 0.38;

float vn1 = 0.16;
float vn2 = 0.200;
float vn3 = 0.2132;

float cn1 = -0.38;
float cn2 = -0.30;
float cn3 = -0.38;

float fslope = 3.6;

float atheta2 = 0;
float atheta3 = 0;


////with mass
//float p1 = 0.0466;
//float p2 = 0.0388;
//float p3 = 0.0284;
//float p4 = 0.1405;
//float p5 = 0.1298;


//float D11 = 0;
//float D12 = 0;
//float D21 = 0;
//float D22 = 0;
//
//float C11 = 0;
//float C12 = 0;
//float C21 = 0;
//float C22 = 0;
//
//float G1 = 0;
//float G2 = 0;
//
//float g = 9.805;

//float costheta3 = 0;
//float sintheta32 = 0;
//float sintheta2 = 0;
//float costheta32 = 0;
//
//float flag = 0;

//float tempcount = 0;

float cosq1 = 0;
float sinq1 = 0;
float cosq2 = 0;
float sinq2 = 0;
float cosq3 = 0;
float sinq3 = 0;
float JT_11 = 0;
float JT_12 = 0;
float JT_13 = 0;
float JT_21 = 0;
float JT_22 = 0;
float JT_23 = 0;
float JT_31 = 0;
float JT_32 = 0;
float JT_33 = 0;
float cosz = 0;
float sinz = 0;
float cosx = 0;
float sinx = 0;
float cosy = 0;
float siny = 0;
float thetaz = 0;
float thetax = 0;
float thetay = 0;
float R11 = 0;
float R12 = 0;
float R13 = 0;
float R21 = 0;
float R22 = 0;
float R23 = 0;
float R31 = 0;
float R32 = 0;
float R33 = 0;
float RT11 = 0;
float RT12 = 0;
float RT13 = 0;
float RT21 = 0;
float RT22 = 0;
float RT23 = 0;
float RT31 = 0;
float RT32 = 0;
float RT33 = 0;

float xd_d = 0;
float yd_d = 0;
float zd_d = 0;

float x_d = 0;
float y_d = 0;
float z_d = 0;

float KPxn = 0.5;
float KPyn = 0.5;
float KPzn = 0.5;

float KDxn = 0.025;
float KDyn = 0.025;
float KDzn = 0.025;

float JTR11 = 0;
float JTR12 = 0;
float JTR13 = 0;
float JTR21 = 0;
float JTR22 = 0;
float JTR23 = 0;
float JTR31 = 0;
float JTR32 = 0;
float JTR33 = 0;

float RTP1 = 0;
float RTP2 = 0;
float RTP3 = 0;

float RTV1 = 0;
float RTV2 = 0;
float RTV3 = 0;

float KPRTP1 = 0;
float KPRTP2 = 0;
float KPRTP3 = 0;

float KDRTV1 = 0;
float KDRTV2 = 0;
float KDRTV3 = 0;

//float x_da = 5.66;
//float y_da = 0;
//float z_da = 17;
//float x_db = 0;
//float y_db = 0;
//float z_db = 0;
float t_total = 0;
float speed_d = 0;
float t_now = 0;
float dist = 0;

int point_n = 0;

float t_step = 0;
float t_temp = 0;

int arrive = 0;
int step = 0;
int i = 0;

float t_test = 0;


// points velocity times distance gains
float xloc[19] = {5.66,10,1.4,1.4,1.4,8.68,14.97,16.09,15.91,15.05,11.5,12.72,12.59,14.98,14.18,14.83,14.83,14.83,10};
float yloc[19] = {0,0,13.86,13.86,13.86,4.43,4.40,2.48,2.19,1.93,2.11,1.93,1.26,-1.7,-2.07,-5.52,-5.52,-5.52,0};
float zloc[19] = {17,20,7.91,4.9,8.91,9.36,8.5,8.5,8.5,8.5,8.5,8.5,8.5,8.5,15.05,15.05,13.47,15.05,20};
float spd[18] = {20,25,10,10,10,20,15,10,10,10,10,10,10,25,25,3,10,25};
float t_tot[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float dista[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


float kpxn[18] = {0.5,0.5,0.025,0.025,0.5,0.5,0.5,0.07,0.07,0.07,0.07,0.07,0.07,0.5,0.5,0.5,0.5,0.5};
float kpyn[18] = {0.5,0.5,0.025,0.025,0.5,0.5,0.08,0.07,0.07,0.07,0.07,0.07,0.07,0.5,0.5,0.5,0.5,0.5};
float kpzn[18] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
float kdxn[18] = {0.025,0.025,0.00125,0.00125,0.025,0.025,0.025,0.0035,0.0035,0.0035,0.0035,0.0035,0.0035,0.025,0.025,0.025,0.025,0.025};
float kdyn[18] = {0.025,0.025,0.00125,0.00125,0.025,0.025,0.0035,0.0035,0.0035,0.0035,0.0035,0.0035,0.0035,0.025,0.025,0.025,0.025,0.025};
float kdzn[18] = {0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025,0.025};
float calc_state = 0;
float test_time = 0;

// This function is called every 1 ms
void lab(float theta1motor,float theta2motor,float theta3motor,float *tau1,float *tau2,float *tau3, int error) {

    if(calc_state == 0){
        for(i=0; i<=17; i++){
        dista[i] = sqrt((xloc[i+1]-xloc[i])*(xloc[i+1]-xloc[i]) + (yloc[i+1]-yloc[i])*(yloc[i+1]-yloc[i]) + (zloc[i+1]-zloc[i])*(zloc[i+1]-zloc[i]));
        t_tot[i] = dista[i]/spd[i];
        }
        calc_state = 1;
    }

    // Rotation zxy and its Transpose
    cosz = cos(thetaz);
    sinz = sin(thetaz);
    cosx = cos(thetax);
    sinx = sin(thetax);
    cosy = cos(thetay);
    siny = sin(thetay);
    RT11 = R11 = cosz*cosy-sinz*sinx*siny;
    RT21 = R12 = -sinz*cosx;
    RT31 = R13 = cosz*siny+sinz*sinx*cosy;
    RT12 = R21 = sinz*cosy+cosz*sinx*siny;
    RT22 = R22 = cosz*cosx;
    RT32 = R23 = sinz*siny-cosz*sinx*cosy;
    RT13 = R31 = -cosx*siny;
    RT23 = R32 = sinx;
    RT33 = R33 = cosx*cosy;
    // Jacobian Transpose
    cosq1 = cos(theta1motor);
    sinq1 = sin(theta1motor);
    cosq2 = cos(theta2motor);
    sinq2 = sin(theta2motor);
    cosq3 = cos(theta3motor);
    sinq3 = sin(theta3motor);
    JT_11 = -10*sinq1*(cosq3 + sinq2);
    JT_12 = 10*cosq1*(cosq3 + sinq2);
    JT_13 = 0;
    JT_21 = 10*cosq1*(cosq2 - sinq3);
    JT_22 = 10*sinq1*(cosq2 - sinq3);
    JT_23 = -10*(cosq3 + sinq2);
    JT_31 = -10*cosq1*sinq3;
    JT_32 = -10*sinq1*sinq3;
    JT_33 = -10*cosq3;



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
        //GpioDataRegs.GPBTOGGLE.bit.GPIO60 = 1; // Blink LED on Emergency Stop Box
        //GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1; // Turn on LED
        //GpioDataRegs.GPBSET.bit.GPIO60 = 1; // Turn off LED


    }


    //error
    Simulink_PlotVar1 = theta1motor - theta1dM;
    Simulink_PlotVar2 = theta2motor - theta2dM;
    Simulink_PlotVar3 = theta3motor - theta3dM;
    //    Simulink_PlotVar4 = theta1dM; //without feedforward
    // Simulink_PlotVar4 = theta1dM;  //feedforward

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




    Omega1_raw = (theta1motor - Theta1_old)/0.001;
    Omega1 = (Omega1_raw + Omega1_old1 + Omega1_old2)/3.0;
    Theta1_old = theta1motor;
    Omega1_old2 = Omega1_old1;
    Omega1_old1 = Omega1;

    Omega2_raw = (theta2motor - Theta2_old)/0.001;
    Omega2 = (Omega2_raw + Omega2_old1 + Omega2_old2)/3.0;
    Theta2_old = theta2motor;
    Omega2_old2 = Omega2_old1;
    Omega2_old1 = Omega2;

    Omega3_raw = (theta3motor - Theta3_old)/0.001;
    Omega3 = (Omega3_raw + Omega3_old1 + Omega3_old2)/3.0;
    Theta3_old = theta3motor;
    Omega3_old2 = Omega3_old1;
    Omega3_old1 = Omega3;

    //world frame velocity------------------------------------------------------
    Omega_x_raw = (x - x_old)/0.001;
    Omega_x = (Omega_x_raw + Omega_x_old1 + Omega_x_old2)/3.0;
    x_old = x;
    Omega_x_old2 = Omega_x_old1;
    Omega_x_old1 = Omega_x;

    Omega_y_raw = (y - y_old)/0.001;
    Omega_y = (Omega_y_raw + Omega_y_old1 + Omega_y_old2)/3.0;
    y_old = y;
    Omega_y_old2 = Omega_y_old1;
    Omega_y_old1 = Omega_y;

    Omega_z_raw = (z - z_old)/0.001;
    Omega_z = (Omega_z_raw + Omega_z_old1 + Omega_z_old2)/3.0;
    z_old = z;
    Omega_z_old2 = Omega_z_old1;
    Omega_z_old1 = Omega_z;

    //friction
    if(Omega1>0.1){
        u_fric1 = vp1*Omega1+cp1;
    }
    else if(Omega1<-0.1){
        u_fric1 = vn1*Omega1+cn1;
    }
    else{
        u_fric1 = fslope*Omega1;
    }

    if(Omega2>0.05){
        u_fric2 = vp2*Omega2+cp2;
    }
    else if(Omega2<-0.05){
        u_fric2 = vn2*Omega2+cn2;
    }
    else{
        u_fric2 = fslope*Omega2;
    }

    if(Omega3>0.05){
        u_fric3 = vp3*Omega3+cp3;
    }
    else if(Omega3<-0.05){
        u_fric3 = vn3*Omega3+cn3;
    }
    else{
        u_fric3 = fslope*Omega3;
    }





    RTP1 = RT11*(x_d-x)+RT12*(y_d-y)+RT13*(z_d-z);
    RTP2 = RT21*(x_d-x)+RT22*(y_d-y)+RT23*(z_d-z);
    RTP3 = RT31*(x_d-x)+RT32*(y_d-y)+RT33*(z_d-z);

    KPRTP1 = KPxn*RTP1;
    KPRTP2 = KPyn*RTP2;
    KPRTP3 = KPzn*RTP3;

    RTV1 = RT11*(xd_d-Omega_x)+RT12*(yd_d-Omega_y)+RT13*(zd_d-Omega_z);
    RTV2 = RT21*(xd_d-Omega_x)+RT22*(yd_d-Omega_y)+RT23*(zd_d-Omega_z);
    RTV3 = RT31*(xd_d-Omega_x)+RT32*(yd_d-Omega_y)+RT33*(zd_d-Omega_z);

    KDRTV1 = KDxn*RTV1;
    KDRTV2 = KDyn*RTV2;
    KDRTV3 = KDzn*RTV3;

    JTR11= JT_11*R11+JT_12*R21+JT_13*R31;
    JTR12= JT_11*R12+JT_12*R22+JT_13*R32;
    JTR13= JT_11*R13+JT_12*R23+JT_13*R33;
    JTR21= JT_21*R11+JT_22*R21+JT_23*R31;
    JTR22= JT_21*R12+JT_22*R22+JT_23*R32;
    JTR23= JT_21*R13+JT_22*R23+JT_23*R33;
    JTR31= JT_31*R11+JT_32*R21+JT_33*R31;
    JTR32= JT_31*R12+JT_32*R22+JT_33*R32;
    JTR33= JT_31*R13+JT_32*R23+JT_33*R33;

    tau1temp = (JTR11*(KPRTP1+KDRTV1)+JTR12*(KPRTP2+KDRTV2)+JTR13*(KPRTP3+KDRTV3)) + 0.5*u_fric1;
    tau2temp = (JTR21*(KPRTP1+KDRTV1)+JTR22*(KPRTP2+KDRTV2)+JTR23*(KPRTP3+KDRTV3)) + 0.5*u_fric2;
    tau3temp = (JTR31*(KPRTP1+KDRTV1)+JTR32*(KPRTP2+KDRTV2)+JTR33*(KPRTP3+KDRTV3)) + 0.5*u_fric3;


    if(tau1temp>5){
        tau1temp = 5;
    }
    if(tau2temp>5){
        tau2temp = 5;
    }
    if(tau3temp>5){
        tau3temp = 5;
    }

    if(tau1temp<-5){
        tau1temp = -5;
    }
    if(tau2temp<-5) {
        tau2temp = -5;
    }
    if(tau3temp<-5){
        tau3temp = -5;
    }



    *tau1 = tau1temp;
    *tau2 = tau2temp;
    *tau3 = tau3temp;


    t_now = mycount/1000.0;
    //home2zero
    if(0<t_now && t_now<t_tot[0]){
        step = 1;
    }
    if(fabs(t_now-t_tot[0])<0.1){
        step = 2;
    }
    //zero2toh
    if(t_tot[0]<t_now && t_now<(t_tot[0]+t_tot[1])){
        step = 3;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1])<0.1){
        step = 4;
    }
    //toh2boh
    if((t_tot[0]+t_tot[1])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2])){
        step = 5;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2])<0.1){
        step = 6;
    }
    //boh2toh
    if((t_tot[0]+t_tot[1]+t_tot[2])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3])){
        step = 7;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3])<0.1){
        step = 8;
    }
    //toh2miz1
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4])){
        step = 9;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4])<0.1){
        step = 10;
    }
    //toh2miz2
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5])){
        step = 11;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5])<0.1){
        step = 12;
    }
    //som2seg1
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6])){
        step = 13;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6])<0.1){
        step = 14;
    }
    //seg12seg2
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7])){
        step = 15;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7])<0.1){
        step = 16;
    }
    //seg22seg3
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8])){
        step = 17;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8])<0.1){
        step = 18;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9])){
        step = 19;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9])<0.1){
        step = 20;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10])){
        step = 21;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10])<0.1){
        step = 22;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11])){
        step = 23;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11])<0.1){
        step = 24;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12])){
        step = 25;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12])<0.1){
        step = 26;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13])){
        step = 27;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13])<0.1){
        step = 28;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14])){
        step = 29;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14])<0.1){
        step = 30;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14]+t_tot[15])){
        step = 31;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15])<0.1){
        step = 32;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14]+t_tot[15])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14]+t_tot[15]+t_tot[16])){
        step = 33;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15]-t_tot[16])<0.1){
        step = 34;
    }
    //seg32seg4
    if((t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14]+t_tot[15]+t_tot[16])<t_now && t_now<(t_tot[0]+t_tot[1]+t_tot[2]+t_tot[3]+t_tot[4]+t_tot[5]+t_tot[6]+t_tot[7]+t_tot[8]+t_tot[9]+t_tot[10]+t_tot[11]+t_tot[12]+t_tot[13]+t_tot[14]+t_tot[15]+t_tot[16]+t_tot[17])){
        step = 35;
    }
    if(fabs(t_now-t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15]-t_tot[16]-t_tot[17])<0.1){
        step = 36;
    }


    switch(step){
    case 1:
        KPxn = kpxn[0];
        KPyn = kpyn[0];
        KPzn = kpzn[0];
        KDxn = kdxn[0];
        KDyn = kdyn[0];
        KDzn = kdzn[0];
        x_d = (xloc[1]-xloc[0]) * (t_now - 0)/t_tot[0] + xloc[0];
        y_d = (yloc[1]-yloc[0]) * (t_now - 0)/t_tot[0] + yloc[0];
        z_d = (zloc[1]-zloc[0]) * (t_now - 0)/t_tot[0] + zloc[0];
        xd_d = (xloc[1]-xloc[0])/t_tot[0];
        yd_d = (yloc[1]-yloc[0])/t_tot[0];
        zd_d = (zloc[1]-zloc[0])/t_tot[0];
        break;
    case 2:
        x_d = xloc[1];
        y_d = yloc[1];
        z_d = zloc[1];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 3:
        KPxn = kpxn[1];
        KPyn = kpyn[1];
        KPzn = kpzn[1];
        KDxn = kdxn[1];
        KDyn = kdyn[1];
        KDzn = kdzn[1];
        x_d = (xloc[2]-xloc[1]) * (t_now - t_tot[0])/t_tot[1] + xloc[1];
        y_d = (yloc[2]-yloc[1]) * (t_now - t_tot[0])/t_tot[1] + yloc[1];
        z_d = (zloc[2]-zloc[1]) * (t_now - t_tot[0])/t_tot[1] + zloc[1];
        xd_d = (xloc[2]-xloc[1])/t_tot[1];
        yd_d = (yloc[2]-yloc[1])/t_tot[1];
        zd_d = (zloc[2]-zloc[1])/t_tot[1];
        break;
    case 4:
        x_d = xloc[2];
        y_d = yloc[2];
        z_d = zloc[2];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 5:
        KPxn = kpxn[2];
        KPyn = kpyn[2];
        KPzn = kpzn[2];
        KDxn = kdxn[2];
        KDyn = kdyn[2];
        KDzn = kdzn[2];
        x_d = (xloc[3]-xloc[2]) * (t_now - t_tot[0]-t_tot[1])/t_tot[2] + xloc[2];
        y_d = (yloc[3]-yloc[2]) * (t_now - t_tot[0]-t_tot[1])/t_tot[2] + yloc[2];
        z_d = (zloc[3]-zloc[2]) * (t_now - t_tot[0]-t_tot[1])/t_tot[2] + zloc[2];
        xd_d = (xloc[3]-xloc[2])/t_tot[2];
        yd_d = (yloc[3]-yloc[2])/t_tot[2];
        zd_d = (zloc[3]-zloc[2])/t_tot[2];
        break;
    case 6:
        x_d = xloc[3];
        y_d = yloc[3];
        z_d = zloc[3];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 7:
        KPxn = kpxn[3];
        KPyn = kpyn[3];
        KPzn = kpzn[3];
        KDxn = kdxn[3];
        KDyn = kdyn[3];
        KDzn = kdzn[3];
        x_d = (xloc[4]-xloc[3]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2])/t_tot[3] + xloc[3];
        y_d = (yloc[4]-yloc[3]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2])/t_tot[3] + yloc[3];
        z_d = (zloc[4]-zloc[3]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2])/t_tot[3] + zloc[3];
        xd_d = (xloc[4]-xloc[3])/t_tot[3];
        yd_d = (yloc[4]-yloc[3])/t_tot[3];
        zd_d = (zloc[4]-zloc[3])/t_tot[3];
        break;
    case 8:
        x_d = xloc[4];
        y_d = yloc[4];
        z_d = zloc[4];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 9:
        KPxn = kpxn[4];
        KPyn = kpyn[4];
        KPzn = kpzn[4];
        KDxn = kdxn[4];
        KDyn = kdyn[4];
        KDzn = kdzn[4];
        x_d = (xloc[5]-xloc[4]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3])/t_tot[4] + xloc[4];
        y_d = (yloc[5]-yloc[4]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3])/t_tot[4] + yloc[4];
        z_d = (zloc[5]-zloc[4]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3])/t_tot[4] + zloc[4];
        xd_d = (xloc[5]-xloc[4])/t_tot[4];
        yd_d = (yloc[5]-yloc[4])/t_tot[4];
        zd_d = (zloc[5]-zloc[4])/t_tot[4];
        break;
    case 10:
        x_d = xloc[5];
        y_d = yloc[5];
        z_d = zloc[5];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 11:
        KPxn = kpxn[5];
        KPyn = kpyn[5];
        KPzn = kpzn[5];
        KDxn = kdxn[5];
        KDyn = kdyn[5];
        KDzn = kdzn[5];
        x_d = (xloc[6]-xloc[5]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4])/t_tot[5] + xloc[5];
        y_d = (yloc[6]-yloc[5]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4])/t_tot[5] + yloc[5];
        z_d = (zloc[6]-zloc[5]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4])/t_tot[5] + zloc[5];
        xd_d = (xloc[6]-xloc[5])/t_tot[5];
        yd_d = (yloc[6]-yloc[5])/t_tot[5];
        zd_d = (zloc[6]-zloc[5])/t_tot[5];
        break;
    case 12:
        x_d = xloc[6];
        y_d = yloc[6];
        z_d = zloc[6];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 13:
        thetaz = (90-36.87)*PI/180;
        KPxn = kpxn[6];
        KPyn = kpyn[6];
        KPzn = kpzn[6];
        KDxn = kdxn[6];
        KDyn = kdyn[6];
        KDzn = kdzn[6];
        x_d = (xloc[7]-xloc[6]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5])/t_tot[6] + xloc[6];
        y_d = (yloc[7]-yloc[6]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5])/t_tot[6] + yloc[6];
        z_d = (zloc[7]-zloc[6]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5])/t_tot[6] + zloc[6];
        xd_d = (xloc[7]-xloc[6])/t_tot[6];
        yd_d = (yloc[7]-yloc[6])/t_tot[6];
        zd_d = (zloc[7]-zloc[6])/t_tot[6];
        break;
    case 14:
        x_d = xloc[7];
        y_d = yloc[7];
        z_d = zloc[7];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 15:
        thetaz = (-36.87)*PI/180;
        KPxn = kpxn[7];
        KPyn = kpyn[7];
        KPzn = kpzn[7];
        KDxn = kdxn[7];
        KDyn = kdyn[7];
        KDzn = kdzn[7];
        x_d = (xloc[8]-xloc[7]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6])/t_tot[7] + xloc[7];
        y_d = (yloc[8]-yloc[7]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6])/t_tot[7] + yloc[7];
        z_d = (zloc[8]-zloc[7]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6])/t_tot[7] + zloc[7];
        xd_d = (xloc[8]-xloc[7])/t_tot[7];
        yd_d = (yloc[8]-yloc[7])/t_tot[7];
        zd_d = (zloc[8]-zloc[7])/t_tot[7];
        break;
    case 16:
        x_d = xloc[8];
        y_d = yloc[8];
        z_d = zloc[8];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 17:
        thetaz = (90-36.87-15)*PI/180;
        KPxn = kpxn[8];
        KPyn = kpyn[8];
        KPzn = kpzn[8];
        KDxn = kdxn[8];
        KDyn = kdyn[8];
        KDzn = kdzn[8];
        x_d = (xloc[9]-xloc[8]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7])/t_tot[8] + xloc[8];
        y_d = (yloc[9]-yloc[8]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7])/t_tot[8] + yloc[8];
        z_d = (zloc[9]-zloc[8]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7])/t_tot[8] + zloc[8];
        xd_d = (xloc[9]-xloc[8])/t_tot[8];
        yd_d = (yloc[9]-yloc[8])/t_tot[8];
        zd_d = (zloc[9]-zloc[8])/t_tot[8];
        break;
    case 18:
        x_d = xloc[9];
        y_d = yloc[9];
        z_d = zloc[9];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 19:
        thetaz = (90-36.87)*PI/180;
        KPxn = kpxn[9];
        KPyn = kpyn[9];
        KPzn = kpzn[9];
        KDxn = kdxn[9];
        KDyn = kdyn[9];
        KDzn = kdzn[9];
        x_d = (xloc[10]-xloc[9]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8])/t_tot[9] + xloc[9];
        y_d = (yloc[10]-yloc[9]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8])/t_tot[9] + yloc[9];
        z_d = (zloc[10]-zloc[9]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8])/t_tot[9] + zloc[9];
        xd_d = (xloc[10]-xloc[9])/t_tot[9];
        yd_d = (yloc[10]-yloc[9])/t_tot[9];
        zd_d = (zloc[10]-zloc[9])/t_tot[9];
        break;
    case 20:
        x_d = xloc[10];
        y_d = yloc[10];
        z_d = zloc[10];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 21:
        thetaz = (-36.87)*PI/180;
        KPxn = kpxn[10];
        KPyn = kpyn[10];
        KPzn = kpzn[10];
        KDxn = kdxn[10];
        KDyn = kdyn[10];
        KDzn = kdzn[10];
        x_d = (xloc[11]-xloc[10]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9])/t_tot[10] + xloc[10];
        y_d = (yloc[11]-yloc[10]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9])/t_tot[10] + yloc[10];
        z_d = (zloc[11]-zloc[10]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9])/t_tot[10] + zloc[10];
        xd_d = (xloc[11]-xloc[10])/t_tot[10];
        yd_d = (yloc[11]-yloc[10])/t_tot[10];
        zd_d = (zloc[11]-zloc[10])/t_tot[10];
        break;
    case 22:
        x_d = xloc[11];
        y_d = yloc[11];
        z_d = zloc[11];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 23:
        thetaz = (90-36.87)*PI/180;
        KPxn = kpxn[11];
        KPyn = kpyn[11];
        KPzn = kpzn[11];
        KDxn = kdxn[11];
        KDyn = kdyn[11];
        KDzn = kdzn[11];
        x_d = (xloc[12]-xloc[11]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10])/t_tot[11] + xloc[11];
        y_d = (yloc[12]-yloc[11]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10])/t_tot[11] + yloc[11];
        z_d = (zloc[12]-zloc[11]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10])/t_tot[11] + zloc[11];
        xd_d = (xloc[12]-xloc[11])/t_tot[11];
        yd_d = (yloc[12]-yloc[11])/t_tot[11];
        zd_d = (zloc[12]-zloc[11])/t_tot[11];
        break;
    case 24:
        x_d = xloc[12];
        y_d = yloc[12];
        z_d = zloc[12];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 25:
        thetaz = (90-36.87)*PI/180;
        KPxn = kpxn[12];
        KPyn = kpyn[12];
        KPzn = kpzn[12];
        KDxn = kdxn[12];
        KDyn = kdyn[12];
        KDzn = kdzn[12];
        x_d = (xloc[13]-xloc[12]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11])/t_tot[12] + xloc[12];
        y_d = (yloc[13]-yloc[12]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11])/t_tot[12] + yloc[12];
        z_d = (zloc[13]-zloc[12]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11])/t_tot[12] + zloc[12];
        xd_d = (xloc[13]-xloc[12])/t_tot[12];
        yd_d = (yloc[13]-yloc[12])/t_tot[12];
        zd_d = (zloc[13]-zloc[12])/t_tot[12];
        break;
    case 26:
        x_d = xloc[13];
        y_d = yloc[13];
        z_d = zloc[13];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 27:
        KPxn = kpxn[13];
        KPyn = kpyn[13];
        KPzn = kpzn[13];
        KDxn = kdxn[13];
        KDyn = kdyn[13];
        KDzn = kdzn[13];
        x_d = (xloc[14]-xloc[13]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12])/t_tot[13] + xloc[13];
        y_d = (yloc[14]-yloc[13]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12])/t_tot[13] + yloc[13];
        z_d = (zloc[14]-zloc[13]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12])/t_tot[13] + zloc[13];
        xd_d = (xloc[14]-xloc[13])/t_tot[13];
        yd_d = (yloc[14]-yloc[13])/t_tot[13];
        zd_d = (zloc[14]-zloc[13])/t_tot[13];
        break;
    case 28:
        x_d = xloc[14];
        y_d = yloc[14];
        z_d = zloc[14];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 29:
        KPxn = kpxn[14];
        KPyn = kpyn[14];
        KPzn = kpzn[14];
        KDxn = kdxn[14];
        KDyn = kdyn[14];
        KDzn = kdzn[14];
        x_d = (xloc[15]-xloc[14]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13])/t_tot[14] + xloc[14];
        y_d = (yloc[15]-yloc[14]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13])/t_tot[14] + yloc[14];
        z_d = (zloc[15]-zloc[14]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13])/t_tot[14] + zloc[14];
        xd_d = (xloc[15]-xloc[14])/t_tot[14];
        yd_d = (yloc[15]-yloc[14])/t_tot[14];
        zd_d = (zloc[15]-zloc[14])/t_tot[14];
        break;
    case 30:
        x_d = xloc[15];
        y_d = yloc[15];
        z_d = zloc[15];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 31:
        KPxn = kpxn[15];
        KPyn = kpyn[15];
        KPzn = kpzn[15];
        KDxn = kdxn[15];
        KDyn = kdyn[15];
        KDzn = kdzn[15];
        x_d = (xloc[16]-xloc[15]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14])/t_tot[15] + xloc[15];
        y_d = (yloc[16]-yloc[15]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14])/t_tot[15] + yloc[15];
        z_d = (zloc[16]-zloc[15]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14])/t_tot[15] + zloc[15];
        xd_d = (xloc[16]-xloc[15])/t_tot[15];
        yd_d = (yloc[16]-yloc[15])/t_tot[15];
        zd_d = (zloc[16]-zloc[15])/t_tot[15];
        break;
    case 32:
        x_d = xloc[16];
        y_d = yloc[16];
        z_d = zloc[16];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 33:
        KPxn = kpxn[16];
        KPyn = kpyn[16];
        KPzn = kpzn[16];
        KDxn = kdxn[16];
        KDyn = kdyn[16];
        KDzn = kdzn[16];
        x_d = (xloc[17]-xloc[16]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15])/t_tot[16] + xloc[16];
        y_d = (yloc[17]-yloc[16]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15])/t_tot[16] + yloc[16];
        z_d = (zloc[17]-zloc[16]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15])/t_tot[16] + zloc[16];
        xd_d = (xloc[17]-xloc[16])/t_tot[16];
        yd_d = (yloc[17]-yloc[16])/t_tot[16];
        zd_d = (zloc[17]-zloc[16])/t_tot[16];
        break;
    case 34:
        x_d = xloc[17];
        y_d = yloc[17];
        z_d = zloc[17];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;
    case 35:
        KPxn = kpxn[17];
        KPyn = kpyn[17];
        KPzn = kpzn[17];
        KDxn = kdxn[17];
        KDyn = kdyn[17];
        KDzn = kdzn[17];
        x_d = (xloc[18]-xloc[17]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15]-t_tot[16])/t_tot[17] + xloc[17];
        y_d = (yloc[18]-yloc[17]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15]-t_tot[16])/t_tot[17] + yloc[17];
        z_d = (zloc[18]-zloc[17]) * (t_now - t_tot[0]-t_tot[1]-t_tot[2]-t_tot[3]-t_tot[4]-t_tot[5]-t_tot[6]-t_tot[7]-t_tot[8]-t_tot[9]-t_tot[10]-t_tot[11]-t_tot[12]-t_tot[13]-t_tot[14]-t_tot[15]-t_tot[16])/t_tot[17] + zloc[17];
        xd_d = (xloc[18]-xloc[17])/t_tot[17];
        yd_d = (yloc[18]-yloc[17])/t_tot[17];
        zd_d = (zloc[18]-zloc[17])/t_tot[17];
        break;
    case 36:
        x_d = xloc[18];
        y_d = yloc[18];
        z_d = zloc[18];
        xd_d = 0;
        yd_d = 0;
        zd_d = 0;
        break;

    }















    mycount++;
}

void printing(void){
    serial_printf(&SerialA, "%.2f %.2f,%.2f, %.2f %.2f %.2f, %.2f %.2f %.2f, %.2f %.2f %.2f   \n\r",printtheta1motor*180/PI,printtheta2motor*180/PI,printtheta3motor*180/PI, x,y,z, theta1DH*180/PI,theta2DH*180/PI,theta3DH*180/PI,theta1M*180/PI,theta2M*180/PI,theta3M*180/PI);

}

