function[T_avail] = T_available(rho,rho0,Mad,C,T0max)
    
    % calculate available thrust
    T_avail = C * (rho/rho0)^Mad * T0max;

end
