x = 79;
x = (x/180)*pi;
sign = 1;
ans = 0;
for n = 1 : 2 : 11
    up = x ^ n;
    f = factorial(n);
    ans = ans + sign * up / f;
    sign = -sign;
end

disp('Calculated Answer:');
disp(ans);
disp('Original Answer:');
disp(sin(x));

disp('Relative Absolute Error: ');
disp( 100 * (sin(x)-ans ) /sin(x) );
