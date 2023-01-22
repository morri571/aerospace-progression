function [W0] = aircraft-GTOW-function(W7_W0,weight_guess,crew_weight,payload_weight,KVS,aircraft)

switch aircraft
    case 1
        We_W0 = .86 * weight_guess^-.05 * KVS;
    case 2
        We_W0 = .91 * weight_guess^-.05 * KVS;
    case 3
        We_W0 = 1.19 * weight_guess^-.09 * KVS;
    case 4
         We_W0 = 1.15 * weight_guess^-.09 * KVS;
    case 5
         We_W0 = 2.36 * weight_guess^-.18 * KVS;
    case 6
         We_W0 = 1.51 * weight_guess^-.1 * KVS;
    case 7
         We_W0 = .74 * weight_guess^-.03 * KVS;
    case 8
         We_W0 = .96 * weight_guess^-.05 * KVS;
    case 9
         We_W0 = 1.09 * weight_guess^-.05 * KVS;
    case 10
         We_W0 = 1.59 * weight_guess^-.1 * KVS;
    case 11
         We_W0 = 2.34 * weight_guess^-.13 * KVS;
    case 12
         We_W0 = .93 * weight_guess^-.07 * KVS;
    case 13
         We_W0 = 1.02 * weight_guess^-.06 * KVS;
end
    

%% ____________________
%% CALCULATE FINAL W0

Wf_W0 = 1.06 * (1 - W7_W0);
W0 = (crew_weight + payload_weight) / (1 - Wf_W0 - We_W0);
