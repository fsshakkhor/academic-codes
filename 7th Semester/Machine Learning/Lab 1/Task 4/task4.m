x=0:0.1:2*pi;
figure;
plot(x,sin(x));
hold on;
plot(x,cos(x));

legend('sin(x)','cos(x)');

figure;
x= 0:0.2:10
y=sigmf(x,[2 4]);
title('sigmoid function'); 
plot(x,y);
legend('sigmoid');