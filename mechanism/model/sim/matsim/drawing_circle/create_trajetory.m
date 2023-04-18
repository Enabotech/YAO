clear,clc,close all;

%% 建立机器人DH参数,初始姿态为竖直。
L1 = Revolute('offset',0,       'd',257.1,  'a',-36,    'alpha',-pi/2);
L2 = Revolute('offset',0,       'd',0,      'a',36,     'alpha',pi/2);
L3 = Revolute('offset',0,       'd',335.3,  'a',48.6,   'alpha',pi/2);
L4 = Revolute('offset',0,       'd',0,      'a',-48.6,   'alpha',-pi/2);
L5 = Revolute('offset',0,       'd',336.8,  'a',32.4,   'alpha',-pi/2);
L6 = Revolute('offset',0,       'd',0,      'a',-32.4,  'alpha',pi/2);
L7 = Revolute('offset',0,       'd',46.8,   'a',0,      'alpha',0);
enabot_v5=SerialLink([L1 L2 L3 L4 L5 L6 L7],'name','ENABOT V5', 'manufacturer','ENABOTECH');
%% 定义圆的圆心、半径以及插补次数
mm=2;
n=[0 0 1]; %法向量n
r=100*mm; %圆的半径
c=[160 160 90]*mm; %圆心的坐标
step=100;   %插补次数
P=circle(n,r,c,step);  %调用画圆函数进行轨迹生成
%% This method can be used for robots with any number of degrees of freedom.
%% ikine:Implements a Levenberg-Marquadt variable step size solver.
%% ikcon:Inverse kinematics by optimization with joint limits
%% ikunc：Inverse manipulator by optimization without joint limits
%% ikinem：Numerical inverse kinematics by minimization。
%% 将笛卡尔空间圆形进行逆解计算得到每个点的关节角度
ikInitGuess=zeros(1,7);
for i=1:length(P)
    T(:,:,i)=transl(P(i,:))*rpy2tr([0,0,pi],'xyz'); %%使关节五始终竖直向下
    config= enabot_v5.ikunc(T(:,:,i),ikInitGuess);   
    ikInitGuess=config;
    qrt(i,:) =config;
end
%% 绘制末端轨迹
W=[-800,+800,-800,+800,-800,+800];
% enabot_v5.plot(qrt,'tilesize',150,'workspace',W,'view','x','trail',{'r','LineWidth',2})  
enabot_v5.plot(qrt,'tilesize',150,'workspace',W,'trail',{'r','LineWidth',2})  
% enabot_v5.teach(qrt,'rpy');                    %显示GUI
%% 保存轨迹
save('qrtData.mat','qrt');
% load('qrtData.mat');