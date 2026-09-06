FROM maven:3.5-jdk-8-alpine AS builder

WORKDIR /worker
COPY . /worker

RUN mvn dependency:resolve

WORKDIR /worker/src
COPY . /worker/src

RUN mvn package


FROM openjdk:8-jre-alpine

WORKDIR /worker/src

COPY --from=builder /worker/src/target/worker-jar-with-dependencies.jar .

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]