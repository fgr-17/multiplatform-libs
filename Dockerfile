FROM debian:bullseye-slim

RUN apt-get update

RUN apt install -y build-essential
RUN apt install -y cmake
RUN apt install -y doxygen
RUN apt install -y graphviz

RUN apt install -y clang
RUN apt install -y clang-format

RUN apt install -y git
RUN apt install -y clang-tidy
RUN apt install -y iwyu
RUN apt install -y pkg-config
RUN apt install -y libcppunit-dev

# Colored prompt and ls in interactive bash
RUN printf "\n# Interactive shell: colored prompt and ls\n" >> /root/.bashrc && \
    printf "if [ -n \"\$PS1\" ]; then\n  PS1='\\[\\033[01;32m\\]\\u@\\h\\[\\033[00m\\]:\\[\\033[01;34m\\]\\w\\[\\033[00m\\]\\\$ '\nfi\n" >> /root/.bashrc && \
    printf "alias ls='ls --color=auto'\n" >> /root/.bashrc && \
    printf "alias ll='ls -alF'\n" >> /root/.bashrc

WORKDIR /workspace
