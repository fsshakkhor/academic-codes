function [output] = g(X,w)

output = transpose(X) * w - 0.5 * transpose(w) * w;
end