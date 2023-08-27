format long

n = 10;
a = -0.25;
b = 0.25;

disp('--------------------Вычисления_для_N1-------------------');
F1 = @(x) 1./cos(5*x);

ideal_f1 = integral(F1, a, b);

answer_for_method_rectangle_f1 =(method_rectangle(F1, a, b, n));
answer_for_method_trap_f1 = (method_trap(F1, a, b, n));
answer_for_method_simpson_f1 = (method_simpson(F1, a, b, n));

disp('--------------------Погрешности_для_N1-------------------');

disp('--------------------Относительные------------------------');
disp('Погрешность методом ср. прямоугольников');
answer_calculation_error_f1_r = calculation_error(ideal_f1, answer_for_method_rectangle_f1);
disp('Погрешность методом трапеций');
answer_calculation_error_f1_t = calculation_error(ideal_f1, answer_for_method_trap_f1);
disp('Погрешность методом Cимпсона');
answer_calculation_error_f1_s = calculation_error(ideal_f1, answer_for_method_simpson_f1);


disp('--------------------Абсолютные---------------------------');
disp('Погрешность методом ср. прямоугольников');
answer_calculation_error_f1_r_a = calculation_error_absolute(ideal_f1, answer_for_method_rectangle_f1);
disp('Погрешность методом трапеций');
answer_calculation_error_f1_t_a = calculation_error_absolute(ideal_f1, answer_for_method_trap_f1);
disp('Погрешность методом Cимпсона');
answer_calculation_error_f1_s_a = calculation_error_absolute(ideal_f1, answer_for_method_simpson_f1);

disp('--------------------Вычисления_для_N2-------------------');
F2 = @(x) -exp(7-12*x.^2);

ideal_f2 = integral(F2, a, b);


answer_for_method_rectangle_f2 =(method_rectangle(F2, a, b, n));
answer_for_method_trap_f2 = (method_trap(F2, a, b, n));
answer_for_method_simpson_f2 = (method_simpson(F2, a, b, n));

disp('--------------------Погрешности_для_N2-------------------');
disp('--------------------Относительные------------------------');
disp('Погрешность методом ср. прямоугольников');
answer_calculation_error_f2_r = calculation_error(ideal_f2, answer_for_method_rectangle_f2);
disp('Погрешность методом трапеций');
answer_calculation_error_f2_t = calculation_error(ideal_f2, answer_for_method_trap_f2);
disp('Погрешность методом Cимпсона');
answer_calculation_error_f2_s = calculation_error(ideal_f2, answer_for_method_simpson_f2);

disp('--------------------Абсолютные---------------------------');
disp('Погрешность методом ср. прямоугольников');
answer_calculation_error_f2_r_a = calculation_error_absolute(ideal_f2, answer_for_method_rectangle_f2);
disp('Погрешность методом трапеций');
answer_calculation_error_f2_t_a = calculation_error_absolute(ideal_f2, answer_for_method_trap_f2);
disp('Погрешность методом Cимпсона');
answer_calculation_error_f2_s_a = calculation_error_absolute(ideal_f2, answer_for_method_simpson_f2);


function answer_for_method_rectangle = method_rectangle(F, a, b, n)
answer_for_method_rectangle = 0;
h = (b-a) / n;
temp = a + h./2;
for i=temp:h:b
    answer_for_method_rectangle = answer_for_method_rectangle + F(i);
end
answer_for_method_rectangle = answer_for_method_rectangle .* h;
disp('Метод средних прямоугольников');
disp(answer_for_method_rectangle);
end

function answer_for_method_trap = method_trap(F, a, b, n)
answer_for_method_trap = 0;
h = (b-a) / n;
for i=a:h:b
    if i~=b
        answer_for_method_trap = answer_for_method_trap + (F(i)+F(i +h))/2*h;
    end
end
disp('Метод трапеций');
disp(answer_for_method_trap);
end

function answer_for_method_simpson = method_simpson(F, a, b, n)
answer_for_method_simpson = 0;
h = (b-a) / n;
k = 1;
x = a:h:b;
while k <= n+1
    if (k ~= 1) && (k ~= n+1) && (mod(k, 2) == 0)
        answer_for_method_simpson = 4 .* F(x(k)) + answer_for_method_simpson;
    elseif (k ~= 1) && (k ~= n+1) && (mod(k, 2) ~= 0)
        answer_for_method_simpson = 2 .* F(x(k)) + answer_for_method_simpson;
    else
        answer_for_method_simpson = F(x(k)) + answer_for_method_simpson;
    end
    k = k + 1;
end
answer_for_method_simpson = h ./ 3 .* answer_for_method_simpson;
disp('Метод Симпсона');
disp(answer_for_method_simpson);
end

function answer_calculation_error = calculation_error(ideal_, answer_)
answer_calculation_error = (ideal_ - answer_) ./ ideal_ .* 100;
disp(abs(answer_calculation_error));
end

function answer_calculation_error = calculation_error_absolute(ideal_, answer_)
answer_calculation_error = (ideal_ - answer_) ./ ideal_;
disp(abs(answer_calculation_error));
end