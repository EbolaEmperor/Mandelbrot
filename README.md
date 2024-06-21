# Mandelbrot集与Julia集图像生成器

这是一个很好用的工具，您只需提供迭代函数，就可以为您生成指定位置的填充Julia集，和这个函数的广义Mandelbrot集

您的函数应当为$f(z,c)$，其中$c$在迭代过程中是常数，最常见的函数是$f(z,c)=z^2+c$

填充Julia集是指，给定$c$，使得迭代序列$z_n=f(z_{n-1},c)$不发散于$\infty$的初始点$z_0$构成的集合，有理函数的填充Julia集边界为Julia集

广义Mandelbrot集是指，使得迭代序列从$z_0=0$开始的迭代序列$z_n=f(z_{n-1},c)$不发散于$\infty$的迭代常数$c$构成的集合

### 软件包依赖

1. MPI：您可以使用 MPICH、OpenMPI 等常见的 MPI 实现，若您从未使用过 MPI，建议您用 apt 直接安装
```bash
    sudo apt install mpich
```
2. GMP：GNU Multiple Precision
```bash
    sudo apt install libgmp-dev
```

### 精度模式切换

默认使用四精度浮点数 `__float128` 运算，可以实现约 $10^{32}$ 级别的放大，如果要更大的放大倍数，您需要切换到高精度模式。具体操作如下：

1. 打开 `src/GMP_Wrapper.h`
2. 将第 7 行的 `128` 修改为您需要的精度，注意这里的精度是值浮点数的二进制位数，并不是有效数字位数
3. 将第 151 行的 `__float128` 修改为 `GMPFloat`