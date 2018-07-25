A = [ 2 3 9 14 1 45 3 2];
x = [ 0 1 2 3 4 5 6 7];

ye = []
yo = []


for i = 1 : 8
    ye = [ye (A(i) + A(9 - i))/2];
    yo = [yo (A(i) - A(9 - i))/2];
end

subplot(3,1,1);
plot(x,A);
title('Original Signal');
xlabel('Time');
ylabel('Amplitude');
subplot(3,1,2);
plot(x,ye);
xlabel('Time');
ylabel('Amplitude');
title('Even Decomposition');
subplot(3,1,3);
plot(x,yo);
xlabel('Time');
ylabel('Amplitude');
title('Odd Decomposition');
