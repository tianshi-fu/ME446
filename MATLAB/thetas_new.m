function [theta1, theta_d1, theta_dd1, theta2, theta_d2, theta_dd2, theta3, theta_d3, theta_dd3] = thetas_new(t,m1c,m2c,m3c)

    if t > 8
       theta1 = 0;
       theta_d1 = 0;
       theta_dd1 = 0;
       theta2 = 0;
       theta_d2 = 0;
       theta_dd2 = 0;
       theta3 = 0;
       theta_d3 = 0;
       theta_dd3 = 0;
       return
    end
    
    if t <= 1
       theta1 = m1c(1) + m1c(2)*t + m1c(3)*t^2 + m1c(4)*t^3;
       theta_d1 =  m1c(2) + 2*m1c(3)*t + 3*m1c(4)*t^2;
       theta_dd1 = 2*m1c(3) + 6*m1c(4)*t;
       theta2 = m2c(1) + m2c(2)*t + m2c(3)*t^2 + m2c(4)*t^3;
       theta_d2 =  m2c(2) + 2*m2c(3)*t + 3*m2c(4)*t^2;
       theta_dd2 = 2*m2c(3) + 6*m2c(4)*t;
       theta3 = m3c(1) + m3c(2)*t + m3c(3)*t^2 + m3c(4)*t^3;
       theta_d3 =  m3c(2) + 2*m3c(3)*t + 3*m3c(4)*t^2;
       theta_dd3 = 2*m3c(3) + 6*m3c(4)*t;
    end
    
    if t <= 2
       theta1 = m1c(5) + m1c(6)*t + m1c(7)*t^2 + m1c(8)*t^3;
       theta_d1 =  m1c(6) + 2*m1c(7)*t + 3*m1c(8)*t^2;
       theta_dd1 = 2*m1c(7) + 6*m1c(8)*t;
       theta2 = m2c(5) + m2c(6)*t + m2c(7)*t^2 + m2c(8)*t^3;
       theta_d2 =  m2c(6) + 2*m2c(7)*t + 3*m2c(8)*t^2;
       theta_dd2 = 2*m2c(7) + 6*m2c(8)*t;
       theta3= m3c(5) + m3c(6)*t + m3c(7)*t^2 + m3c(8)*t^3;
       theta_d3 =  m3c(6) + 2*m3c(7)*t + 3*m3c(8)*t^2;
       theta_dd3 = 2*m3c(7) + 6*m3c(8)*t;
    end
    
    if t <= 3
       theta1 = m1c(9) + m1c(10)*t + m1c(11)*t^2 + m1c(12)*t^3;
       theta_d1 =  m1c(10) + 2*m1c(11)*t + 3*m1c(12)*t^2;
       theta_dd1 = 2*m1c(11) + 6*m1c(12)*t; 
       theta2 = m2c(9) + m2c(10)*t + m2c(11)*t^2 + m2c(12)*t^3;
       theta_d2 =  m2c(10) + 2*m2c(11)*t + 3*m2c(12)*t^2;
       theta_dd2 = 2*m2c(11) + 6*m2c(12)*t; 
       theta3 = m3c(9) + m3c(10)*t + m3c(11)*t^2 + m3c(12)*t^3;
       theta_d3 =  m3c(10) + 2*m3c(11)*t + 3*m3c(12)*t^2;
       theta_dd3 = 2*m3c(11) + 6*m3c(12)*t; 
    end

    if t <= 4
       theta1 = m1c(13) + m1c(14)*t + m1c(15)*t^2 + m1c(16)*t^3;
       theta_d1 =  m1c(14) + 2*m1c(15)*t + 3*m1c(16)*t^2;
       theta_dd1 = 2*m1c(15) + 6*m1c(16)*t;
       theta2 = m2c(13) + m2c(14)*t + m2c(15)*t^2 + m2c(16)*t^3;
       theta_d2 =  m2c(14) + 2*m2c(15)*t + 3*m2c(16)*t^2;
       theta_dd2 = 2*m2c(15) + 6*m2c(16)*t;
       theta3 = m3c(13) + m3c(14)*t + m3c(15)*t^2 + m3c(16)*t^3;
       theta_d3 =  m3c(14) + 2*m3c(15)*t + 3*m3c(16)*t^2;
       theta_dd3 = 2*m3c(15) + 6*m3c(16)*t;
    end
    
    if t <= 5
       theta1 = m1c(17) + m1c(18)*t + m1c(19)*t^2 + m1c(20)*t^3;
       theta_d1 =  m1c(18) + 2*m1c(19)*t + 3*m1c(20)*t^2;
       theta_dd1 = 2*m1c(19) + 6*m1c(20)*t;
       theta2 = m2c(17) + m2c(18)*t + m2c(19)*t^2 + m2c(20)*t^3;
       theta_d2 =  m2c(18) + 2*m2c(19)*t + 3*m2c(20)*t^2;
       theta_dd2 = 2*m2c(19) + 6*m2c(20)*t;
       theta3 = m3c(17) + m3c(18)*t + m3c(19)*t^2 + m3c(20)*t^3;
       theta_d3 =  m3c(18) + 2*m3c(19)*t + 3*m3c(20)*t^2;
       theta_dd3 = 2*m3c(19) + 6*m3c(20)*t;
    end
    
    if t <= 6
       theta1 = m1c(21) + m1c(22)*t + m1c(23)*t^2 + m1c(24)*t^3;
       theta_d1 =  m1c(22) + 2*m1c(23)*t + 3*m1c(24)*t^2;
       theta_dd1 = 2*m1c(23) + 6*m1c(24)*t;
       theta2 = m2c(21) + m2c(22)*t + m2c(23)*t^2 + m2c(24)*t^3;
       theta_d2 =  m2c(22) + 2*m2c(23)*t + 3*m2c(24)*t^2;
       theta_dd2 = 2*m2c(23) + 6*m2c(24)*t;
       theta3 = m3c(21) + m3c(22)*t + m3c(23)*t^2 + m3c(24)*t^3;
       theta_d3 =  m3c(22) + 2*m3c(23)*t + 3*m3c(24)*t^2;
       theta_dd3 = 2*m3c(23) + 6*m3c(24)*t;
    end
    
    if t <= 7
       theta1 = m1c(25) + m1c(26)*t + m1c(27)*t^2 + m1c(28)*t^3;
       theta_d1 =  m1c(26) + 2*m1c(27)*t + 3*m1c(28)*t^2;
       theta_dd1 = 2*m1c(27) + 6*m1c(28)*t;
       theta2 = m2c(25) + m2c(26)*t + m2c(27)*t^2 + m2c(28)*t^3;
       theta_d2 =  m2c(26) + 2*m2c(27)*t + 3*m2c(28)*t^2;
       theta_dd2 = 2*m2c(27) + 6*m2c(28)*t;
       theta3 = m3c(25) + m3c(26)*t + m3c(27)*t^2 + m3c(28)*t^3;
       theta_d3 =  m3c(26) + 2*m3c(27)*t + 3*m3c(28)*t^2;
       theta_dd3 = 2*m3c(27) + 6*m3c(28)*t;
    end
    
    if t <= 8
       theta1 = m1c(29) + m1c(30)*t + m1c(31)*t^2 + m1c(32)*t^3;
       theta_d1 =  m1c(30) + 2*m1c(31)*t + 3*m1c(32)*t^2;
       theta_dd1 = 2*m1c(31) + 6*m1c(32)*t;
       theta2 = m2c(29) + m2c(30)*t + m2c(31)*t^2 + m2c(32)*t^3;
       theta_d2 =  m2c(30) + 2*m2c(31)*t + 3*m2c(32)*t^2;
       theta_dd2 = 2*m2c(31) + 6*m2c(32)*t;
       theta3 = m3c(29) + m3c(30)*t + m3c(31)*t^2 + m3c(32)*t^3;
       theta_d3 =  m3c(30) + 2*m3c(31)*t + 3*m3c(32)*t^2;
       theta_dd3 = 2*m3c(31) + 6*m3c(32)*t;
    end

end