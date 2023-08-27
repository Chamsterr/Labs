e = 0.01;

A = [3, 1, -1, 1; 
    1, -4, 3, -4; 
    -1, 1, 4, 1; 
    1, 2, 1, -5];
b = [36; 6; 3; 14];
x = [0.7*12; 1; 2; 0.5];

n = size(x,1);


disp(Zel(A, b, x, n, e));

disp(Zel_2(n, x));

function zel_answer = Zel(A, b, x, n, e)
    normVal=Inf;
    itr = 0;
    while normVal > e
        x_ = x; 
        for i = 1:n
            s = 0;
                for j=1:i-1
                    s = s+A(i,j)*x(j);
                end

                for j= i+1:n
                    s = s+A(i,j)*x_(j);
                end
        x(i) = (1./A(i,i))*(b(i)-s);
        end

        itr = itr + 1;
        normVal = norm(x_-x); 
    end
    zel_answer = x;
end

function zel_answer_2 = Zel_2(n, x)
    x0 = 0.5;
    y0 = -0.8;
    M1 = 2;
    M2 = 1;
    itr = 0;
    for i = 0:n
        x1 = x0 - (2.*x0-cos(y0+1) - y0 - 0.5)/M1;
        y1 = y0 - (y0+sin(x)+0.4)/M2;
        y0 = y1;
        x0 = x1;
        itr = itr + 1;
    end
    zel_answer_2 = 'Ответ:';
    disp(x0)
    disp(y0)
end