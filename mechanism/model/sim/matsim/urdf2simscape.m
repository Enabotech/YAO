clear;clc;
enabot_v5=importrobot('enabot_v5\urdf\enabot_v5.urdf');
showdetails(enabot_v5);
initialpose=homeConfiguration(enabot_v5);
show(enabot_v5,initialpose,'Frames','off','Visuals','on');
axis([-0.6,0.6,-0.6,0.6,0,1]);
enabot_v5_sim=smimport('enabot_v5\urdf\enabot_v5.urdf');
