x1=(0:1:32);
x2=(32:1:64);
n1=0;
n2=0;
c1=(1-(4/3)*sin(x1*pi/128).^2).^(n1+n2).*sin(x1*pi/128).^2;
c3=(1-(4/3)*cos(x1*pi/128).^2).^(n1).*(1-(4/3)*sin(x1*pi/128).^2).^(n2).*cos(x1*pi/128).^2;
c2=(1-(4/3)*sin(x2*pi/128).^2).^(n2).*(1-(4/3)*cos(x2*pi/128).^2).^(n1).*cos(x2*pi/128).^2;
c4=(1-(4/3)*sin(x2*pi/128).^2).^(n1+n2).*sin(x2*pi/128).^2;
figure
subplot(3,2,1)
title('\nu_1=0,\nu_2=0')
hold on
plot(x1,c1,"-")
hold on
plot(x1,c3,":")
hold on
plot(x2,c4,".")
hold on
plot(x2,c2,"k-.")
legend('c1','c2','c3','c4')
n1=0;
n2=2;
c1=(1-(4/3)*sin(x1*pi/128).^2).^(n1+n2).*sin(x1*pi/128).^2;
c3=(1-(4/3)*cos(x1*pi/128).^2).^(n1).*(1-(4/3)*sin(x1*pi/128).^2).^(n2).*cos(x1*pi/128).^2;
c2=(1-(4/3)*sin(x2*pi/128).^2).^(n2).*(1-(4/3)*cos(x2*pi/128).^2).^(n1).*cos(x2*pi/128).^2;
c4=(1-(4/3)*sin(x2*pi/128).^2).^(n1+n2).*sin(x2*pi/128).^2;
subplot(3,2,2)
title('\nu_1=0,\nu_2=2')
hold on
plot(x1,c1,"-")
hold on
plot(x1,c3,":")
hold on
plot(x2,c4,".")
hold on
plot(x2,c2,"k-.")
legend('c1','c2','c3','c4')
n1=1;
n2=1;
c1=(1-(4/3)*sin(x1*pi/128).^2).^(n1+n2).*sin(x1*pi/128).^2;
c3=(1-(4/3)*cos(x1*pi/128).^2).^(n1).*(1-(4/3)*sin(x1*pi/128).^2).^(n2).*cos(x1*pi/128).^2;
c2=(1-(4/3)*sin(x2*pi/128).^2).^(n2).*(1-(4/3)*cos(x2*pi/128).^2).^(n1).*cos(x2*pi/128).^2;
c4=(1-(4/3)*sin(x2*pi/128).^2).^(n1+n2).*sin(x2*pi/128).^2;
subplot(3,2,3)
title('\nu_1=1,\nu_2=1')
hold on
plot(x1,c1,"-")
hold on
plot(x1,c3,":")
hold on
plot(x2,c4,".")
hold on
plot(x2,c2,"k-.")
legend('c1','c2','c3','c4')
hold on
n1=2;
n2=0;
c1=(1-(4/3)*sin(x1*pi/128).^2).^(n1+n2).*sin(x1*pi/128).^2;
c3=(1-(4/3)*cos(x1*pi/128).^2).^(n1).*(1-(4/3)*sin(x1*pi/128).^2).^(n2).*cos(x1*pi/128).^2;
c2=(1-(4/3)*sin(x2*pi/128).^2).^(n2).*(1-(4/3)*cos(x2*pi/128).^2).^(n1).*cos(x2*pi/128).^2;
c4=(1-(4/3)*sin(x2*pi/128).^2).^(n1+n2).*sin(x2*pi/128).^2;
subplot(3,2,4)
title('\nu_1=2,\nu_2=0')
hold on
plot(x1,c1,"-")
hold on
plot(x1,c3,":")
hold on
plot(x2,c4,".")
hold on
plot(x2,c2,"k-.")
legend('c1','c2','c3','c4')
hold on
n1=2;
n2=2;
c1=(1-(4/3)*sin(x1*pi/128).^2).^(n1+n2).*sin(x1*pi/128).^2;
c3=(1-(4/3)*cos(x1*pi/128).^2).^(n1).*(1-(4/3)*sin(x1*pi/128).^2).^(n2).*cos(x1*pi/128).^2;
c2=(1-(4/3)*sin(x2*pi/128).^2).^(n2).*(1-(4/3)*cos(x2*pi/128).^2).^(n1).*cos(x2*pi/128).^2;
c4=(1-(4/3)*sin(x2*pi/128).^2).^(n1+n2).*sin(x2*pi/128).^2;
subplot(3,2,5)
title('\nu_1=2,\nu_2=2')
hold on
plot(x1,c1,"-")
hold on
plot(x1,c3,":")
hold on
plot(x2,c4,".")
hold on
plot(x2,c2,"k-.")
legend('c1','c2','c3','c4')
hold on
n1=4;
n2=0;
c1=(1-(4/3)*sin(x1*pi/128).^2).^(n1+n2).*sin(x1*pi/128).^2;
c3=(1-(4/3)*cos(x1*pi/128).^2).^(n1).*(1-(4/3)*sin(x1*pi/128).^2).^(n2).*cos(x1*pi/128).^2;
c2=(1-(4/3)*sin(x2*pi/128).^2).^(n2).*(1-(4/3)*cos(x2*pi/128).^2).^(n1).*cos(x2*pi/128).^2;
c4=(1-(4/3)*sin(x2*pi/128).^2).^(n1+n2).*sin(x2*pi/128).^2;
subplot(3,2,6)
title('\nu_1=4,\nu_2=0')
hold on
plot(x1,c1,"-")
hold on
plot(x1,c3,":")
hold on
plot(x2,c4,".")
hold on
plot(x2,c2,"k-.")
legend('c1','c2','c3','c4')
hold on




