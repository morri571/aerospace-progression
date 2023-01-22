% AAE 251 Fall 2022
% Homework 04
% Title of the code: Calculation of escape velocities to reach LEO at
% various launch sites

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

% create constants
starbase_lat = 25.9875; % starbase latitude (degrees) 
ksc_lat = 28.52417; % kennedy space center latitude (degrees)
earth_rotation = 7.292e-5; % earth rotation speed (rad/s)
earth_radius = 6371; % earth's radius (km)
V_loss = 1.65; % loss velocity (km/s)
G = 6.6743e-11; % gravitational constant (Nm^2/kg^2)
earth_mass = 5.972e24; % earth mass (kg)

% create function inputs
azimuths = linspace(0,180,181);
starbase_permissible_az = [93 94 95 112];
ksc_permissible_az = linspace(35,120,86);
inclinations = linspace(0,90,91);

% initalize arrays
starbase_Veh = zeros(1,181);
ksc_Veh = zeros(1,181);
starbase_94_V = zeros(1,91);
starbase_112_V = zeros(1,91);
ksc_35_V = zeros(1,91);
ksc_90_V = zeros(1,91);
ksc_120_V = zeros(1,91);

%% ____________________
%% CALCULATIONs

% calculate constant V_leo
V_leo = (sqrt((G * earth_mass) / ((earth_radius + 222) * 1000))) / 1000; % LEO velocity (km/s) 

for i = 1:181
    starbase_Veh(i) = earth_rotation * earth_radius * cosd(starbase_lat) * sind(azimuths(i));
    ksc_Veh(i) = earth_rotation * earth_radius * cosd(ksc_lat) * sind(azimuths(i));
end

% calculate VEH in acceptable ranges
starbase_permissible_Veh = sind(starbase_permissible_az) * earth_rotation * earth_radius * cosd(starbase_lat);
ksc_permissible_Veh = sind(ksc_permissible_az) * earth_rotation * earth_radius * cosd(ksc_lat);

%calculate new inclinations and VEH values
starbase_94_inclination = acosd(cosd(starbase_lat) * sind(azimuths(95)));
starbase_94_new_Veh = (earth_rotation * (earth_radius + 222) * cosd(starbase_lat) * sind(azimuths(95)));

starbase_112_inclination = acosd(cosd(starbase_lat) * sind(azimuths(113)));
starbase_112_new_Veh = (earth_rotation * (earth_radius + 222) * cosd(starbase_lat) * sind(azimuths(113)));

KSC_35_inclination = acosd(cosd(ksc_lat) * sind(azimuths(36)));
KSC_35_new_Veh = (earth_rotation * (earth_radius + 222) * cosd(ksc_lat) * sind(azimuths(36)));

KSC_90_inclination = acosd(cosd(ksc_lat) * sind(azimuths(91)));
KSC_90_new_Veh = (earth_rotation * (earth_radius + 222) * cosd(ksc_lat) * sind(azimuths(91)));

KSC_120_inclination = acosd(cosd(ksc_lat) * sind(azimuths(121)));
KSC_120_new_Veh = (earth_rotation * (earth_radius + 222) * cosd(ksc_lat) * sind(azimuths(121)));

% calculate V total 
for i = 1:91
    inclination = abs(inclinations(i) - starbase_94_inclination);
    starbase_94_V(i) = V_leo + V_loss + (2 * V_leo * sind(inclination/2))  - starbase_94_new_Veh;
    
    inclination = abs(inclinations(i) - starbase_112_inclination);
    starbase_112_V(i) = V_leo + V_loss + (2 * V_leo * sind(inclination/2))  - starbase_Veh(113);
    
    inclination = abs(inclinations(i) - KSC_35_inclination);
    ksc_35_V(i) = V_leo + V_loss + (2 * V_leo * sind(inclination/2))  - ksc_Veh(36);

    inclination = abs(inclinations(i) - KSC_90_inclination);
    ksc_90_V(i) = V_leo + V_loss + (2 * V_leo * sind(inclination/2))  - ksc_Veh(91);

    inclination = abs(inclinations(i) - KSC_120_inclination);
    ksc_120_V(i) = V_leo + V_loss + (2 * V_leo * sind(inclination/2))  - ksc_Veh(121);
end

%% ____________________
%% FIGURE 1

% plot VEH versus azimuth at launch sites
figure(1)

grid on
hold on
plot(azimuths,starbase_Veh,'r-')
plot(azimuths,ksc_Veh,'b-')
plot(starbase_permissible_az,starbase_permissible_Veh,'ro')
plot(ksc_permissible_az,ksc_permissible_Veh,'bo')
title('ΔV_E_H as a function of azimuth for starbase and KSC latitudes')
xlabel('Azimuth (degrees)')
ylabel('ΔV_E_H (km/s)')
legend('Starbase possible V_eh outputs from azimuth','KSC possible V_eh outputs from azimuth','Starbase permissible V_eh outputs from azimuth','KSC permissible V_eh outputs from azimuth','location','best')

%% ____________________
%% FIGURE 2

% plot V total at different launch sites and azimuths
figure(2)

grid on
hold on
plot(inclinations,starbase_94_V,'k-')
plot(inclinations,starbase_112_V,'b-')
plot(inclinations,ksc_35_V,'r-')
plot(inclinations,ksc_90_V,'y-')
plot(inclinations,ksc_120_V,'c-')
title('ΔVtot versus inclination at different launch sites')
xlabel('Inclination (degrees)')
ylabel('ΔVtot (kilometers/second)')
legend('Starbase 94° ΔVtot','Starbase 112° ΔVtot','KSC 35° ΔVtot','KSC 90° ΔVtot','KSC 120° ΔVot','location','best')

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
