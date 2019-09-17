clear;

mat = [];
for i = 1 : 367
    filepre='imgset/img_';
    s=num2str(i); 
    impath=strcat(filepre,s,'.jpg');
    if(exist(impath) == 0)
        continue;
    end
    A = imread(impath);
    A = rgb2gray(A);
    
    A = imresize(A,[50 50]);
    lin = [];
    [n m] = size(A);
    

    for row = 1 : n
        for col = 1 : m
            lin = [lin A(row,col)];
        end
    end
    mat = [mat;lin];
end

mat = double(mat);

[cof,score,latent] = pca(mat);



normalized = latent/sum(latent);
% plot(normalized);

%mat = mat - mean(mat,2);
%mat2 = mat * cof;

[n m] = size(cof);
for col = 1 : 79
    img = [];
    ptr = 1;
    for i = 1 : 50
        lin = [];
        for j = 1 : 50
            lin = [lin cof(ptr,col)];
            ptr = ptr + 1;
        end
        img = [img;lin];
    end
    subplot(7,7,col);
    imagesc(img),colormap gray;
end

    

disp('done');
