function [theta] = runge2(h)

theta = 1200;
for t = h : h : 480
    k1 = F(theta);
    k2 = F(theta + k1 * h/2);
    newtheta = theta + k2 * h;
    theta = newtheta;
end

end
