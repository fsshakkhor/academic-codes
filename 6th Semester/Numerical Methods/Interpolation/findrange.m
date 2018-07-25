function [x,y] = findrange(X,Y,val)
x = [];
y = [];
l = 1;
r = 4;
dmin = 1000;
index = 1;

while r <= 6
    d = 0;
    for i = l : r
        d = max([d abs(val - X(i)) ] );
    end
    if d < dmin
        dmin = d;
        index = l;
    end
    l = l + 1;
    r = r + 1;
end

shesh = index + 3;
for i = index : shesh
    x = [x X(i)];
    y = [y Y(i)];
end

end
