function T=drawing_circle(n,r,c,step)
    %% example1
%     n=[0 0 1]; %法向量n
%     r=150; %圆的半径为1
%     % c=[-200 361.803 145.662]; %圆心的坐标
%     c=[-200 400 145.662]; %圆心的坐标
%     step=2500;   %插补次数
    %% example2
    % n=[1 0 0]; %法向量n   
    % r=150; %圆的半径为150
    % c=[-331 160 250]; %圆心的坐标
    %%
    theta=(0:2*pi/step:2*pi)'; %theta角从0到2*pi
    a=cross(n,[1 0 0]); %n与i叉乘，求取a向量
    if ~any(a) %如果a为零向量，将n与j叉乘
        a=cross(n,[0 1 0]);
    end
    b=cross(n,a); %求取b向量
    a=a/norm(a); %单位化a向量
    b=b/norm(b); %单位化b向量

    c1=c(1)*ones(size(theta,1),1);
    c2=c(2)*ones(size(theta,1),1);
    c3=c(3)*ones(size(theta,1),1);

    x=c1+r*a(1)*cos(theta)+r*b(1)*sin(theta);%圆上各点的x坐标
    y=c2+r*a(2)*cos(theta)+r*b(2)*sin(theta);%圆上各点的y坐标
    z=c3+r*a(3)*cos(theta)+r*b(3)*sin(theta);%圆上各点的z坐标
    points=[x y z];
    T=points;
%     plot3(T(1:end,1),T(1:end,2),T(1:end,3),'r'); grid on;
end