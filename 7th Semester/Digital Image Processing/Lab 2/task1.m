A = imread('histEq.jpg');
[n m] = size(A);

freq = zeros(256,1);
store = zeros(256,1);

for i = 1 : n
    for j = 1 : m
        freq(A(i,j) + 1) = freq(A(i,j) + 1) + 1; 
    end
end

cum = 0;
total = n * m;
for i = 0 : 255
    cum = cum + freq(i + 1);
    freq(i + 1) = cum;
    store(i + 1) = (freq(i + 1)/total) * 255;
    store(i + 1) = floor(store(i+1));
end

newA = A;

for i = 1 : n
    for j = 1 : m
        newA(i,j) = store(newA(i,j) + 1);
    end
end

imtool(A);
imtool(newA);

newfreq = zeros(1,256);
cdf = zeros(1,256);

cum = 0;
for i = 1 : n
    for j = 1 : m
        newfreq(newA(i,j) + 1) = newfreq(newA(i,j) + 1) + 1; 
    end
end

for i = 1 : 256
    cum = cum + newfreq(i);
    cdf(i) = cum;
end

figure;
stem(newfreq);
figure;
stem(cdf);