% AAE 251 Fall 2022
% Homework 01
% Title of the code: model of altitude vs temperature, 
% pressure, density, and speed of sound in the troposphere
% and mid stratosphere

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

% I will be using geometric altitude and not geopotential because under
% altitude of 65km which occurs in this program, the difference is greater
% than one percent

% create constants for important calculations
G = 9.8; % gravitational acceleration
H1 = 0; % sea level height
T1 = 288.16; % sea level temperature
A = -6.5e-3; % change in temperature constant for first altitude layer
P1 = 1.01325e5; % sea level pressure
rho1 = 1.225; % sea level density
R = 287; % first gas constant 
gamma = 1.4; % adiabatic constant
R2 = 8.314462; % second gas constant
M = .02897; % air molar mass

% create vectors full of zeroes to later store calculations in 
temperatures_si = zeros(1,305);
pressures_si = zeros(1,305);
densities_si = zeros(1,305);
speeds_si = zeros(1,305);
altitudes_si = zeros(1,305);

%% ____________________
%% CALCULATIONs

% for loop for calculations at height increments of 100
i = 1; % index for storing calculations in vectors
for h = 0:100:30500
    if h <= 11000 % calculations for first altitude segment
        temp = T1 + A *(h - H1); % calculate temperature
        temperatures_si(i) = temp; % store temperature in vector
        pressure = P1 * (temp / T1)^(-G/(A * R)); % calculate pressure
        pressures_si(i) = pressure; % store pressure in vector
        density = rho1 * (temp / T1)^-(G /(A * R) + 1); % calculate density
        densities_si(i) = density; % store density in vector
        speed = sqrt((gamma * R2 * temp) / M); % calculate speed of sound
        speeds_si(i) = speed; % store speed of sound in vector
        
        if h == 11000 % change reference numbers for calculations in next altitude section
            H1 = h;
            T1 = temp;
            P1 = pressure;
            disp(P1)
            rho1 = density;
        end

    elseif h >= 11100 && h <= 25000 % calculations for second altitude segment (constant temp)
        temp = T1; % calculate temperature (constant in this case)
        temperatures_si(i) = temp; % store temperature in vector
        pressure = P1 * exp(-(G / (R * temp) * (h - H1))); % calculate pressure
        pressures_si(i) = pressure; % store pressure in vector
        density = rho1 * pressure / P1; % calculate density
        densities_si(i) = density; % store density in vector
        speed = sqrt((gamma * R2 * temp) / M); % calculate speed of sound
        speeds_si(i) = speed; % store speed of sound in vector

        if h == 25000 % change reference numbers for calculations in next altitude section
            H1 = h;
            T1 = temp;
            P1 = pressure;
            rho1 = density;
            A = 3e-3;
        end

    elseif h > 25000 && h <= 30500 % calculations for last altitude segment
        temp = T1 + A*(h - H1); % calculate temperature
        temperatures_si(i) = temp; % store temperature in vector
        pressure = P1 * (temp / T1)^(-G/(A * R)); % calculate pressure
        pressures_si(i) = pressure; % store pressure in vector
        density = rho1 * (temp / T1)^-(G /(A * R) + 1); % calculate density
        densities_si(i) = density; % store density in vector
        speed = sqrt((gamma * R2 * temp) / M); % calculate speed of sound
        speeds_si(i) = speed; % store speed of sound in vector

    end

altitudes_si(i) = h / 1000; % convert altitudes from m to km
i = i + 1; % add index so values get stored in unique locations

end

% create imperial vectors using conversions from SI units
temperatures_im = 1.8 * temperatures_si;
pressures_im = pressures_si / 47.880172;
densities_im = densities_si / 515.378819;
altitudes_im = altitudes_si / 1.609344;
speeds_im = speeds_si * 3.28084;

%% ____________________
%% FIGURE 1

% plot SI units figure

figure(1)

subplot(2,2,1);
plot(temperatures_si,altitudes_si,'k-');
axis([200 300 0 35])
title('Temperature change over altitude');
xlabel('temperature (k)');
ylabel('altitude (km)');

grid on

subplot(2,2,2);
plot(pressures_si,altitudes_si,'k-');
axis([0 130000 0 35])
title('Air pressure change over altitude');
xlabel('pressure (N/m^2)');
ylabel('altitude (km)');

grid on

subplot(2,2,3);
plot(densities_si,altitudes_si,'k-');
axis([0 1.5 0 35])
title('Air density change over altitude');
xlabel('density (kg/m^3)');
ylabel('altitude (km)');

grid on

subplot(2,2,4);
plot(speeds_si,altitudes_si,'k-');
axis([280 350 0 35])
title('Speed of sound change over altitude');
xlabel('velocity (m/s)');
ylabel('altitude (km)');

grid on

sgtitle('Atmospheric model in SI units ')

%% ____________________
%% FIGURE 2

% plot imperial units figure

figure(2)

subplot(2,2,1);
plot(temperatures_im,altitudes_im,'k-');
axis([375 550 0 20])
title('Temperature change over altitude');
xlabel('temperature (F)');
ylabel('altitude (mi)');

grid on

subplot(2,2,2);
plot(pressures_im,altitudes_im,'k-');
title('Air pressure change over altitude');
xlabel('pressure (lb/in^2)');
ylabel('altitude (mi)');

grid on

subplot(2,2,3);
plot(densities_im,altitudes_im,'k-');
title('Air density change over altitude');
xlabel('density (slug/ft^3)');
ylabel('altitude (mi)');

grid on

subplot(2,2,4);
plot(speeds_im,altitudes_im,'k-');
title('Speed of sound change over altitude');
xlabel('velocity (f/s)');
ylabel('altitude (mi)');

grid on

sgtitle('Atmoshperic model in imperial units')

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
