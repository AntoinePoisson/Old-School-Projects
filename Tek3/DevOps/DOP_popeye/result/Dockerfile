FROM node:12.0-alpine

WORKDIR /result
COPY . /result

EXPOSE 80

RUN npm install

CMD ["node", "./server.js"]