clear
clc
close all

theta=[];
theta_d=[];
theta_dd=[];
for t = 0:2000
   [temp, temp2, temp3] = thetas(t/1000);
   theta =[theta;temp];
   theta_d =[theta_d;temp2];
   theta_dd =[theta_dd;temp3];
end

time = [0:0.001:2];

plot(time,theta)
figure
plot(time,theta_d)
figure
plot(time,theta_dd)





