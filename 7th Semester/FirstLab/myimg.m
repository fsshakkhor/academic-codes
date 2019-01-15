A = imread('scene.jfif');
A = rgb2gray(A);

[n m] = size(A);

freq = zeros(256);
for i = 1 : n
    for j = 1 : m
        freq(A(i,j) + 1) = freq(A(i,j) + 1) + 1; 
    end
end

plot(freq);
imhist(A);

imgout = zeros(n,m,'uint8');
for i = 1 : n
    for j = 1 : m
        imgout(i,j) = 255 - A(i,j);
    end
end

imtool(A);
imtool(imgout);