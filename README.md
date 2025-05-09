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
## 逆运动学
| 参数 | 解析解 |
|------|------|
| $\theta_1$   | $$\arctan2(p_y, p_x) - \arcsin\left(\frac{a_1}{\sqrt{p_x^2 + p_y^2}}\right)$$ |
| $\theta_2$   | $$\arctan2\left( p_z - d_1, \sqrt{p_x^2 + p_y^2} - a_1 \right) - \arctan2(a_3\sinθ_3, a_2 + a_3\cosθ_3)$$ |
| $\theta_3$   | $$\pm \arccos\left( \frac{L^2 - a_2^2 - a_3^2}{2a_2a_3} \right)\quad(\text{±号对应肘部"up/down"两种构型})$$ |
| $\theta_4$   | $$\phi - (\theta_2 + \theta_3)$$ |
| $\theta_5$   | $$\arctan2(r_{32}, r_{31})$$ |
| $\theta_6$   | $$\arctan2(\sqrt{r_{11}^2 + r_{21}^2}, r_{33})\quad(\text{为零时退化为万向节锁})$$ |
| $\theta_7$   | $$\arctan2(r_{23}, -r_{13})$$ |
| $\mathbf{p}_{end}$ | $$[p_x, p_y, p_z]^T$$ |
| $L$          | $$\sqrt{(p_z - d_1)^2 + (\sqrt{p_x^2 + p_y^2} - a_1)^2}$$ |
| $\phi$       | $$\arg\min \sum_{i=1}^7 (θ_i - θ_{i,home})^2 \quad (\text{最小能量准则})$$ |
## 图纸
![enabot_yao_prj_spec](https://user-images.githubusercontent.com/8104370/178981737-4663297f-a54c-4832-a1d7-b44af2ec0b84.jpg)
![t](https://user-images.githubusercontent.com/8104370/179392462-123128de-52c5-4b24-8725-53f92fceb417.jpg)
![q](https://user-images.githubusercontent.com/8104370/179392465-e530ebd2-e48a-4e75-97ec-92d616ec06c9.jpg)
![w](https://user-images.githubusercontent.com/8104370/179392467-c791970d-ba12-4fc8-9953-b78b48b07641.jpg)
