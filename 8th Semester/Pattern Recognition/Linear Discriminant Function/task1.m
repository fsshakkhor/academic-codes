w1 = [1 1 4;1 -1 5];
w2 = [2 0 2;2.5 2 3];

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
disp(y);