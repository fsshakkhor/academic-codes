x = [3 5];
y = [4 5];

p = polyfit(x,y,1);
answer = polyval(p,4.5);

disp(answer);

X = [1  3 4.5  5  7  9  11];
Y = [-3 4 answer  5 -8 -3 0];

plot(X,Y);
hold on;
stem(X,Y);
grid on;
