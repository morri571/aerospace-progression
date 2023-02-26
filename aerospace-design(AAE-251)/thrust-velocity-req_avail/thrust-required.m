function[T_req_EJ,T_req_GA,EJ_CD0,GA_CD0] = T_required(G,rho,EJ_full_mass,GA_full_mass,EJ_K,GA_SA,EJ_SA,GA_K,EJ_velocities,GA_velocities,EJ_CD0,GA_CD0)

    % create empty arrays of required thrust
    T_req_EJ = zeros(1,100);
    T_req_GA = zeros(1,100);
    
    % loop through and fill array
    for i = 1:100
        % calculate required thrust for GA and EJ aircraft
        T_req_EJ(i) = 0.5 * rho * EJ_velocities(i)^2 * EJ_SA * EJ_CD0 + (2 * EJ_K * (EJ_full_mass * G)^2 /(rho * EJ_SA * EJ_velocities(i)^2));
        T_req_GA(i) = 0.5 * rho * GA_velocities(i)^2 * GA_SA * GA_CD0 + (2 * GA_K * (GA_full_mass * G)^2 /(rho * GA_SA * GA_velocities(i)^2));
    end

end
