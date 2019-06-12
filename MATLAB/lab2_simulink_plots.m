clear
clc
close all

% simulation only
sim('qddot')


plot(tout,q1(:,2))
title('Motor 2 Simulated Position Response to Squarewave input (PD)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')

figure
plot(tout,q2(:,2))
title('Motor 3 Simulated Position Response to Squarewave input (PD)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')

figure
plot(tout,dq1(:,2))
title('Motor 2 Simulated Velocity Response to Squarewave input (PD)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')

figure
plot(tout,dq2(:,2))
title('Motor 3 Simulated Velocity Response to Squarewave input (PD)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')

figure
plot(tout,e1(:,2))
title('Motor 2 Simulated Position error (PD)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')

figure
plot(tout,e2(:,2))
title('Motor 3 Simulated Position error (PD)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')
%--------------------------------------------------------------------------

%PID without feedforward
load PID_no_feedforward
figure
plot(PID_no_feedforward(:,1),PID_no_feedforward(:,2), ...
    PID_no_feedforward(:,1),PID_no_feedforward(:,3),'--', ...
    PID_no_feedforward(:,1),PID_no_feedforward(:,4),':', ...
    PID_no_feedforward(:,1),PID_no_feedforward(:,5),'-.')
title('CRS Motor Angles with Squarewave input (PID /wo Feedforward)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')
legend({'motor1','motor2','motor3','reference'},'Location','southeast')
%error
figure
plot(PID_no_feedforward(:,1),PID_no_feedforward(:,5)-PID_no_feedforward(:,2), ...
    PID_no_feedforward(:,1),PID_no_feedforward(:,5)-PID_no_feedforward(:,3),'--', ...
    PID_no_feedforward(:,1),PID_no_feedforward(:,5)-PID_no_feedforward(:,4),':')
title('CRS Motor Errors with Squarewave input (PID /wo Feedforward)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')
legend({'motor1 error','motor2 error','motor3 error'},'Location','southeast')

%--------------------------------------------------------------------------

%PID with feedforward
load PID_feedforward
figure
plot(PID_feedforward(:,1),PID_feedforward(:,2), ...
    PID_feedforward(:,1),PID_feedforward(:,3),'--', ...
    PID_feedforward(:,1),PID_feedforward(:,4),':', ...
    PID_feedforward(:,1),PID_feedforward(:,5),'-.')
title('CRS Motor Angles with Cubic Trajectory (PID /w Feedforward)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')
legend({'motor1','motor2','motor3','reference'},'Location','southeast')
%error
figure
plot(PID_feedforward(:,1),PID_feedforward(:,5)-PID_feedforward(:,2), ...
    PID_feedforward(:,1),PID_feedforward(:,5)-PID_feedforward(:,3),'--', ...
    PID_feedforward(:,1),PID_feedforward(:,5)-PID_feedforward(:,4),':')
title('CRS Motor Errors with Cubic Trajectory (PID /wo Feedforward)')
xlabel('time(seconds)')
ylabel('amplitude(rad)')
legend({'motor1 error','motor2 error','motor3 error'},'Location','southeast')
%--------------------------------------------------------------------------

