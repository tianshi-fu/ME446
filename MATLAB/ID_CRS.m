
% guessing here due to unknown gear ratio
Imotor1 = 0.00375;
Imotor1 = Imotor1*20;

Imotor2 = 0.00375;
Imotor2 = Imotor2*10;  %guess

% center of mass of link one
lc1 = 0.125;
% Total moment of Inertia of Link one about its center of mass
Il1 = 0.0114;
ml1 = 1.3;
L1 = 10*.0254; %meters

% Total mass of link two
ml2 = 1.14;
% Center of mass of link two
lc2 = 0.157;
% Total moment of Inertia of Link Two about its center of mass
Il2 = 0.0111;

% generate the five parameters
pars(1,1) = ml1*lc1^2 + ml2*L1^2 + Il1 + Imotor1;
pars(2,1) = ml2*lc2^2 + Il2 + Imotor2;
pars(3,1) = ml2*L1*lc2;
pars(4,1) = ml1*lc1 + ml2*L1;
pars(5,1) = ml2*lc2;

% add the Torque Constant to the parameters
TorqueConst = 6.0; %N-m/UnitIN
pars = pars/TorqueConst

%for FeedForward Control
%big guess here
J1 = 0.1/TorqueConst
J2 = (Imotor1+ml1*lc1^2+ml2*L1^2+Il1)/TorqueConst
J3 = (Imotor2+Il2+ml2*lc2^2)/TorqueConst
