A = []
xl = 0;
xu = .11;
prem = 1;

for i = 1 : 10
    xm = (xl + xu)/2;
    p = F(xl) * F(xm);
    newl = 0;
    newu = 0;
    newm = 0;
    error = 0;
    val = 0;
    
    if p < 0 
        newl = xl;
        newu = xm;
    else
        newl  = xm;
        newu = xu;
    end
    
    error = (xm - prem)/xm;
    error = error * 100;
    if error < 0
        error = -error;
    end
    
    
    val = F(xm);
    
    A = [xl xu xm error val];
    xl = newl;
    xu = newu;
    prem = xm;
    disp(A);
end
