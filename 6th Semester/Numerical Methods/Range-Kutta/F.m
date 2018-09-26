function [v] = F(x)
C = -2.2067 * 1e-12;
P = x * x * x * x;
v = C * (P - 81 * 1e8);
end