% AAE 251 Fall 2022
% Homework 07
% Title of the code: Calculation of GLOW and relation to velocity fractions
% and ISP

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

% Creat Constants
deltaV = 11110; % delta V (m/s)
payload = 88; % payload capacity in kg
f_inert = 1/12; % f_inert (
ISP_S1 = 277; % ISP of stage 1 (s)
ISP_S2 = 366; % ISP of stage 2 (s)
g = 9.81; % Earth's gravitational constant in m/s^2

% create arrays for loops
a1_fractions = linspace(0.2,0.6); % delta V fractions for stage 1
a2_fractions = linspace(0.5,0.605); % delta V fractions for stage 2

% create empty arrays for plotting
initial_mass_1 = zeros(1,100); % stage one masses
initial_masses_366 = zeros(1,100); % stage two masses with ISP 366
initial_masses_377 = zeros(1,100); % stage two masses with ISP 377
initial_masses_399 = zeros(1,100); % stage two masses with ISP 399
initial_masses_444 = zeros(1,100); % stage two masses with ISP 444
initial_masses_455 = zeros(1,100); % stage two masses with ISP 455

%% ____________________
%% CALCULATIONS

% calculate stage 1 masses
for i = 1:100
    exponent2 = exp(deltaV * (1 - a1_fractions(i)) / (ISP_S2 * g)); % create constant for propellant mass calculation (kg)
    propellant_mass = payload * (exponent2 - 1) * (1 - f_inert) / (1 - f_inert * (exponent2)); % calculate 2nd stage prop mass (kg)
    inert_mass = (f_inert * propellant_mass / (1 - f_inert)); % find 2nd stage inert mass (kg)
    final_mass = payload + inert_mass; % calculate 2nd final mass (kg)
    initial_mass_2 = final_mass + propellant_mass; % calculate 2nd stage takeoff mass (kg)

    exponent1 = exp(deltaV * a1_fractions(i) / (ISP_S1 * g)); % create constant for propellant mass calculation (kg)
    propellant_mass = initial_mass_2 * (exponent1 - 1) * (1 - f_inert) / (1 - f_inert * (exponent1)); % calculate 2nd stage prop mass (kg)
    inert_mass = (f_inert * propellant_mass / (1 - f_inert));
    final_mass = initial_mass_2 + inert_mass;
    initial_mass_1(i) = final_mass + propellant_mass; % calculate 1st stage takeoff mass
end

minimum_GLOW = min(initial_mass_1); % minimum glow (kg)
a1_GLOW = a1_fractions(initial_mass_1 == minimum_GLOW); % minimum glow a1
a2_GLOW = 1 - a1_GLOW; % minimum glow a2

exponent2 = exp((deltaV * a2_GLOW) / (ISP_S2 * g)); % create constant for propellant mass calculation (kg)
propellant_mass = payload * (exponent2 - 1) * (1 - f_inert) / (1 - f_inert * (exponent2)); % calculate 2nd stage prop mass (kg)
inert_mass = (f_inert * propellant_mass / (1 - f_inert)); % find 2nd stage inert mass (kg)
final_mass = payload + inert_mass; % calculate 2nd final mass (kg)
initial_mass_2 = final_mass + propellant_mass; % calculate 2nd stage takeoff mass (kg)

exponent1 = exp(deltaV * (1 - a2_GLOW) / (ISP_S1 * g)); % create constant for propellant mass calculation (kg)
propellant_mass_2 = initial_mass_2 * (exponent1 - 1)*(1 - f_inert) / (1 - f_inert * (exponent1)); % calculate 1st stage prop mass (kg)
propellant_total = propellant_mass_2 + propellant_mass; % total mass of the propellant (kg)

for ISPS_2 = [366 377 399 444 455]
    for i = 1:100
        exponent2 = exp((deltaV * a2_fractions(i)) / (ISPS_2 * g)); % create constant for propellant mass calculation (kg)
        propellant_mass = payload * (exponent2 - 1) * (1 - f_inert) / (1 - f_inert * (exponent2)); % calculate 2nd stage prop mass (kg)
        inert_mass = (f_inert * propellant_mass / (1 - f_inert)); 
        final_mass = payload + inert_mass; % calculate 2nd final mass (kg)
        initial_mass = final_mass + propellant_mass;

        exponent1 = exp(deltaV * (1 - a2_fractions(i)) / (ISP_S1 * g)); % create constant for propellant mass calculation (kg)
        propellant_mass_2 = initial_mass * (exponent1 - 1) * (1 - f_inert) / (1 - f_inert * (exponent1)); % calculate 1st stage prop mass (kg)
        inert_mass_2 = (f_inert * propellant_mass_2 / (1 - f_inert)); % find 2nd stage inert mass (kg)
        final_mass_2 = initial_mass + inert_mass_2; % calculate 2nd final mass (kg)  
        initial_mass_2 = final_mass_2 + propellant_mass_2; % calculate 1st stage takeoff mass
        
        % use logic to store values in appropriate arrays for plotting
        if ISPS_2 == 366
            initial_masses_366(i) = initial_mass_2 + propellant_mass;
        elseif ISPS_2 == 377
            initial_masses_377(i) = initial_mass_2 + propellant_mass;
        elseif ISPS_2 == 399
            initial_masses_399(i) = initial_mass_2 + propellant_mass;
        elseif ISPS_2 == 444
            initial_masses_444(i) = initial_mass_2 + propellant_mass;
        elseif ISPS_2 == 455
            initial_masses_455(i) = initial_mass_2 + propellant_mass;
        end

    end
end

%% ____________________
%% FIGURE 1

% plot GLOW against a1 velocity fraction
figure(1)
hold on
grid on
plot(a1_fractions,initial_mass_1,'k-')
plot(a1_GLOW,minimum_GLOW,'r*')
legend("\DeltaV fraction versus GLOW", "mimimum GLOW",'Location','best')
title("GLOW with relation to \DeltaV fraction of first stage")
xlabel("\DeltaV fraction (unitless)")
ylabel("Gross Lift-Off Weight (kg)")

%% ____________________
%% FIGURE 2

% plot GLOW against a2 velocity fraction for 5 different ISP's
figure(2)
hold on
grid on
plot(a2_fractions,initial_masses_366,'r-')
plot(a2_fractions,initial_masses_377,'b-')
plot(a2_fractions,initial_masses_399,'g-')
plot(a2_fractions,initial_masses_444,'m-')
plot(a2_fractions,initial_masses_455,'y-')
legend("I_{sp} 366", "I_{sp} 377", "I_{sp} 399", "I_{sp} 444", "I_{sp} 455",'Location','best')
title("GLOW with relation to \DeltaV fraction of second stage")
xlabel("\DeltaV fraction (unitless)")
ylabel("Gross Lift-Off Weight (kg)")

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
