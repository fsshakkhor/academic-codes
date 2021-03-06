M = readtable('titanic.csv');

M = M(1:100,:);
[n m] = size(M);

survived = 0;
dead = 0;
fare_survived = 0;
fare_dead = 0;

t1 = table2array(M(:,1));
t2 = table2array(M(:,2)) ;t2 = str2double(t2);
t3 = table2array(M(:,3));
t4 = table2array(M(:,4));
t5 = table2array(M(:,5));


disp('Mean of the ticket fares of people of those who survived');
disp(mean(t2(t5 == 1),1) );
disp('Mean of the ticket fares of people of those who survived');
disp(mean(t2(t5 == 0),1) );

male = 0;
female = 0;
for i = 1 : 100
    if strcmp(t4(i),'male') && t5(i) == 1
        male = male + 1;
    end
    if strcmp(t4(i),'female') && t5(i) == 1
        female = female + 1;
    end
end

disp('Survived Male : ');
disp(male);
disp('Survived Female : ');
disp(female);

disp('The mean age of people who survived');
disp(mean(t3(t5 == 1),1));
disp('The mean age of people who did not survived');
disp(mean(t3(t5 == 0),1));