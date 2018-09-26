function [theta] = eul(h)

theta = 1200;
for t = h : h : 480
    newtheta = theta + F(theta) * h;
    theta = newtheta;
end

end
