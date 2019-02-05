A = imread('download.jpg');
[n m] = size(A);

gamma = 2;
A = double(A);

imgout = (A .^ gamma);
rmin = min(imgout);
rmax = max(imgout);
denom = rmax - rmin;

for i = 1 : n
    for j = 1 : m
        x = (A(i,j) - rmin);
        x = x/denom;
        imgout(i,j) = x;
    end
end

imtool(imgout);