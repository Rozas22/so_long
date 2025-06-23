#include "MLX42/MLX42.h"
#include <stdio.h>

int main(void)
{
    mlx_t* mlx = mlx_init(800, 600, "Ventana de prueba", true);
    if (!mlx)
    {
        printf("Error al iniciar MLX42\n");
        return (1);
    }

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}
