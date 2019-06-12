function [theta, theta_d, theta_dd] = thetas(t)

    if t > 2
       theta = 0;
       theta_d = 0;
       theta_dd = 0;
       
       return
    end
    
    if t <= 1
       theta = 1.5*t^2 - t^3;
       theta_d = 3*t - 3*t^2;
       theta_dd = 3 - 6*t;
    end
    
    if t > 1
       theta = -2 + 6*t - 4.5*t^2 + t^3;
       theta_d = 6 - 9*t + 3*t^2;
       theta_dd = -9 + 6*t;
    end


end