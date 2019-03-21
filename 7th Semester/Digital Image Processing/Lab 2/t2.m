img2in = imread('pic.jpg');
[R C] = size(img2in);
img2in = double(img2in);
imgout = ((img2in.^(1.2))/(255.^(1)));

subplot(1,2,1);
imshow(uint8(img2in));
title('Original Image');
subplot(1,2,2);
imshow(imgout);
title('Transformed Image');