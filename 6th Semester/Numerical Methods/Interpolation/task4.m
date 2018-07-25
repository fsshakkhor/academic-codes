X = [10     15      20      22.5  ];
Y = [227.04 362.78  517.35  602.97];

answer = 0;
x = 16.5;

for i = 1 : 4
    L = 1;
    for j = 1 : 4
        if i == j
            continue;
        end
        L = L * (x - X(j));
        L = L/(X(i) - X(j));
    end
    answer = answer + L * Y(i);    
end

X = [X x];
Y = [Y answer];
X = sort(X);
Y = sort(Y);

plot(X,Y);
grid on;
disp(answer);
