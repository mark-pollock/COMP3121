%f1 = @(n) n^2;
%f2 = @(n) n;
%f2 = @(n) (n - 2*log(n))*(n + cos(n))

%fplot(f1, [0, 10000]); hold on;
%fplot(f2, [0, 10000]);
close all;
x1 = linspace(0, 100000000000000000);
y1 = x1.^2;
y2 = (x1 - 2.*log(x1)).*(x1 + cos(x1));

plot(x1, y1, x1, y2);
figure;
x2 = linspace(0, 10000000000000000000000000000000000000000000);
y3 = 1.*(log(x2)).^2;
y4 = (log(x2)).^2 + 2.*log(x2);
plot(x2, y3, x2, y4);

figure;
x3 = linspace(0, 30);
y5 = x3.^((1+sin(pi.*x3./2))/2);
y6 = sqrt(x3);
plot(x3, y5, x3, y6);

syms n;
r1 = (log(n)).^2;
r2 = log(n.^(log(n)))+2.*log(n);
r3 = (log(n)).^2 + 2.*log(n);

eval(subs(r1, n, 1000000000000))
eval(subs(r3, n, 1000000000000))


