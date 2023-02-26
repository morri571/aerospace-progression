function [EJ_lifts,EJ_drags,EJ_CLS,EJ_CDS,GA_lifts,GA_drags,GA_CLS,GA_CDS] = LD_function(rho,G,EJ_SA,EJ_velocities,EJ_full_mass,GA_SA,GA_velocities,GA_full_mass)

    % initialize arrays
    EJ_lifts = zeros(1,100);
    EJ_drags = zeros(1,100);
    GA_lifts = zeros(1,100);
    GA_drags = zeros(1,100);
    EJ_CLS = zeros(1,100);
    EJ_CDS = zeros(1,100);
    GA_CLS = zeros(1,100);
    GA_CDS = zeros(1,100);

    % loop for calculations
    for i = 1:100
        % calculate lift and drag for both aircraft
        EJ_CLS(i) = 2 * EJ_full_mass * G / (rho * EJ_velocities(i)^2 * EJ_SA);
        EJ_CDS(i) = .015 + .05 * (EJ_CLS(i))^2;
        EJ_lifts(i) = 0.5 * rho * (EJ_velocities(i))^2 * EJ_SA * EJ_CLS(i);
        EJ_drags(i) = 0.5 * rho * (EJ_velocities(i))^2 * EJ_SA * EJ_CDS(i);

        GA_CLS(i) = 2 * GA_full_mass * G / (rho * GA_velocities(i)^2 * GA_SA);
        GA_CDS(i) = .026 + .054 * (GA_CLS(i))^2;
        GA_lifts(i) = 0.5 * rho * (GA_velocities(i))^2 * GA_SA * GA_CLS(i);
        GA_drags(i) = 0.5 * rho * (GA_velocities(i))^2 * GA_SA * GA_CDS(i);
    end

end
