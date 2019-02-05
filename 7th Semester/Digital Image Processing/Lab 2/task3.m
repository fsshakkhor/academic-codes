A = imread('dollar.jpg');
[n m] = size(A);

mask = 1;
for k = 1 : 8
    newA = zeros(n,m);
    for i = 1 : n
        for j = 1 : m
            x = bitand(A(i,j),mask);
            if x > 0 
                newA(i,j) = 1;
            else
                newA(i,j) = 0;
            end 
            
        end
    end
    mask = mask * 2;
    subplot(4,2,k);
    imshow(newA);
end
