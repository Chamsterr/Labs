format long %
n = 0.01;

F1 = @(x) x.^3 + 0.5.*x-1;
F1_for_simple = @(x) x - (1/(3*x.^2+0.5)).*(x.^3 + 0.5.*x-1); 
F1_ = @(x) 3*x.^2+0.5;
F1__ = @(x) 6*x;

% F1 = @(x) x.^3 + 2.*x + 2;
% F1_for_simple = @(x) x - (1/(3*x.^2+2)).*(x.^3 + 2.*x + 2); 
% F1_ = @(x) 3*x.^2+2;
% F1__ = @(x) 6*x;

% 🠓🠓 Ось оx 🠓🠓
F2 = @(x) 0;

x01 = fzero(F1, 0);
y01 = 0;

figure Name 1
    ezplot(F1),hold on;
    ezplot(F2);
plot(x01, y01, 'or');


start_answer = Find_start(F1, F1);

disp_start_answer = ['Начальное приближение: ', 'x0 = ', num2str(start_answer)];
disp(disp_start_answer)

disp(Niuton(F1, F1_, start_answer, n))

disp(Half_division(F1, -2, 2, n))

disp(Simple_iteration(F1_for_simple, n))


% Дихатомия
function half_division_answer = Half_division(F, a, b , n)
    while b-a > n
        c = (a + b) / 2;
        if F(b)*F(c) < 0
            a = c;
        else 
            b = c;
        end
    end
    half_division_answer = c;
end 
% Начальное приближение
function find_start_answer = Find_start(F, F__)
    n = 0;
    while F(n)*F__(n) < 0
        n = n +1;
    end
    find_start_answer = n;
end
% Ньютона
function Niuton_answer = Niuton(F, F_, start_answer, n)
    Niuton_answer_last = start_answer;
    Niuton_answer_last = Niuton_answer_last -F(Niuton_answer_last)/F_(Niuton_answer_last);
    Niuton_answer = 1;
    counter = 0;
    while(abs(Niuton_answer-Niuton_answer_last) > n)
        Niuton_answer_last = Niuton_answer;
        Niuton_answer = Niuton_answer_last -F(Niuton_answer_last)/F_(Niuton_answer_last);
        counter = counter + 1;
        calculation_error = abs(Niuton_answer-Niuton_answer_last);
        
        disp('-------------------------------------------')
        disp_info_about_iteration = ['Итерация номер - ' num2str(counter), ':'];
        disp_info_about_iteration_main = ['приближенный ответ - '  num2str(Niuton_answer)];
        disp_info_about_iteration_calc = ['погрешность - '  num2str(calculation_error)];
        
        disp(disp_info_about_iteration);
        disp(disp_info_about_iteration_main);
        disp(disp_info_about_iteration_calc);
    end
end

function simple_iteration_answer = Simple_iteration(F, n)
    x_ = 0.8;
    x0 = 0.8;
    x1 = F(x0);
    N = 100;
    for counter = 1 : N
        if (x1 - x0).^2/abs(2*x0-x1-x_) < n
            break
        end
        x_ = x0;
        x0 = x1;
        x1 = F(x0);
    end
    disp(counter);
    simple_iteration_answer = x1;
end
