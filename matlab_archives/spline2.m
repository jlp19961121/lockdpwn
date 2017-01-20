



% x값의 데이터를 입력합니다
x = [0 100 200 400 600 800 1000];
% fx값의 데이터를 입력합니다
fx = [0 0.82436 1 0.73576 0.40601 0.19915 0.09158];
% xx값을 이용해 (0,1000) 구간을 100등분합니다
xx = linspace(0,1000);
% sp1에 자연끝단조건 3차 스플라인의 값을 입력합니다
sp1 = interp1(x,fx,xx,'spline');
% sp2에 Hermite 3차 스플라인의 값을 입력합니다
sp2 = interp1(x,fx,xx,'pchip');
% sp1은 빨간선, sp2는 녹색점선으로 표시합니다
plot(x,fx,'o',xx,sp1,'r',xx,sp2,'--')

hold on 

% 무명함수를 만들고
fx = @(x) x/200*exp((-x/200)+1);
% 그래프를 그립니다
ezplot(fx,[0,1000]),grid




