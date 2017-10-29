tetta=load('theta.txt');
notrela=load('thetanotrela.txt');


years = linspace(1,100,length(tetta));

figure (1)
hold on
plot(years,notrela);
plot(years,tetta);
legend('Newtonian force', 'Relativistic force');
title('Perihelion angle')
grid on
xlabel('Years')
ylabel('Arcseconds')
