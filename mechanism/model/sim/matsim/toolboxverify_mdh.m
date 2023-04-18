clear;

% mdh template
% L1 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);
% L2 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);
% L3 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);
% L4 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);
% L5 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);
% L6 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);
% L7 = RevoluteMDH('alpha',0,     'a',0,      'offset',0,     'd',0);

% stdh template
% L1 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);
% L2 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);
% L3 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);
% L4 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);
% L5 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);
% L6 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);
% L7 = Revolute('offset',0,       'd',0,      'a',0,      'alpha',pi/2);

% enabot mdh param
% L1 = RevoluteMDH('alpha',0,     'a',0,      'offset',pi,     'd',257.1);
% L2 = RevoluteMDH('alpha',pi/2,	'a',36,     'offset',pi,	'd',0);
% L3 = RevoluteMDH('alpha',pi/2,	'a',36,     'offset',0,     'd',335.3);
% L4 = RevoluteMDH('alpha',pi/2,	'a',48.6,	'offset',pi,	'd',0);
% L5 = RevoluteMDH('alpha',pi/2,	'a',48.6,	'offset',0,     'd',336.8);
% L6 = RevoluteMDH('alpha',pi/2,	'a',-32.4,	'offset',pi,    'd',0);
% L7 = RevoluteMDH('alpha',pi/2,	'a',-32.4,	'offset',0,	'd',46.8);

% enabot stdh param
L1 = Revolute('offset',0,       'd',257.1,  'a',-36,    'alpha',-pi/2);
L2 = Revolute('offset',0,       'd',0,      'a',36,     'alpha',pi/2);
L3 = Revolute('offset',0,       'd',335.3,  'a',48.6,   'alpha',pi/2);
L4 = Revolute('offset',0,       'd',0,      'a',-48.6,   'alpha',-pi/2);
L5 = Revolute('offset',0,       'd',336.8,  'a',32.4,   'alpha',-pi/2);
L6 = Revolute('offset',0,       'd',0,      'a',-32.4,  'alpha',pi/2);
L7 = Revolute('offset',0,       'd',46.8,   'a',0,      'alpha',0);


% Theta = zeros(1,6);
% enabot_v5 = SerialLink([L1 L2 L3 L4 L5 L6],'name','enabot_v5');
Theta = zeros(1,7);
% Theta = 30*ones(1,7);
enabot_v5 = SerialLink([L1 L2 L3 L4 L5 L6 L7], 'name','enabot_v5');
Theta = Theta/180*pi;
forwarda = enabot_v5.fkine(Theta);                  %正解
W = [-1200,+1200,-1200,+1200,-1200,+1200];          %设置坐标轴范围
enabot_v5.plot(Theta,'tilesize',150,'workspace',W); %显示3D动画
q1 = enabot_v5.ikine(forwarda)*180/pi;              %验证逆解关节角
rpy = tr2rpy(forwarda,'deg');                       %末端姿态
EUL = tr2eul(forwarda,'deg');
[THETA,V] = tr2angvec(forwarda,'deg');
enabot_v5.teach(forwarda,'rpy');                    %显示GUI
