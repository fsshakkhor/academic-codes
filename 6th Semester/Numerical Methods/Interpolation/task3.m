X = [1 3 5 7 9 11];
Y = [-3 4  5 -8 -3 0];

[x,y] = findrange(X,Y,4.5);

p = polyfit(x,y,3);
answer = polyval(p,4.5);

X = [X 4.5];
Y = [Y answer];

X = [1 3 4.5 5 7 9 11];
Y = [-3 4 answer 5 -8 -3 0];
plot(X,Y);
stem(X,Y);
