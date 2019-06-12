clear
clc

a = 1;
t=linspace(0,4*pi,200);
x= a+a*cos(t); %parametrized Viviani's Curve
y= a*sin(t);
z = 2*a*sin(t/2);

v_curve = line(x,y,z);
view(50,20);



