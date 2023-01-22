% AAE 251 Fall 2022
% Homework 05
% Title of the code: NACA 4-digit Airfoil Plotting

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

% create constants
M = 0.02;
P = 0.4;
T = .15;

i = 1;
% create function inputs
x = linspace(0,1,501);

% initalize arrays
MCL_coords = zeros(1,501);
YT = zeros(1,501);
theta = zeros(1,501);
x_upper = zeros(1,501);
y_upper = zeros(1,501);
x_lower = zeros(1,501);
y_lower = zeros(1,501);

%% ____________________
%% CALCULATIONS

% create for loop to create data for graphing
for inputs = linspace(0,1,501)
    if inputs >= 0 && inputs <= .4 % calculations for 0 <= x <= P

        theta(i) = atan(((2 * M) / (P^2) * (P - inputs))); % calculate angle using arctan of derivative of mean camber line equation
        MCL_coords(i) = (M / (P^2)) * (2 * P * inputs - inputs^2); % calculate mean camber line coordinates
        YT(i) = (T/.2) * (.2969 * sqrt(inputs)  - .126 * inputs - .3516 *inputs^2 + .2843 * inputs^3 - .1015 * inputs^4); % calculate thickness distribution

        x_upper(i) = inputs - YT(i) * sin(theta(i)); % calculate x coords of upper airfoil line
        y_upper(i) = MCL_coords(i) + YT(i) * cos(theta(i)); % calculate y coords of upper airfoil line
        x_lower(i) = inputs + YT(i) * sin(theta(i)); % calculate x coords of lower airfoil line
        y_lower(i) = MCL_coords(i) - YT(i) * cos(theta(i)); % calculate y coords of lower airfoil line

    elseif inputs > .4 && inputs <= 1 % calculations for P < x <= 1

        theta(i) = atan(((2 * M) / ((1 - P)^2) * (P - inputs))); % calculate angle using arctan of derivative of mean camber line equation
        MCL_coords(i) = (M / (1 - P)^2) * ((1 - 2 * P) + 2 * P * inputs - inputs^2); % calculate mean camber line coordinates 
        YT(i) = (T/.2) * (.2969 * sqrt(inputs)  - .126 * inputs - .3516 *inputs^2 + .2843 * inputs^3 - .1015 * inputs^4); % calculate thickness distribution

        x_upper(i) = inputs - YT(i) * sin(theta(i)); % calculate x coords of upper airfoil line
        y_upper(i) = MCL_coords(i) + YT(i) * cos(theta(i)); % calculate y coords of upper airfoil line
        x_lower(i) = inputs + YT(i) * sin(theta(i)); % calculate x coords of lower airfoil line
        y_lower(i) = MCL_coords(i) - YT(i) * cos(theta(i)); % calculate y coords of lower airfoil line

    end

    i = i + 1; % iterate to store values

end

%% ____________________
%% FIGURE 1

% plot airfoil
hold on
axis equal % scale to look like an actual airfoil
plot(x_lower,y_lower);
plot(x_upper,y_upper);
grid on
xlabel('Length (unitless)')
ylabel('Length (unitless)')
title('2415 NACA airfoil')

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
