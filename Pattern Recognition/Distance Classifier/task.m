w1 = [2 2;3 1;3 3;-1 -3;4 2;-2 -2];
w2 = [0 0;-2 2;-1 -1;-4 2;-4 3;2 6];

w1 = transpose(w1);
w2 = transpose(w2);
scatter(w1(1,:),w1(2,:));
hold on;
scatter(w2(1,:),w2(2,:));
axis([-7 7 -7 7]);

w1 = mean(w1,2);
w2 = mean(w2,2);

scatter(X(1,i),X(2,i),'b','x');

X = [-1.5 3 -2 8;-1.5 2 1 2];

o1 = g(X,w1);
o2 = g(X,w2);


for i = 1 : 4
    if o1(i) > o2(i)
        scatter(X(1,i),X(2,i),'b','x');
    else
        scatter(X(1,i),X(2,i),'r','x');    
    end
    hold on;
end

scatter(w1(1),w1(2),'g','o');
scatter(w2(1),w2(2),'k','o');

W = w1 - w2;
W0 = -0.5 * (transpose(w1) * w1 - transpose(w2) * w2);


fx = -10 : .1 : 10;
fy = -(W(1) * fx + W0)/W(2);

hold on;
plot(fx,fy);
axis([-10 10 -10 10]);
