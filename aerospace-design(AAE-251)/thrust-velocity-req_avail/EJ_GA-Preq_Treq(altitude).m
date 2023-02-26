% AAE 251 Fall 2022
% Homework 09
% Title of the code: GA and EV thrust and power 
% This program uses inputs from an executive jet and general aviation aircraft 
% to calculate and plot their required power and thrust, and available power 
% and thrust from sea level to 30,000 meters.

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

EJ_full_mass = 31100; % executive jet mass with full tank (kg)
EJ_K = .05; % oswald aspect ratio coefficient (unitless)
EJ_CD0 = .015; % parasitic drag coefficient (unitless)
EJ_SA = 88.2; % executive jet surface area (m^2)
max_thrust = 55620;

GA_full_mass = 1315; % general aviation mass with full tank (kg)
GA_K = .054; % general aviation oswald aspect ratio coefficient (unitless)
GA_CD0 = .026; % general aviation parasitic drag coefficient (unitless)
GA_SA = 16.3; % general aviation surface area (m^2) 
max_power = 216000;
prop_efficiency = .8;

AD = 0.6;
throttle_setting = 1;
G = 9.81; % gravitational acceleration
H1 = 0; % sea level height
T1 = 288.16; % sea level temperature
A = -6.5e-3; % change in temperature constant for first altitude layer
rho1 = 1.225; % sea level density
R = 287; % gas constant
P1 = 1.01325e5; % sea level pressure

% create empty arrays
Pmin = zeros(1,301); % min power array
Pavail = zeros(1,301); % available power array
Tmin = zeros(1,301); % minimum thrust array
Tavail = zeros(1,301); % available thrust array
densities_si = zeros(1,301); % densities array
altitudes_si = zeros(1,301); % altitudes array

%% ____________________
%% CALCULATIONS

i = 1; % index for storing calculations in vectors
for h = 0:100:30000
    Pmin(i) = h;
    if h <= 11000 % calculations for first altitude segment
        temp = T1 + A *(h - H1); % calculate temperature
        pressure = P1 * (temp / T1)^(-G/(A * R)); % calculate pressure
        density = rho1 * (temp / T1)^-(G /(A * R) + 1); % calculate density
        densities_si(i) = density; % store density in vector
        Pmin(i) = 4/3 * sqrt(2 * (GA_full_mass * G)^3 / (densities_si(i) * GA_SA) * (sqrt(3 * GA_K^3 * GA_CD0))); % calculate minimum power
        Tmin(i) = 2 * EJ_full_mass * G * sqrt(EJ_K * EJ_CD0); % calculate minimum thrust
        Pavail(i) = max_power * prop_efficiency * (densities_si(i) / 1.225)^AD; % calculate available power
        Tavail(i) = max_thrust * throttle_setting * (densities_si(i) / 1.225)^AD; % calculate available thrust

        if h == 11000 % change reference numbers for calculations in next altitude section
            H1 = h;
            T1 = temp;
            P1 = pressure;
            rho1 = density;
        end

    elseif h >= 11100 && h <= 25000 % calculations for second altitude segment (constant temp)
        temp = T1; % calculate temperature (constant in this case)
        pressure = P1 * exp(-(G / (R * temp) * (h - H1))); % calculate pressure
        density = rho1 * pressure / P1; % calculate density
        densities_si(i) = density; % store density in vector
        Pmin(i) = 4/3 * sqrt(2 * (GA_full_mass * G)^3 / (densities_si(i) * GA_SA) * (sqrt(3 * GA_K^3 * GA_CD0))); % calculate minimum power
        Tmin(i) = 2 * EJ_full_mass * G * sqrt(EJ_K * EJ_CD0); % calculate minimum thrust
        Pavail(i) = max_power * prop_efficiency * (densities_si(i) / 1.225)^AD; % calculate available power
        Tavail(i) = max_thrust * throttle_setting * (densities_si(i) / 1.225)^AD; % calculate available thrust

        if h == 25000 % change reference numbers for calculations in next altitude section
            H1 = h;
            T1 = temp;
            rho1 = density;
            A = 3e-3;
        end

    elseif h > 25000 && h <= 30000 % calculations for last altitude segment
        temp = T1 + A*(h - H1); % calculate temperature   
        density = rho1 * (temp / T1)^-(G /(A * R) + 1); % calculate density
        densities_si(i) = density; % store density in vector
        Pmin(i) = 4/3 * sqrt(2 * (GA_full_mass * G)^3 / (densities_si(i) * GA_SA) * (sqrt(3 * GA_K^3 * GA_CD0))); % calculate minimum power
        Tmin(i) = 2 * EJ_full_mass * G * sqrt(EJ_K * EJ_CD0); % calculate minimum thrust
        Pavail(i) = max_power * prop_efficiency * (densities_si(i) / 1.225)^AD; % calculate available power
        Tavail(i) = max_thrust * throttle_setting * (densities_si(i) / 1.225)^AD; % calculate available thrust
    end

altitudes_si(i) = h / 1000; % convert altitudes from m to km

i = i + 1; % add index so values get stored in unique locations

end

%% ____________________
%% PLOT FIGURES

figure(1)
hold on
plot(Pmin,altitudes_si)
plot(Pavail,altitudes_si)
title('Minimum power and available power related to altitude')
legend('Minimum power required vs altitude','Power available vs altitude','Location','best')
ylabel('Altitude (km)')
xlabel('Power available (W)')

figure(2)
hold on
plot(Tmin,altitudes_si)
plot(Tavail,altitudes_si)
title('Minimum thrust and available thrust related to altitude')
legend('Minimum thrust required vs altitude','Thrust available vs altitude','Location','best')
ylabel('Altitude (km)')
xlabel('Thrust (N)')

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
