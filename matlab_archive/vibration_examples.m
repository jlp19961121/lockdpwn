%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------




%--------------------------------------------------------------------------------------






%--------------------------------------------------------------------------------------
% matlab ==> ������ p425 4.32
%{
    �ٴ��� ��ȸ�����Ǵ� ��������� ������ �׷��� �ڵ�

    x(t) = 0.488*e^-t * cos(19.975t - 1.529) + 0.00133 cos(5t - 0.0266) +
    0.053 sin(5t - 0.026)
%}

for i = 1: 1001
    t(i) = (i - 1) * 10 / 1000;
    x(i) = 0.488* exp(-t(i)) * cos(19.975 *t(i) - 1.529) + 0.00133*cos(5*t(i) - 0.0266) + ...
    0.0533 * sin(5 * t(i) - 0.0266);
end

plot(t, x);
xlabel('t');
ylabel('x(t)');




%--------------------------------------------------------------------------------------
% matlab ==> ������ p322 3.21
%{
    ���ʰ����� �޴� �������� �������������� ������ ���غ� �ڵ� (�ڵ尡 �������� �ʳ�)
    m = 1200 kg
    k =  4 * 10^2 N/m
    zeta = 0.5
    Y = 0.05 m
    w = 29.0887 rad/s
    x0 = 0
    x0_dot = 0.1 m/s
    
    y(t) = Ysin(wt)
%}

tspan = [0 : 0.01 : 2];
x0 = [0 ; 0.1];

[t, x] = ode23('dfunc3_13' , tspan, x0);
disp(' t   x(t)   xd(t)');
disp([t  x]);
plot(t, x(:, 1));
xlabel('t');
gtext('x(t)');
title('Ex 3.13');

function f =dfunc3_20(t, x)
f = zeros(2,1);
f(1) = x(2);
f(2) = 400000 * 0.05 * sin(29.0887*t) / 1200 + ...
    sqrt(400000*1200) * 29.0887 * 0.05 * cos(29.0887*t) / 1200 ...
    - sqrt(40000*1200) * x(2)/1200 - (40000 / 1200) * x(1);







%--------------------------------------------------------------------------------------
% matlab ==> ������ p319 3.19
%{
    �񰨼�� ��ü����
    m = 5 kg
    k = 2000 N/m
    F(t) = 100cos30t N
    x0 = 0.1 m
    x0_dot = 0.1 m/s

%}

F0 = 100;
wn = 20;
m = 5;
w = 30;
x0 = 0.1;
x0_dot = 0.1;
f_0 = F0 / m;

for i = 1:101
    t(i) = 2 * (i-1) / 100;
    x(i) = x0_dot * sin(wn * t(i)) / wn + (x0 - f_0 / (wn^2 -w^2)) * cos(wn*t(i)) + f_0 / (wn^2 - w^2) * cos(w*t(i));
end

plot (t , x);
xlabel('t');
ylabel('x(t)');
title('Ex3.11');



%--------------------------------------------------------------------------------------
% matlab ==> ������ p204 2.20, 
%   x(t) = A_o * sin(w_n*t + phi)    
%   x(t) = 0.0824 sin(5t + 1.325) �� ����, �ӵ�, ���ӵ� �׷����� �׷����� �ڵ�

for i = 1:101
    t(i) = 6 * (i-1) / 100;
    x(i) = 0.0824 * sin(5 * t(i) + 1.3258);
    x1(i) = 0.412 * cos(5 * t(i) + 1.3258);
    x2(i) = -2.061 * sin(5 * t(i) + 1.3258);
end

subplot(311);
plot(t, x);
ylabel('x(t)');
title('Example 2.20');
grid

subplot(312);
plot(t, x1);
ylabel('x^.(t) one dot');
grid

subplot(313);
plot(t, x2);
xlabel('t');
ylabel('x^.^.(t) two dot');
grid