function[P_req_EJ,P_req_GA] = P_required(G,rho,EJ_full_mass,GA_full_mass,EJ_K,GA_SA,EJ_SA,GA_K,EJ_velocities,GA_velocities,EJ_CD0,GA_CD0)

    % create empty arrays of required thrust
    P_req_EJ = zeros(1,100);
    P_req_GA = zeros(1,100);
    
    % loop through and fill array
    for i = 1:100
        % calculate required power for GA and EJ aircraft
       P_req_EJ(i) = 0.5 * rho * EJ_velocities(i)^3 * EJ_SA * EJ_CD0 + (2 * EJ_K * (EJ_full_mass * G)^2 /(rho * EJ_SA * EJ_velocities(i)));
       P_req_GA(i) = 0.5 * rho * GA_velocities(i)^3 * GA_SA * GA_CD0 + (2 * GA_K * (GA_full_mass * G)^2 /(rho * GA_SA * GA_velocities(i)));
    end
end
