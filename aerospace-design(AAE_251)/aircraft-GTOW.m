% AAE 251 Fall 2022
% Homework 02
% Title of the code: simulated take off weight calculation of an aircraft.

% Authors: Aidan Morrison

%% ____________________
%% INITIALIZATION

fprintf('Please enter all inputs in english units. They will be converted to metric if you wish.\n')
units = input('Please input 1 if you want metric or 2 if you want english units\n');
aircraft = input(['Please input 1 for unpowered sailplane, 2 for powered sailplane, 3 for homebuild wood/metal, ' ...
    '\n4 for homebuilt composite, 5 for single engine GA, 6 for double engine GA,\n7 for agricultural aircraft, 8 for twin turboprop, ' ...
    '9 for flying boat,\n10 for jet trainer, 11 for jet fighter, 12 for military cargo/bomber, or 13 for jet transport.\n']);
engine = input(['Please input 1 for pure turbojet, 2 for low bypass-turbofan, 3 for high-bypass turbofan,' ...
    '\n4 for fixed piston-prop, 5 for variable piston-prop, or 6 for turboprop.\n']);
M = input('Please enter mach number.\n');
R = input('Please enter range in nautical miles.\n');
LD1 = input('Please enter lift/drag ratio.\n');
CC1 = input('Please enter specific fuel consumption per hour for cruise 1.\n');
CC2 = input('Please enter specific fuel consumption per hour for cruise 2.\n');
E1 = input('Please enter loiter 1 time in hours.\n');
E2 = input('Please enter loiter 2 time in hours.\n');
KVS = input('Please enter 1 for fixed sweep or 1.04 for variable sweep\n');
payload_weight = input('What is the payload weight?\n');
crew_weight = input('What is the crew weight?\n');
weight_guess = input('Please enter guess for aircraft weight\n');

% given weight ratios
W1_W0 = .97;
W2_W1 = .985;
W7_W6 = .995;

%% ____________________
%% CALCULATE  W7_W0

% Conversions

R = R * 6076.12; % range in feet
CC1 = CC1 / 3600; % 1st cruise C
CC2 = CC2 / 3600; % 2nd cruise C
V = M * 994.8; % velocity
E1 = E1 * 3600; % 1st loiter E
E2 = E2 * 3600; % 2nd loiter E

LD2 = LD1 * .866;

% Cruise 1

if engine >= 1 && engine <= 3

    W3_W2 = exp((-R * CC1 / V) / LD2); % weight ratio of cruise 1 for jets

else 

    W3_W2 = exp((-R * CC1 / V) / LD1); % weight ratio of cruise 1 for propellors

end

% Loiter 1

if engine >= 1 && engine <= 3
    
    W4_W3 = exp(-(E1 * CC2) / LD1); % weight ratio of loiter 1 for jets
    
else

    W4_W3 = exp(-(E1 * CC2) / LD2); % weight ratio of loiter 1 for propellors
    
end

% Cruise 2

W5_W4 = W3_W2;

% Loiter 2

if engine >= 1 && engine <= 3
    
    W6_W5 = exp(-(E2 * CC2) / LD1); % weight ratio of loiter 1 for jets
    
else

    W6_W5 = exp(-(E2 * CC2) / LD2); % weight ratio of loiter 1 for propellors
    
end

W7_W0 = W7_W6 * W6_W5 * W5_W4 * W4_W3 * W3_W2 * W2_W1 * W1_W0;

%% ____________________
%% CALCULATE W0

% calculated W0
W0 = AAE251_HW2_function(W7_W0,weight_guess,crew_weight,payload_weight,KVS,aircraft);

% loop to find W0 within certain error
while W0 - weight_guess >= 10 || W0 - weight_guess <= -10
    weight_guess = (weight_guess + W0) / 2;
    W0 = AAE251_HW2_function(W7_W0,weight_guess,crew_weight,payload_weight,KVS,aircraft);
end

if units == 1
    fprintf('Takeoff weight within 4.53 kg error is %f\n',W0 * 2.205);
else
    fprintf('Takeoff weight within 10 lb error is %f\n',W0);
end

%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.
