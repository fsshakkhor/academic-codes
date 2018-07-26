n = 512;

A = rand(1,n);
B = zeros(1,n);

real = zeros(1,n/2+1);
img = zeros(1,n/2+1);


for k = 1 : n/2 + 1
    for i = 1 : n
        real(k) = real(k) + A(i) * cos(2 * pi * (k-1) * (i-1) /n);
        img(k) = img(k) - A(i) * sin(2 * pi * (k-1) * (i-1) /n);
    end
end

for k = 1 : n/2 + 1
    real(k) = real(k)/(n/2);
    img(k) = -img(k)/(n/2);
end
real(1) = real(1)/2;
real(n/2+1) = real(n/2+1)/2;
    
for k = 1 : n/2 + 1
    for i = 1 : n
        B(i) = B(i) + real(k) * cos(2 * pi * (k-1) * (i-1) /n);
        B(i) = B(i) + img(k) * sin(2 * pi * (k-1) * (i-1) /n);
    end
end

subplot(2,1,1);
plot(A);
hold on;
plot(B);
