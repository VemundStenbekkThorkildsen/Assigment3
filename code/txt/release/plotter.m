clc 
close all
clear all

pos=load('positions.txt');





for i=1:9999
   n=10*i;
   n1=n-1;
   n2=n-2;
   n3=n-3;
   n4=n-4;
   n5=n-5;
   n6=n-6;
   n7=n-7;
   n8=n-8;
   n9=n-9;
   
   pos1(i,:)=pos(n9,:);
   pos2(i,:)=pos(n8,:);
   pos3(i,:)=pos(n7,:);
   pos4(i,:)=pos(n6,:);
   pos5(i,:)=pos(n5,:);
   pos6(i,:)=pos(n4,:);
   pos7(i,:)=pos(n3,:);
   pos8(i,:)=pos(n2,:);
   pos9(i,:)=pos(n1,:);
   pos10(i,:)=pos(n,:);
    
    
    
end





figure (1)
hold on


plot3(pos1(:,1),pos1(:,2),pos1(:,3));
plot3(pos2(:,1),pos2(:,2),pos2(:,3));
plot3(pos3(:,1),pos3(:,2),pos3(:,3));
plot3(pos4(:,1),pos4(:,2),pos4(:,3));
plot3(pos5(:,1),pos5(:,2),pos5(:,3));
plot3(pos6(:,1),pos6(:,2),pos6(:,3));
plot3(pos7(:,1),pos7(:,2),pos7(:,3));
plot3(pos8(:,1),pos8(:,2),pos8(:,3));
plot3(pos9(:,1),pos9(:,2),pos9(:,3));
plot3(pos10(:,1),pos10(:,2),pos10(:,3));

title('The solar system in 3 dimensions')
grid on
legend('Sun', 'Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto');
axis equal
xlabel('AU')
ylabel('AU')
zlabel('AU')

figure (2)
hold on
plot(pos1(:,1),pos1(:,2))
plot(pos2(:,1),pos2(:,2))
plot(pos3(:,1),pos3(:,2))
plot(pos4(:,1),pos4(:,2))
plot(pos5(:,1),pos5(:,2))
plot(pos6(:,1),pos6(:,2))
plot(pos7(:,1),pos7(:,2))
plot(pos8(:,1),pos8(:,2))
plot(pos9(:,1),pos9(:,2))
plot(pos10(:,1),pos10(:,2))

title('The solar system in 2 dimensions')
axis equal
grid on
legend('Sun', 'Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto');
xlabel('AU')
ylabel('AU')



%%

Angle=load('perihelion.txt');
RelativisticAngle=load('perihelionRelativistic.txt');

Angle1=Angle(Angle~=0);
RelativisticAngle1=RelativisticAngle(RelativisticAngle~=0);


Years=linspace(0,100,length(Angle1));
figure (3)
plot(Years, Angle1)
figure(4)
plot(Years, RelativisticAngle1)    
        
    
    
    
    




