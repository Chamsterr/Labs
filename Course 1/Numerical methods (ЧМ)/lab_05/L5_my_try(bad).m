e = 0.01;
m = 12
a = [3, 1, -1, 1;
     1, -4, 1, -1;
     -1, 1, 4, 1;
     1, 2, 1, -5;]
b = [3*m;
     m-6;
     15-m;
     m+2;];
 NumIter = 100;
A = [12, -1/3, 1/3, -1/3;
           -3/2, -1/4, +1/4, +1/4;
           3/4, 1/4, -1/4, -1/4;
           -14/5, 1/5, 2/5, 1/5;];
Zel_clau (A, e, m);

function zel_answer_clau = Zel_clau (A, e, m)
    x1=0.7*m; x2=1; x3=2; x4=0.5;
    NumIter = 100;
    for i=1:1:NumIter
        x1(i+1)=A(1,1)-A(1,2).*x2(i)-A(1,3).*x3(i)-A(1,4).*x4(i);
        x2(i+1)=A(2,1)-A(2,2).*x1(i+1)-A(2,3).*x3(i)-A(2,4).*x4(i);
        x3(i+1)=A(3,1)-A(3,2).*x1(i+1)-A(3,3).*x2(i+1)-A(3,4).*x4(i);
        x4(i+1)=A(4,1)-A(4,2).*x1(i+1)-A(4,3).*x2(i+1)-A(4,4).*x3(i+1);
        if abs(x1(i+1)-x1(i)) < e
            disp(['Число итераций=' num2str(i)])
            disp(['X1 = ',num2str(x1(i)), ' X2 = ',num2str(x2(i)),' X3 = ',num2str(x3(i)), ' X4 = ',num2str(x4(i))])
            break
        end
        zel_answer_clau = [x1(i), x2(i), x3(i), x4(i)];
    end
end