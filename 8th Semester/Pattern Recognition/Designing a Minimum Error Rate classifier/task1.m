X = [1,1;
    1,-1;
    4,5;
    -2,2.5;
    0,2;
    2,-3];

sigma1 = [.25 .3;.3 1];
mu1 = [0 0];
sigma2 = [.5 0;0 .5];
mu2 = [2 2];

for i = 1 : 6
    p1 = mvnpdf(X(i,:),mu1,sigma1);
    p2 = mvnpdf(X(i,:),mu2,sigma2);
    
    if p1 > p2
        scatter(X(i,1),X(i,2),'r','*');
    else 
        scatter(X(i,1),X(i,2),'g','+');
    end
    hold on;
end



W1 = -0.5 * inv(sigma1);
W2 = -0.5 * inv(sigma2);

w1 = inv(sigma1) * mu1';
w2 = inv(sigma2) * mu2';

w01 = -0.5 * mu1 * w1 - 0.5 * log(det(sigma1)) + log(0.5);
w02 = -0.5 * mu2 * w2 - 0.5 * log(det(sigma2)) + log(0.5);

W = W1 - W2;
w = w1' - w2';
w0 = w01 - w02;

disp(W);
disp(w);
disp(w0);
syms x1 x2;
s = sym(x1 * x1 * W(1,1) + (W(1,2) + W(2,1)) * x1 * x2 + x2 * x2 * W(2,2) + w(1,1) * x1 + w(1,2) * x2 + w0);

s2 = solve(s,x2);

xval = [-7:0.1:7];
xval2 = subs(s2(1),x1,xval);
xval3 = subs(s2(2),x1,xval);

plot(xval,xval2);
hold on;
plot(xval,xval3);

axis([-5 5 -15 15]);
