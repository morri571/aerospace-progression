function[P_avail] = P_available(rho,rho0,Mad,C,P0max,H)
    
    % calculate available power
    P_avail = H * C * (rho/rho0)^Mad * P0max;

end
