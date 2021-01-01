1、puma560齐次变换矩阵
sym('th',[1 6]);
syms a2 a3 d2 d4 d6;
syms T1(th1) T2(th2, d2) T3(th3, a2) T4(th4,a3,d4) T5(th5) T6(th6,d6);
T1(th1) = [[cos(th1) -sin(th1) 0 0];[sin(th1) cos(th1) 0 0];[0 0 1 0];[0 0 0 1]];
T2(th2,d2) = [[cos(th2) -sin(th2) 0 0];[0 0 1 d2];[-sin(th2) -cos(th2) 0 0];[0 0 0 1]];
T3(th3,a2) = [[cos(th3) -sin(th3) 0 a2];[sin(th3) cos(th3) 0 0];[0 0 1 0];[0 0 0 1]];
T4(th4,a3,d4) = [[cos(th4) -sin(th4) 0 a3];[0 0 1 d4];[-sin(th4) -cos(th4) 0 0];[0 0 0 1]];
T5(th5) = [[cos(th5) -sin(th5) 0 0];[0 0 -1 0];[sin(th5) cos(th5) 0 0];[0 0 0 1]];
T6(th6,d6) = [[cos(th6) -sin(th6) 0 0];[0 0 1 d6];[-sin(th6) -cos(th6) 0 0];[0 0 0 1]];
T(th1,th2,th3,th4,th5,th6,a2,a3,d2,d4,d6) = T1(th1)*T2(th2,d2)*T3(th3,a2)*T4(th4,a3,d4)*T5(th5)*T6(th6,d6);


T(pi/2,0,-pi/2,0,0,0,a2, a3, d2, d4, 0);
 
ans =
 
[ 0, 1, 0,     -d2]
[ 0, 0, 1, a2 + d4]
[ 1, 0, 0,      a3]
[ 0, 0, 0,       1]

2、任意轴旋转变换
syms nx ny nz ox oy oz ax ay az fx fy fz th;
syms n(nx,ny,nz) o(ox,oy,oz) a(ax,ay,az) f(fx,fy,fz) Rz(th) Rf(th);
n(nx,ny,nz) = [nx;ny;nz];o(ox,oy,oz) = [ox;oy;oz];a(ax,ay,az) = [ax;ay;az];f(fx,fy,fz) = [fx;fy;fz];
C(nx,ny,nz,ox,oy,oz,ax,ay,az) = [[n(nx,ny,nz);0] [o(ox,oy,oz);0] [a(ax,ay,az);0] [0;0;0;1]];
Ct(nx,ny,nz,ox,oy,oz,ax,ay,az) = [[nx;ox;ax;0] [ny;oy;ay;0] [nz;oz;az;0] [0;0;0;1]];
Rz(th) = [[cos(th) -sin(th) 0 0];[sin(th) cos(th) 0 0];[0 0 1 0];[0 0 0 1]];
Rf(nx,ny,nz,ox,oy,oz,ax,ay,az,th) = C(nx,ny,nz,ox,oy,oz,ax,ay,az)*Rz(th)*Ct(nx,ny,nz,ox,oy,oz,ax,ay,az)

3、A
[  fx^2 + nx*(nx*cos(th) + ox*sin(th)) + ox*(ox*cos(th) - nx*sin(th)), fx*fy + ny*(nx*cos(th) + ox*sin(th)) + oy*(ox*cos(th) - nx*sin(th)), fx*fz + nz*(nx*cos(th) + ox*sin(th)) + oz*(ox*cos(th) - nx*sin(th)), 0]
[ fx*fy + nx*(ny*cos(th) + oy*sin(th)) + ox*(oy*cos(th) - ny*sin(th)),  fy^2 + ny*(ny*cos(th) + oy*sin(th)) + oy*(oy*cos(th) - ny*sin(th)), fy*fz + nz*(ny*cos(th) + oy*sin(th)) + oz*(oy*cos(th) - ny*sin(th)), 0]
[ fx*fz + nx*(nz*cos(th) + oz*sin(th)) + ox*(oz*cos(th) - nz*sin(th)), fy*fz + ny*(nz*cos(th) + oz*sin(th)) + oy*(oz*cos(th) - nz*sin(th)),  fz^2 + nz*(nz*cos(th) + oz*sin(th)) + oz*(oz*cos(th) - nz*sin(th)), 0]
[                                                                   0,                                                                   0,                                                                   0, 1]
