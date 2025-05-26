# 🌐 Webserver

**Webserver** es una implementación de un servidor HTTP en **C++98** construido desde cero. Soporta múltiples conexiones concurrentes utilizando `epoll`, responde a solicitudes HTTP/1.1 y permite servir archivos estáticos y ejecutar scripts CGI. El proyecto está enfocado en el desarrollo de infraestructuras de red a bajo nivel, sin dependencias externas, con especial atención a la eficiencia y al manejo correcto del protocolo HTTP.

## 🧱 Objetivos del proyecto

- Implementar un servidor HTTP funcional sin librerías externas.
- Gestionar múltiples clientes concurrentemente con **`epoll`**.
- Procesar correctamente métodos `GET`, `POST`, `DELETE`, `OPTIONS`, etc.
- Interpretar archivos de configuración personalizados al estilo Nginx.
- Manejar errores HTTP y retornar códigos y páginas adecuados.
- Integrar soporte para CGI dinámico.

## 🛠️ Tecnologías utilizadas

- Lenguaje: **C++98**
- Sistema de eventos: `epoll` (Linux)
- Sockets POSIX (`sys/socket.h`)
- Parsing manual de archivos de configuración
- OS Target: Linux

## 🔍 Funcionalidades implementadas

- Manejo eficiente de múltiples conexiones concurrentes con `epoll`.
- Parsing de archivos `config` con múltiples servidores virtuales y ubicaciones.
- Soporte para métodos `GET`, `POST`, `DELETE`, `OPTIONS`, `PUT`.
- Generación de respuestas HTTP con encabezados y códigos adecuados.
- Manejo de errores personalizados (400, 404, 500, etc.).
- Ejecución de scripts CGI con soporte para `POST` y `GET`.
- Servido de archivos estáticos desde un directorio raíz definido por configuración.

## 🧠 Qué aprendí

Este proyecto me permitió profundizar en:

- Programación de redes en bajo nivel con sockets y `epoll`.
- Funcionamiento interno del protocolo HTTP (peticiones, respuestas, headers, status codes).
- Manejo de múltiples conexiones sin bloqueo con eficiencia.
- Parsing de configuraciones tipo Nginx en C++98.
- Modularización de un proyecto de red a escala media.

## ℹ️ Notas

Este proyecto fue desarrollado como parte de una formación intensiva, con restricciones que excluyen el uso de librerías modernas y STL avanzada. Todo el sistema de red, parsing y manejo de solicitudes está construido desde cero en C++98 para reforzar la comprensión profunda de cómo funciona un servidor web real.

---

## 👥 Autores

- [@Fefeco](https://github.com/Fefeco)
- [@samuelhm](https://github.com/samuelhm)
- [@erikgonk](https://github.com/erikgonk)
