FROM jenkins/jenkins:latest

COPY plugins.txt /usr/share/jenkins/ref/plugins.txt
COPY my_marvin.yml /var/lib/jenkins/init-configs

USER root

RUN apt-get upgrade
RUN apt-get update
RUN apt-get install -y make gcc

RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt
