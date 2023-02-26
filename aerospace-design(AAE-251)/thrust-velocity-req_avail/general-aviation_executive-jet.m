% AAE 251 Fall 2022
% Homework 08
% Title of the code: 

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

% executive jet parameters
EJ_full_mass = 31100; % executive jet mass with full tank (kg)
EJ_fuel_mass = 12700; % executive jet fuel mass (kg)  
EJ_SA = 88.2; % executive jet fuel mass (kg) 
EJ_velocities = linspace(55,333); % create array of velocities (m/s)
EJ_Mad = 0.6; % executive jet air density exponent (unitless)
EJ_C = 19.3; % executive jet TSFC (g/s.kN)
T0max = 55620; % executive jet max sea level thrust (N)
EJ_K = .05; % oswald aspect ratio coefficient (unitless)
EJ_CD0 = .015; % parasitic drag coefficient (unitless)

% general aviation parameters
GA_full_mass = 1315; % general aviation mass with full tank (kg)
GA_fuel_mass = 168; % general aviation fuel mass (kg)  
GA_SA = 16.3; % general aviation fuel mass (kg) 
GA_velocities = linspace(22,155); % create array of velocities (m/s)
GA_Mad = 0.6; % general aviation air density exponent (unitless)
GA_C = .076; % general aviation PSFC (g/s.kW)
P0max = 216; % general aviation max sea level power (KW)
H = 0.8; % general aviation propeller efficiency (unitless)
GA_K = .054; % general aviation oswald aspect ratio coefficient (unitless)
GA_CD0 = .026; % general aviation parasitic drag coefficient (unitless)

% parameters for both aircraft
rho = 1.225; % reference density (kg/m^3)
rho0 = 1.225; % sea level density (kg/m^3)
G = 9.81; % gravitational acceleration (m/s^2)

%% ____________________
%% CALCULATE LIFT AND DRAG

[EJ_lifts,EJ_drags,EJ_CLS,EJ_CDS,GA_lifts,GA_drags,GA_CLS,GA_CDS] = LD_function(rho,G,EJ_SA,EJ_velocities,EJ_full_mass,GA_SA,GA_velocities,GA_full_mass);

%% ____________________
%% CALCULATE AVAILABLE THRUST

EJ_T_avail = T_available(rho,rho0,EJ_Mad,EJ_C,T0max);

%% ____________________
%% CALCULATE AVAILABLE POWER

GA_P_avail = P_available(rho,rho0,GA_Mad,GA_C,P0max,H);

%% ____________________
%% CALCULATE REQUIRED THRUST

[T_req_EJ,T_req_GA] = T_required(G,rho,EJ_full_mass,GA_full_mass,EJ_K,GA_SA,EJ_SA,GA_K,EJ_velocities,GA_velocities,EJ_CD0,GA_CD0);

%% ____________________
%% CALCULATE REQUIRED POWER

[P_req_EJ,P_req_GA] = P_required(G,rho,EJ_full_mass,GA_full_mass,EJ_K,GA_SA,EJ_SA,GA_K,EJ_velocities,GA_velocities,EJ_CD0,GA_CD0);


%% ____________________
%% PLOT FIGURES

figure(1)
plot(GA_velocities,T_req_GA,'k-')
grid on
title('Required thrust versus airspeed for a GA aircraft')
xlabel('airspeed (m/s)')
ylabel('required thrust (N)')

figure(2)
plot(EJ_velocities,T_req_EJ,'k-')
grid on
title('Required thrust versus airspeed for an EJ aircraft')
xlabel('airspeed (m/s)')
ylabel('required thrust (N)')

figure(3)
plot(GA_velocities,P_req_GA,'k-')
grid on
title('Rrequired power versus airspeed for a GA aircraft')
xlabel('airspeed (m/s)')
ylabel('required power (W)')

figure(4)
plot(EJ_velocities,P_req_EJ,'k-')
grid on
title('Required power versus airspeed for an EJ aircraft')
xlabel('airspeed (m/s)')
ylabel('required power (W)')

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
