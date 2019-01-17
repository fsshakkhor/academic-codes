A = imread('yay.jpg');


[n m] = size(A);


subplot(1,4,1);
imshow(255-A(:,:,1));
subplot(1,4,2);
imshow( 255-A(:,:,2));
subplot(1,4,3);
imshow( 255-A(:,:,3));
subplot(1,4,4);
imshow(A);