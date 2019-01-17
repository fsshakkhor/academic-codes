M = readtable('mtcars.csv');

A = table2array(M(:,2:7));

subplot(2,3,1);
scatter(A(:,2),A(:,1));
title('Displacement vs  Miles Per Gallon');

subplot(2,3,2);
scatter(A(:,3),A(:,1));
title('Horse Power vs  Miles Per Gallon');

subplot(2,3,3);
scatter(A(:,4),A(:,1));
title('Real Axel Ratio vs Miles Per Gallon');

subplot(2,3,4);
scatter(A(:,5),A(:,1));
title('Weight vs Miles Per Gallon');

subplot(2,3,6);
scatter(A(:,6),A(:,1));
title('Acceleration Measure vs Miles Per Gallon');
