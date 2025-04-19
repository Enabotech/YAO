# YAO
https://github.com/Enabotech/YAO/assets/8104370/9be1e858-5e8b-4420-9542-9bed2b7c62a3

enabotech@126.com

## 电气
### 电机及驱动
* 东方减速步进电机套件。可根据实际需求自行选择合适的电机及驱动方案。
### 运动控制器
* Galil DMC-2183/DMC-4080。可根据实际需求自行选择合适的控制器方案。
### 主控单元
* 基于Ubuntu + ROS Kinetic的PC系统。
## 机械
* 已完成设计及结构验证。主要参考ABB IRB 14000机械臂自行设计。
## 软件
* 完成基于ROS的MOVEIT+GAZEBO仿真系统搭建。
* 初步完成系统框架程序。欢迎PR。
## 逆运动学解析解
| 关节 | 公式 |
|------|------|
| $\theta_1$   | $$\arctan2(p_{w,y}, p_{w,x})$$ |
| $\theta_2$   | $$\arctan2\left( \sqrt{p_{w,x}^2 + p_{w,y}^2}, p_{w,z} - d_1 \right)$$ |
| $\theta_3$   | $$\arctan2(y_e, x_e) - \arctan2(a_4 \sin\theta_4, a_3 + a_4 \cos\theta_4)$$ |
| $\theta_4$   | $$\pm \arccos\left( \frac{\|p_w - p_s\|^2 - a_3^2 - L_4^2}{2a_3a_4} \right)$$ |
| $\theta_5$   | $$\arctan2(r_{23}, r_{13})$$ |
| $\theta_6$   | $$\arccos(r_{33})$$ |
| $\theta_7$   | $$\arctan2(r_{32}, -r_{31})$$ |
| $p_w$        | $$p - d_7 \cdot R \cdot [0,0,1]^T$$ |
| $p_s$        | $$[a_1\cos\theta_1, a_1\sin\theta_1, d_1]^T$$ |
| $p_e$        | $$p_s + R_2^0 \cdot [0,0,d_3]^T + R_3^0 \cdot [a_3,0,0]^T$$ |
## 图纸
![enabot_yao_prj_spec](https://user-images.githubusercontent.com/8104370/178981737-4663297f-a54c-4832-a1d7-b44af2ec0b84.jpg)
![t](https://user-images.githubusercontent.com/8104370/179392462-123128de-52c5-4b24-8725-53f92fceb417.jpg)
![q](https://user-images.githubusercontent.com/8104370/179392465-e530ebd2-e48a-4e75-97ec-92d616ec06c9.jpg)
![w](https://user-images.githubusercontent.com/8104370/179392467-c791970d-ba12-4fc8-9953-b78b48b07641.jpg)
