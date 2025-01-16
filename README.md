<table align="center">
  <tr>
    <th><img src="https://github.com/LucasOpoka/fractol/blob/main/assets/Mandelbrot.png" width="100" height="100"></th>
    <th><img src="https://github.com/LucasOpoka/fractol/blob/main/assets/Mandelbrot3.png" width="100" height="100"></th>
    <th><img src="https://github.com/LucasOpoka/fractol/blob/main/assets/Julia-0.2321-0.835.png" width="100" height="100"></th>
    <th><img src="https://github.com/LucasOpoka/fractol/blob/main/assets/CubicJulia.png" width="100" height="100"></th>
    <th><img src="https://github.com/LucasOpoka/fractol/blob/main/assets/Newton.png" width="100" height="100"></th>
    <th><img src="https://github.com/LucasOpoka/fractol/blob/main/assets/Bow.png" width="100" height="100"></th>
  </tr>
  <tr>
    <td align="center">Mandelbrot</td>
    <td align="center">Mandelbrot3</td>
    <td align="center">Julia</td>
    <td align="center">CubicJulia</td>
    <td align="center">Newton</td>
    <td align="center">Bow</td>
  </tr>
</table>

<br />

# Quickstart guide for Linux (Debian Like)

## Install dependencies
```bash
sudo apt update
sudo apt install git cmake make build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

## Clone MLX42 repository
```bash
git clone https://github.com/codam-coding-college/MLX42.git
```

## Build MLX42
```bash
cd MLX42
cmake -B build
cmake --build build -j4
cd ..
```

## Clone fractol repository
```bash
git clone https://github.com/LucasOpoka/fractol.git
```

## Build fractol
```bash
cd fractol
make
```

## Test run
```bash
./fractol Mandelbrot
```
