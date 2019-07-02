w1 = [1 1 4;1 -1 5];
w2 = [2 -1 2;2.5 0 3];

scatter(w1(1,:),w1(2,:),'r');
hold on;
scatter(w2(1,:),w2(2,:),'g');
axis([-10 10 -10 10])
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
y1 = [w1(1,:).*w1(1,:);
    w1(2,:).*w1(2,:);
    w1(1,:).*w1(2,:);
    w1(1,:);
    w1(2,:);
    ones(1,3)];


y2 = [w2(1,:).*w2(1,:);
    w2(2,:).*w2(2,:);
    w2(1,:).*w2(2,:);
    w2(1,:);
    w2(2,:);
    ones(1,3)];


y2 = y2 * -1;
y = [y1 y2];

y = transpose(y);

iterations = 1000;


w = [0 0 0 0 0 0];
alpha = 1;

for iter = 1 : iterations
    mis = 0;
    for i = 1 : 6
        g = w * (y(i,:))';
        if g <= 0
            w = w + alpha .* y(i,:);
            mis = mis + 1;
        end
    end
    
end

x1 = sym('x1');
x2 = sym('x2');

s = sym(w(1) * x1 * x1 + w(2) * x2 * x2 + w(3) * x1 * x2 + w(4) * x1 + w(5) * x2 + w(6));
s2 = solve(s,x2);
xvals1 = [-10:0.01:10];
xvals2(1,:) = subs(s2(2),x1,xvals1);
plot(xvals1,xvals2(1,:),'k');
