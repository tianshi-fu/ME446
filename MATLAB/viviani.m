clear
clc
close all

a = 1; %radius


%sphere
s1 = linspace(0,pi,40); 
s2 = linspace(0,2*pi,50); 
[s1,s2] = meshgrid(s1,s2);
sx=2*a*sin(s1).*cos(s2);
sy=2*a*sin(s1).*sin(s2);
sz=2*a*cos(s1);
%Plotting the sphere:
sphere=mesh(sx, sy, sz);
set(sphere,'EdgeColor',[0,0,0.5]) 
axis equal 
axis on 


%cylinder
c1=linspace(0,2*pi,50); 
cz=linspace(-2*a,2*a,30); 
[c1,cz]=meshgrid(c1,cz); 
cx=a+a*cos(c1);
cy=a*sin(c1);
cz = 1*cz;
hold on 
cylinder=mesh(cx, cy, cz); 
set(cylinder,'EdgeColor',[0.8,0,0]) 


%Vivani's curve

t=linspace(0,4*pi,200);

x= a+a*cos(t);
y= a*sin(t);
z = 2*a*sin(t/2);

v_curve = line(x,y,z,'Color', [0,0.9,0],'LineWidth',3);
view(50,20);
title('Viviani''s curve')

