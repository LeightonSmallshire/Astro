FROM mcr.microsoft.com/devcontainers/cpp:0-ubuntu-22.04


ARG DEBIAN_FRONTEND="noninteractive"

RUN vcpkg install box2d

# install opengl, glew, etc

RUN apt-get update && \
    apt-get install -y libglew-dev libglfw3-dev
