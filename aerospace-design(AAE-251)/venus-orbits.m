% AAE 251 Fall 2022
% Homework 03
% Title of the code: Calculation and display of Jebediah and Valentina orbits around venus

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

% create constants
valentina_apoapsis = 555; % apoapsis constant of valentina orbit (km)
valentina_eccentricity = .0123; % eccentricity (circularness) of valentina orbit (unitless)
venus_radius = 6051.8; % venus radius (km)
jebediah_alt = 333; % jebediah apoapsis/alt: same because circular orbit(km)
valentina_a = 0.5 * (valentina_apoapsis + (2 * venus_radius + valentina_apoapsis - valentina_apoapsis * valentina_eccentricity) / (1 + valentina_eccentricity)); % valentina semi-major axis (km)

% create function inputs
surface_inputs_positive_venus = linspace(venus_radius,-venus_radius,180); % inputs for first and second quadrant of venus circle
surface_inputs_negative_venus = linspace(-venus_radius,venus_radius,180); % inputs for third and fourth quadrant of venus circle

surface_inputs_positive_jebediah = linspace(venus_radius + jebediah_alt,-venus_radius - jebediah_alt,180); % inputs for first and second quadrant of jebediah circle
surface_inputs_negative_jebediah = linspace(-venus_radius - jebediah_alt,venus_radius + jebediah_alt,180); % inputs for third and fourth quadrant of jebediah circle

surface_inputs_venus = [surface_inputs_positive_venus surface_inputs_negative_venus]; % concatenate venus inputs for plotting
surface_inputs_jebediah = [surface_inputs_positive_jebediah surface_inputs_negative_jebediah]; % concatenate jebediah inputs for plotting

%% ____________________
%% CALCULATIONs

% initalize arrays
venus_surface = zeros(1,360); % allocates memory for venus surface plot points
valentina_inputs = zeros(1,360); % allocates memory for valentina inputs
valentina_orbit = zeros(1,360); % allocates memory for valentina orbit plot points
jebediah_orbit = zeros(1,360); % allocates memory for jebediah orbit plot points

% calculate outputs for circle functions of jebediah orbit and venus
% surface
for i = 1:180
    venus_surface(i) = sqrt(venus_radius^2 - surface_inputs_positive_venus(i)^2);
    jebediah_orbit(i) = sqrt((venus_radius + jebediah_alt)^2 - surface_inputs_positive_jebediah(i)^2);
end
for i = 181:360
    venus_surface(i) = -sqrt(venus_radius^2 - surface_inputs_negative_venus(i - 180)^2);
    jebediah_orbit(i) = -sqrt((venus_radius + jebediah_alt)^2 - surface_inputs_negative_jebediah(i - 180)^2);
end

% convert valentina values from polar to cartesian
for i = 0:360
    valentina_orbit(i + 1) = (valentina_a * (1 - valentina_eccentricity^2)) / (1 + valentina_eccentricity * cosd(i)); 
    valentina_inputs(i + 1) = valentina_orbit(i + 1) * cosd(i);
    valentina_orbit(i + 1) = valentina_orbit(i + 1) * sind(i);
end

%% ____________________
%% FIGURE 1

% plot venus surface with jebediah and valentina orbits
grid on
hold on
plot(surface_inputs_venus,venus_surface,'k-')
plot(surface_inputs_jebediah,jebediah_orbit,'r-');
plot(valentina_inputs,valentina_orbit,'b-');
xlabel('Distance (kilometers)')
ylabel('Distance (kilometers)')
legend('Venus surface','Jebediah orbit','Valentina orbit')
title('Venus and spacecraft orbit');
axis([-8000 8000 -8000 8000])


%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
