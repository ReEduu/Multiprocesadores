# Proyecto Final

Para el siguiente proyecto se configuró Ubuntu en una maquina virtual de un servicio en la nube, en este caso Azure, esto con el objetivo de ejecutar las actividades en las que está involucrado fopenmp, siendo estas las actividades 1.3, 1.4, 1.5, 2.1 y 2.2, para finalmente comparar los resultados obtenidos con los del equipo personal.  
A continuación se explican los pasos que se siguieron

**Configuración de VM en Azure**

- Entramos a portal.azure.com e iniciamos sesión

  ![Inicio de sesion](./imgs/Inicio_sesion.png)
  
- En mi caso estoy usando una cuenta educativa que me regala 100 dolares para usar

  ![Inicio de sesion_1](./imgs/Inicio_sesion_1.png)
  
- Una vez con la sesión iniciada la pantalla de inicio se ve de la siguiente manera. Seleccionamos maquinas virtuales

  ![Pantalla inicio](./imgs/pantalla_inicio.png)

- Nos dirigirá a la siguiente página 

  ![Pantalla inicio](./imgs/vm_inicio.png)
  
- Seleccionamos crear --> Maquina virtual de Azure

  ![Pantalla Crear](./imgs/vm_crear.png)
  
- Lo que sigue es configurar varios parametros de la maquina virtual, como por ejemplo la región

  ![Conf_1](./imgs/conf_1.png)

- Seleccionamos un sistema operativo basado en Linux en este caso Ubuntu Server

  ![Ubuntu](./imgs/Ubuntu_2.png)
  ![Ubuntu](./imgs/Ubuntu_1.png)

- El siguiente paso será seleccionar la Maquina Virtual a utilizar.
  
  Se eligió una de las más básicas con las siguientes caracteristicas:
  - 1 vCPU
  - 1 GiB de RAM
  ![VM seleccion](./imgs/VM_sel.png)

- En el siguiente pasó se permite la conexión por medio de SSH, por lo que se habilita el puerto 22

  ![SSH](./imgs/ssh.png)
  
- Lo que sigue es elegir un disco duro en este caso es un SSD estandar de 30 GB. Damos click en el botón revisar y crear

  ![SSH](./imgs/discos_1.png)

- Nos pedirá validar los datos, si todo está correcto damos click en Crear

  ![SSH](./imgs/validacion.png)

- Si la maquina virtual se creó de manerá correcta, despues de un tiempo aparecerá la siguiente pantalla

  ![SSH](./imgs/vm_creada.png)
 
**Conexión a la VM**
  
- Seleccionamos conectar --> Bastion. Ya que es una de las formas más sencillas de conectarse

  ![SSH](./imgs/bastion_1.png)
  
- Si no tenemos ninguna instancia de Bastion creada entonces creamos una

  ![SSH](./imgs/bastion.png)
  
- Esperamos a que se cree y nos podrénos conectar a la VM introduciendo usuario y contraseña

  ![SSH](./imgs/bastion_connect.png)
  
- Nos abrirá otra pestaña con la terminal de Ubuntu

  ![SSH](./imgs/consola.png)
  
**Subir los archivos a la VM**

Para subir los archivos se ejecuta el siguiente comando en una terminal de la PC local
```
scp -r C:\Users\ibmor\OneDrive\Documentos\lalo\Codigos ReEdu@20.83.188.43:
```
La sintaxis es muy sencilla
scp -r origen destino

En este caso el origen es una carpeta de la PC local y el destino la VM, la cual se indica con el nombre_de_usuario@dirección_ip_publica. Esto se puede invertir para descargar archivos de la VM, en lugar de subirlos

Si no se conoce la ip publica, esta se encuentra en la página principal de la VM 

![IP](./imgs/ip.png)

Una vez que el comando se ejecuto de forma correcta, los archivos se subirán

![Subida](./imgs/subir_archivos.png)

**Ejecutar actividades**

- Actividad 1.3
- Actividad 1.4
- Actividad 1.5
- Actividad 2.1
- Actividad 2.2
