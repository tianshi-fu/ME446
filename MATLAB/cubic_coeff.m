function coeff = cubic_coeff(t0,tf,q0,qf,v0,vf)

A = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
b = [q0; v0; qf; vf];

coeff = A\b;
end

